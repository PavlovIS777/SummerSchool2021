#include "compareStr.h"
#include "qsortStr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINES 1000
#define MAXLEN 1000

#pragma warning(disable:4996)

char* buff[MAXLINES] = {};
int main(void) {
    FILE* input = fopen("input.txt", "r");
    char* str = (char*)calloc(MAXLEN, sizeof(char));
    int i;
    for (i = 0; fgets(str, MAXLEN, input) != nullptr; ++i) {
        deleteNSymbol(str);
        buff[i] = str;
        str = (char*)calloc(MAXLEN, sizeof(char));
    }
    for (int j = 0; j < i; ++j)
        printf("%s", buff[j]);
    printf("\n--------\n");
    //qsortStr(test, 0, 2);
    qsort(buff, i, sizeof(char*), compareStr);
    for (int j = 0; j < i; ++j)
        printf("%s\n", buff[j]);
    return 0;
}