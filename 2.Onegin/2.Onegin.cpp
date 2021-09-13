#include "compareStr.h"
#include "qsortStr.h"
#include <stdio.h>
#include <stdlib.h>




int main(void) 
{
    char* buff[100] = {};
    FILE* input = fopen("input.txt", "r");
    char* str = (char*)calloc(MAXLEN, sizeof(char));
    int i;

    for (i = 0; fgets(str, MAXLEN, input) != nullptr; ++i) {
        deleteNSymbol(str);
        buff[i] = str;
        str = (char*)calloc(MAXLEN, sizeof(char));
    }

    for (int j = 0; j < i; ++j)
        printf("%s\n", buff[j]);

    printf("\n\n*===================*\n\n");
    
    qsortStr(buff, i, sizeof(char*), compareStr);
    for (int j = 0; j < i; ++j)
        printf("%s\n", buff[j]);

    /*fclose(input);
    printf("\n\n*===================*\n\n");
    stdQsort();*/
}