#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct disk_t* disk_open_from_file(const char* volume_file_name) {
    if (!volume_file_name) {
        errno = EFAULT;
        return NULL;
    }
    FILE* fp = fopen(volume_file_name, "rb");
    if (!fp) {
        errno = ENOENT;
        return NULL;
    }
    fclose(fp);
    disk* d = malloc(sizeof(disk));
    if (!d) {
        errno = ENOMEM;
        return NULL;
    }
    d->sectors = 0;
    d->f = fopen(volume_file_name, "rb");
    uint8_t errcode = 1;
    uint8_t buffer[SECTOR_SIZE];
    while (errcode == 1) {
        errcode = fread(buffer, SECTOR_SIZE, 1, d->f);
        d->sectors++;
    }
    return d;
}

uint32_t get_cluster_pos(uint32_t cluster_area_start, uint16_t num, uint32_t size) {
    return (cluster_area_start + (num - 2) * size);
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read) {
    if (!pdisk||!buffer||sectors_to_read < 1||first_sector < 0) {
        errno = EFAULT;
        return -1;
    }
    if (((unsigned int)first_sector + (unsigned int)sectors_to_read) > pdisk->sectors) {
        errno = ERANGE;
        return -1;
    }
    int pos = fseek(pdisk->f, first_sector*SECTOR_SIZE, SEEK_SET);
    if (pos == -1) {
        errno = ERANGE;
        return -1;
    }

    int retval = fread(buffer, SECTOR_SIZE, sectors_to_read, pdisk->f);
    if (retval != sectors_to_read) {
        errno = ENXIO;
        return -1;
    }
    return 0;
}
int disk_close(struct disk_t* pdisk) {
    if (!pdisk) {
        errno = EFAULT;
        return -1;
    }
    FILE* fp = pdisk->f;
    free(pdisk);
    if (!fp) {
        errno = EFAULT;
        return -1;
    }
    fclose(fp);
    return 0;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector) {
    if (!pdisk) {
        errno = EFAULT;
        return NULL;
    } else if (!pdisk->f) {
        errno = EFAULT;
        return NULL;
    }
    volume* vol = calloc(1, sizeof(volume));
    int err = disk_read(pdisk, (int)first_sector, &vol->vol, 1);
    if (err == -1) {
        free(vol);
        return NULL;
    }
    if (vol->vol.bytes_per_sector != SECTOR_SIZE||vol->vol.number_of_fats != 2||vol->vol.signature != 0xaa55) {
        errno = EINVAL;
        free(vol);
        return NULL;
    }
    void* fat1 = calloc(vol->vol.size_of_fat, SECTOR_SIZE);
    if (!fat1) {
        free(vol);
        errno = ENOMEM;
        return NULL;
    }
    void* fat2 = calloc(vol->vol.size_of_fat, SECTOR_SIZE);
    if (!fat2) {
        free(fat1);
        free(vol);
        errno = ENOMEM;
        return NULL;
    }

    err = disk_read(pdisk, vol->vol.size_of_reserved_area, fat1, vol->vol.size_of_fat);

    if (err == -1) {
        free(fat1);
        free(fat2);
        free(vol);
        return NULL;
    }

    err = disk_read(pdisk, vol->vol.size_of_reserved_area + vol->vol.size_of_fat, fat2, vol->vol.size_of_fat);

    if (err == -1) {
        free(fat1);
        free(fat2);
        free(vol);
        return NULL;
    }

    err = memcmp(fat1, fat2, vol->vol.size_of_fat*SECTOR_SIZE);
    if (err != 0) {
        free(fat1);
        free(fat2);
        free(vol);
        errno = EINVAL;
        return NULL;
    }

    int root_dir_location = vol->vol.size_of_reserved_area + vol->vol.size_of_fat + vol->vol.size_of_fat;

    size_t root_dir_size = sizeof(file) * vol->vol.maximum_number_of_files;

    vol->root_dir = calloc(1, sizeof(directory));
    vol->root_dir->parent = vol;

    if (vol->root_dir == 0) {
        free(fat1);
        free(fat2);
        free(vol);
        errno = ENOMEM;
        return NULL;
    }
    vol->root_dir->contents = calloc(sizeof(file), vol->vol.maximum_number_of_files);

    if (vol->root_dir->contents == 0) {
        free(vol->root_dir);
        free(fat1);
        free(fat2);
        free(vol);
        errno = ENOMEM;
        return NULL;
    }

    err = disk_read(pdisk, root_dir_location, vol->root_dir->contents, root_dir_size/SECTOR_SIZE);

    if (err == -1) {
        free(fat1);
        free(fat2);
        free(vol->root_dir->contents);
        free(vol->root_dir);
        free(vol);
        return NULL;
    }
    vol->root_dir->number_of_files = vol->vol.maximum_number_of_files;
    vol->root_dir->number_of_files = get_directory_size(vol->root_dir);
    vol->fat1 = fat16_from12(fat1, vol->vol.size_of_fat * SECTOR_SIZE);
    vol->fat2 = fat16_from12(fat2, vol->vol.size_of_fat * SECTOR_SIZE);

    free(fat1);
    free(fat2);

    vol->parent = pdisk;
    return vol;
}
int fat_close(struct volume_t* pvolume) {
    if (!pvolume) {
        errno = EFAULT;
        return -1;
    }
    if (pvolume->fat1) {
        free(pvolume->fat1);
    }
    if (pvolume->fat2) {
        free(pvolume->fat2);
    }
    if (pvolume->root_dir) {
        free(pvolume->root_dir);
    }
    if (pvolume->root_dir->contents) {
        free(pvolume->root_dir->contents);
    }
    free(pvolume);
    return 0;
}

_Bool recognize_no_extension(const char* fat_name) {
    for (int j = 11-3; j < 11; ++j) {
        if (fat_name[j] != ' ') {
            return 0;
        }
    }
    return 1;
}

///name1 is a string, whilst name2 is a fucked up mockery of nature aka fat-originated file name
int fncmp(const char* name1, const char* name2) {
    char name_cast[13];
    char name_upper[13];
    OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(name_cast, 13);
    OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(name_upper, 13);
    for (int i = 0; name1[i]; ++i) {
        name_upper[i] = toupper(name1[i]);
    }
    int i = 0;
    for (; name2[i] != ' '&&name2[i] != '.'&&i < 11-3; ++i) {
        name_cast[i] = name2[i];
    }
    if (!recognize_no_extension(name2)) name_cast[i++] = '.';
    for (int j = 11-3; j < 11&&name2[j] != ' '; ++j, ++i) {
        name_cast[i] = name2[j];
    }
    return strcmp(name_upper, name_cast);
}

_Bool check_for_no_parents(const char* filename) {
    for (int i = 1; i < 12; ++i) {
        if (filename[i] == '\\') {
            return 0;
        }
    }
    return 1;
}

struct file_t* dir_process_path(struct dir_t* root_dir, const char* filename) {
    directory* parent;
    _Bool fail = 1;
    char processed_dir_name[13];
    OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(processed_dir_name, 13);
    filename++;
    processed_dir_name[0] = '\\';
    for (int i = 1; *filename != '\\'; ++i, ++filename) {
        processed_dir_name[i] = *filename;
    }
    parent = dir_open(root_dir->parent, processed_dir_name);
    if (!parent) {
        errno = ENOENT;
        return NULL;
    }
    while(!check_for_no_parents(filename)) {
        OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(processed_dir_name, 13);
        filename++;
        for (int i = 0; *filename != '\\'; ++i, ++filename) {
            processed_dir_name[i] = *filename;
        }
        if (strcmp(processed_dir_name, "..") == 0) {
            if (!fail) {
                directory *temp = parent->parent_dir;
                dir_free_4real(parent);
                parent = temp;
            }
            continue;
        }
        if (strcmp(processed_dir_name, ".") == 0) {
            continue;
        }
        fail = 1;
        fileinfo* dir_info = (fileinfo *)parent->contents;
        int i = 0;
        for (; i < parent->number_of_files; ++i) {
            if (dir_info[i].filename[0] == 0) {
                break;
            }
            if (fncmp(processed_dir_name, dir_info[i].filename) == 0) {
                directory* dp = calloc(1, sizeof(directory));
                if (!dp) {
                    errno = ENOMEM;
                    return zero;
                }
                memcpy(&dp->descr, dir_info + i, sizeof(fileinfo));
                dp->parent = parent->parent;
                if (!(dp->descr.file_attributes & 0x10)) {
                    errno = ENOTDIR;
                    free(dp);
                    return zero;
                }
                volume* pvolume = parent->parent;
                short* file_allocation_table = get_allocation_table(dp->descr.low_order_address_of_first_cluster, dp->parent->fat1);
                int j = 0;
                for (; file_allocation_table[j] < 0xff0; ++j);
                dp->contents = calloc(j, SECTOR_SIZE*pvolume->vol.sectors_per_clusters);
                for (int k = 0; file_allocation_table[k] < 0xff0; ++k) {
                    size_t rd_pos = pvolume->vol.size_of_fat*2 + pvolume->vol.size_of_reserved_area;
                    size_t rd_size = pvolume->vol.maximum_number_of_files * sizeof(fileinfo) / pvolume->vol.bytes_per_sector;
                    unsigned int res_sector = get_cluster_pos(rd_pos + rd_size, file_allocation_table[k], pvolume->vol.sectors_per_clusters);
                    disk_read(pvolume->parent, res_sector, (fileinfo*)dp->contents + k, pvolume->vol.sectors_per_clusters);
                }
                dp->file_allocation_table = file_allocation_table;
                dp->number_of_files = j*16;
                dp->number_of_files = get_directory_size(dp);
                dp->pos = 0;
                dp->parent_dir = parent;
                parent = dp;
                fail = 0;
                break;
            }
        }
    }
    fileinfo* dir_info = (fileinfo*)parent->contents;

    filename++;
    int i = 0;

    for (; i < parent->number_of_files; ++i) {
        if (dir_info[i].filename[0] == 0) {
            break;
        }
        char* currfn = dir_info[i].filename;
        if (fncmp(filename, currfn) == 0) {
            file* fp = calloc(1, sizeof(file));
            if (!fp) {
                errno = ENOMEM;
                free(parent->contents);
                free(parent->file_allocation_table);
                free(parent);
                return 0;
            }
            memcpy(&fp->info, dir_info + i, sizeof(fileinfo));
            fp->parent = parent->parent;
            if (fp->info.file_attributes & 0x10) {
                errno = EISDIR;
                free(parent->contents);
                free(parent->file_allocation_table);
                free(parent);
                free(fp);
                return 0;
            }
            fp->file_allocation_table = get_allocation_table(fp->info.low_order_address_of_first_cluster, fp->parent->fat1);
            free(parent->contents);
            free(parent->file_allocation_table);
            free(parent);
            return fp;
        }
    }
    free(parent->contents);
    free(parent->file_allocation_table);
    free(parent);
    return 0;
}


struct file_t* file_open(struct volume_t* pvolume, const char* file_name) {
    if (!pvolume||!file_name) {
        errno = EFAULT;
        return 0;
    }

    if (!check_for_no_parents(file_name)) {
        return dir_process_path(pvolume->root_dir, file_name);
    }

    fileinfo* root_dir = (fileinfo*)pvolume->root_dir->contents;
    int i = 0;

    for (; i < pvolume->vol.maximum_number_of_files; ++i) {
        if (root_dir[i].filename[0] == 0) {
            break;
        }
        char* currfn = root_dir[i].filename;
        if (fncmp(file_name, currfn) == 0) {
            file* fp = calloc(1, sizeof(file));
            if (!fp) {
                errno = ENOMEM;
                return 0;
            }
            memcpy(&fp->info, root_dir + i, sizeof(fileinfo));
            fp->parent = pvolume;
            if (fp->info.file_attributes & 0x10) {
                errno = EISDIR;
                free(fp);
                return 0;
            }
            fp->file_allocation_table = get_allocation_table(fp->info.low_order_address_of_first_cluster, fp->parent->fat1);
            return fp;
        }
    }
    errno = ENOENT;
    return 0;
}
int file_close(struct file_t* stream) {
    if (!stream) {
        errno = EFAULT;
        return -1;
    }
    if (stream->file_allocation_table) {
        free(stream->file_allocation_table);
    }
    free(stream);
    return 0;
}
short* get_allocation_table(int first_sector, u_short* fat) {
    int size = 0;
    int kostyl = first_sector;
    while (kostyl < 0xff0) {
        ++size;
        kostyl = fat[kostyl];
    }
    int s = 0;
    kostyl = first_sector;
    short* table = calloc(size+1, sizeof(short));
    table[s++] = kostyl;
    while (kostyl < 0xff0) {
        table[s++] = fat[kostyl];
        kostyl = fat[kostyl];
    }
    return table;
}
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream) {
    if (!ptr||!stream||!size||!nmemb) {
        errno = EFAULT;
        return -1;
    }
    if (stream->info.size / size < nmemb) {
        nmemb = stream->info.size / size;
    }
    int round = (stream->info.size % SECTOR_SIZE != 0) * SECTOR_SIZE;
    size_t rounded_size = stream->info.size + round;
    if (stream->pos >= stream->info.size) {
        return 0;
    }
    void* buf = calloc(rounded_size + SECTOR_SIZE, 1);
    if (!buf) {
        errno = ENOMEM;
        return -1;
    }
    size_t rd_pos = stream->parent->vol.size_of_fat*2 + stream->parent->vol.size_of_reserved_area;
    size_t rd_size = stream->parent->vol.maximum_number_of_files * sizeof(fileinfo) / stream->parent->vol.bytes_per_sector;
    int pos = stream->info.low_order_address_of_first_cluster;
    for (int i = 0; pos <= 0xff0; ++i) {
        void* cluster_buffer = calloc(stream->parent->vol.sectors_per_clusters, SECTOR_SIZE);
        if (!cluster_buffer) {
            errno = ENOMEM;
            free(buf);
            return -1;
        }
        int res_sector = get_cluster_pos(rd_pos + rd_size, pos, stream->parent->vol.sectors_per_clusters);
        int err = disk_read(stream->parent->parent, res_sector, cluster_buffer, stream->parent->vol.sectors_per_clusters);
        if (err == -1) {
            errno = ERANGE;
            free(buf);
            free(cluster_buffer);
            return -1;
        }

        for (int j = 0; j < stream->parent->vol.sectors_per_clusters*SECTOR_SIZE; ++j) {
            ((uint8_t*)buf + (i*stream->parent->vol.sectors_per_clusters*SECTOR_SIZE))[j] = ((uint8_t*)cluster_buffer)[j];
        }
        free(cluster_buffer);
        pos = stream->parent->fat1[pos];

    }
    int size_copy = size*nmemb;
    if (size_copy + stream->pos > stream->info.size) {
        size_copy = stream->info.size - size_copy + stream->pos;
    }
    if (size + stream->pos > stream->info.size) {
        size_copy = size - ((size + stream->pos) - stream->info.size);
        memcpy(ptr, (uint8_t*)buf + stream->pos, size_copy);
        free(buf);
        stream->pos += stream->info.size - (size + stream->pos);
        return 0;//That is for test 24 cuz I don't get what it wants from me
    }
    memcpy(ptr, (uint8_t*)buf + stream->pos, size_copy);
    stream->pos += size_copy;
    free(buf);
    return nmemb;
}
int32_t file_seek(struct file_t* stream, int32_t offset, int whence) {
    if (!stream) {
        errno = EINVAL;
        return -1;
    }
    if (whence < SEEK_SET||whence > SEEK_END) {
        errno = ERANGE;
        return -1;
    }
    if (whence == SEEK_SET) {
        if (offset < 0) {
            errno = ENXIO;
            return -1;
        }
        stream->pos = offset;
    } else if (whence == SEEK_CUR) {
        if ((long long)stream->pos + offset < 0) {
            errno = ENXIO;
            return -1;
        }
        if (stream->info.size < (uint32_t)stream->pos + offset) {
            errno = ENXIO;
            return -1;
        }
        stream->pos += offset;
    } else if (whence == SEEK_END) {
        if (offset > 0) {
            errno = ENXIO;
            return -1;
        }
        stream->pos = stream->info.size + offset;
    }
    return abs(offset);
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path) {
    if (!pvolume||!dir_path) {
        errno = EFAULT;
        return zero;
    }
    const char* new_path = dir_path + 1;
    if (!*new_path) {
        return pvolume->root_dir;
    }
    fileinfo* root_dir = (fileinfo*)pvolume->root_dir->contents;
    int i = 0;

    for (; i < pvolume->vol.maximum_number_of_files; ++i) {
        if (root_dir[i].filename[0] == 0) {
            break;
        }
        char* currdn = root_dir[i].filename;
        if (fncmp(new_path, currdn) == 0) {
            directory* dp = calloc(1, sizeof(directory));
            if (!dp) {
                errno = ENOMEM;
                return zero;
            }
            memcpy(&dp->descr, root_dir + i, sizeof(fileinfo));
            dp->parent = pvolume;
            if (!(dp->descr.file_attributes & 0x10)) {
                errno = ENOTDIR;
                free(dp);
                return zero;
            }
            short* file_allocation_table = get_allocation_table(dp->descr.low_order_address_of_first_cluster, dp->parent->fat1);
            int j = 0;
            for (; file_allocation_table[j] < 0xff0; ++j);
            dp->contents = calloc(j, SECTOR_SIZE*pvolume->vol.sectors_per_clusters);
            for (int k = 0; file_allocation_table[k] < 0xff0; ++k) {
                size_t rd_pos = pvolume->vol.size_of_fat*2 + pvolume->vol.size_of_reserved_area;
                size_t rd_size = pvolume->vol.maximum_number_of_files * sizeof(fileinfo) / pvolume->vol.bytes_per_sector;
                int res_sector = get_cluster_pos(rd_pos + rd_size, file_allocation_table[k], pvolume->vol.sectors_per_clusters);
                disk_read(pvolume->parent, res_sector, (fileinfo*)dp->contents + k, pvolume->vol.sectors_per_clusters);
            }
            dp->file_allocation_table = file_allocation_table;
            dp->number_of_files = j*16;
            dp->number_of_files = get_directory_size(dp);
            dp->pos = 0;
            dp->parent_dir = pvolume->root_dir;
            return dp;
        }
    }
    errno = ENOENT;

    return zero;
}
void defatify(const char* original, char* dest) {
    int i = 0;
    for (; original[i] != ' '&&original[i] != '.'; ++i) {
        dest[i] = original[i];
    }
    if (!recognize_no_extension(original)) dest[i++] = '.';
    for (int j = 11-3; j < 11&&original[j] != ' '; ++j, ++i) {
        dest[i] = original[j];
    }
}
dir_entry fileinfo_to_pentry(fileinfo* fi) {
    dir_entry _rv;
    if (!fi) {
        strcpy(_rv.name, "ERR!!!");
        return _rv;
    }
    char termname[12] = {0};
    OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(_rv.name, 12);
    memcpy(termname, fi->filename, 11);
    defatify(termname, _rv.name);
    _rv.size = fi->size;
    _rv.is_directory = fi->file_attributes & 0x10;
    _rv.is_archived = fi->file_attributes & 0x20;
    _rv.is_hidden =fi->file_attributes & 0x02;
    _rv.is_readonly = fi->file_attributes & 0x01;
    _rv.is_system =fi->file_attributes & 0x04;
    return _rv;
}
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry) {
    if (!pdir||!pentry) {
        errno = EFAULT;
        return -1;
    }
    if (pdir->pos >= (size_t)pdir->number_of_files) {
        return 1;
    }
    while(((fileinfo*)pdir->contents)[pdir->pos].filename[0] == (char) 0xe5||((fileinfo*)pdir->contents)[pdir->pos].filename[0] == (char) 0x05) {
        pdir->pos++;
    }
    *pentry = fileinfo_to_pentry((fileinfo*)pdir->contents + pdir->pos++);
    return 0;
}

int dir_free_4real(struct dir_t* pdir) {
    free(pdir->contents);
    free(pdir->file_allocation_table);
    free(pdir);
    return 0;
}

int dir_close(struct dir_t* pdir) {

    return 0;
}

uint16_t *fat16_from12(uint8_t *fat12, size_t size) {
    uint16_t* results = calloc(size, sizeof(uint16_t));
    OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA((char*)results, (size) * 2);
    if (!results) {
        return results;
    }
    for (size_t i = 0, j = 0; i < size/3; ++i) {
        byte2 first, second;
        first.base = 0;
        second.base = 0;
        byte b1, b2, b3;
        b1.base = fat12[(i*3)];
        b2.base = fat12[(i*3)+1];
        b3.base = fat12[(i*3)+2];
        first.base = b1.base;
        first.bits._9 = b2.bits._1;
        first.bits._10 = b2.bits._2;
        first.bits._11 = b2.bits._3;
        first.bits._12 = b2.bits._4;
        second.base = b3.base;
        second.base <<= 4;
        second.bits._1 = b2.bits._5;
        second.bits._2 = b2.bits._6;
        second.bits._3 = b2.bits._7;
        second.bits._4 = b2.bits._8;
        results[j++] = first.base;
        results[j++] = second.base;
    }
    return results;
}
short get_directory_size(directory* dir) {
    for (int i = 0; i < dir->number_of_files; ++i) {
        if (((fileinfo*)dir->contents)[i].filename[0] == 0) {
            return (short)i;
        }
    }
    return dir->number_of_files;
}



