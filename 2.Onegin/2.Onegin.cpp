#include "compareStr.h"
#include "qsortStr.h"
#include <stdio.h>
#include <stdlib.h>

void coppyBuff(char*** srcBuff, char*** destBuff, int len)
{
    for (int i = 0; i < len; ++i)
    {
        *destBuff++ = *srcBuff++;
    }
}



int main(void) 
{
    FILE* input = fopen("input.txt", "r");
    char* str = (char*)calloc(MAXLEN, sizeof(char));
    int strCount;

    for (strCount = 0; fgets(str, MAXLEN, input) != nullptr; ++strCount);
    
    rewind(input);
    
    char** buffSorted = (char**)calloc(strCount, sizeof(char**));
    
    for (int k = 0; k < strCount; ++k)
    {
        fgets(str, MAXLEN, input);
        deleteNSymbol(str);
        *buffSorted++ = str;
        str = (char*)calloc(MAXLEN, sizeof(char));
    }
    buffSorted -= strCount;

    char** buffNotSorted = (char**)calloc(strCount, sizeof(char**));
    coppyBuff((char***)buffSorted, (char***)buffNotSorted, strCount);

    qsortStr(buffSorted, strCount, sizeof(char*), compareStr);
    
    printf("Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k)
    {
        printf("%s\n", *buffSorted++);
    }
    printf("\n*****************\n");
    printf("Not sorted array:\n\n");
    for (int k = 0; k < strCount; ++k)
    {
        printf("%s\n", *buffNotSorted++);
    }
    buffNotSorted -= strCount;
    for (int j = 0; j < strCount; ++j)
    {
        free(*buffNotSorted);
        ++buffNotSorted;
    }
    buffNotSorted -= strCount;
    free(buffNotSorted);
}