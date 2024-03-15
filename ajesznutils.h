#ifndef UNTITLED_AJESZNUTILS_H
#define UNTITLED_AJESZNUTILS_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

void clearBuffer();
void OIIIIIIIIIIIIIIIIIII_JOSUKE_IVE_ACCIDENTALLY_ERASED_ALL_DATA(char* names, int size);
int fsize(FILE* fp);
void push_char(char* table);
void push_int(int* table, int size, int i);
int max(int a, int b);
int min(int a, int b);
int check(char* filename);
size_t get_malloc_limit();
void ZA_HANDO(char* names, int size, char ch);
int nl(long long num);
typedef union byte_t {
    uint8_t base;
    struct {
        uint8_t _1:1;
        uint8_t _2:1;
        uint8_t _3:1;
        uint8_t _4:1;
        uint8_t _5:1;
        uint8_t _6:1;
        uint8_t _7:1;
        uint8_t _8:1;
    } bits;
}byte;

typedef union byte2_t {
    uint16_t base;
    struct{
        uint8_t _1:1;
        uint8_t _2:1;
        uint8_t _3:1;
        uint8_t _4:1;
        uint8_t _5:1;
        uint8_t _6:1;
        uint8_t _7:1;
        uint8_t _8:1;
        uint8_t _9:1;
        uint8_t _10:1;
        uint8_t _11:1;
        uint8_t _12:1;
        uint8_t _13:1;
        uint8_t _14:1;
        uint8_t _15:1;
        uint8_t _16:1;
    }bits;
}byte2;
#endif
//Hello, old friend :)
