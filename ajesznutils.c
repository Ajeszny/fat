#include "ajesznutils.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

void clearBuffer(){
    if(getchar()!='\n') clearBuffer();
}

void OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(char* names, int size) {
    for (int i = 0; i < size; ++i) {
        *(names+i) = '\0';
    }
}

void ZA_HANDO(char* names, int size, char ch) {
    for (int i = 0; i < size; ++i) {
        *(names+i) = ch;
    }
}//I really spent five minutes thinking how to name this fuction


int fsize(FILE* fp) {
    if (!fp) {
        return 0;
    }
    int size = 0;
    int pos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, pos, SEEK_SET);
    return size;
}

void push_char(char* table) {
    for (int i = 0; *(table+i) != '\0'; ++i) {
        *(table+i) = *(table+i+1);
    }
}

void push_int(int* table, int size, int i) {
    for (int j = i; j < size-1; ++j) {

        *(table+j) = *(table+j+1);
    }

}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int check(char* filename) {
    char* extension = (filename + strlen(filename) - 4);
    if (strcmp(extension, ".txt") == 0) {
        return 1;
    } else if (strcmp(extension, ".bin") == 0) {
        return 2;
    } else {
        return 0;
    }
}

size_t get_malloc_limit() {
    void* dummy = malloc(1);
    if (!dummy) {
        return 0;
    }
    size_t bytes=0;
    do {
        free(dummy);
        dummy = malloc(++bytes);
    } while (dummy);
    return bytes;
}

int nl(long long num) {
    int count = 0;
    if (num < 0) {
        count++;
    }
    num = abs((int)num);
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}




