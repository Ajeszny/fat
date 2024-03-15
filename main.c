#include <stdio.h>
#include <ctype.h>
#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

void show_sector(uint8_t *sector) {
    for (int i = 0; i < SECTOR_SIZE / BYTES_PER_LINE; ++i) {
        for (int j = 0; j < BYTES_PER_LINE; ++j) {
            printf("%02x ", *(sector + i * BYTES_PER_LINE + j));
        }
        for (int j = 0; j < BYTES_PER_LINE; ++j) {
            uint8_t c = *(sector + i * BYTES_PER_LINE + j);
            if (isprint(c))
                printf("%c", c);
            else
                printf(".");
        }
        printf("\n");
    }
}

int main() {
    disk* d = disk_open_from_file("last_fat12_volume.img");
    volume* vol1 = fat_open(d, 0);

    printf("Hello, World!\n");
    disk_close(d);
    fat_close(vol1);
    return 0;
}



