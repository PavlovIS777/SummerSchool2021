#include "CLI.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "qsortStr.h"
#include "comparator.h"

void coppyBuff(buff srcBuff, buff destBuff, int len)
{
    memcpy(destBuff, srcBuff, len * sizeof(buff));
}

void commandLineInterface(void)
{
    FILE* input = fopen("input.txt", "r");
    c_string str = (c_string)calloc(MAXLEN, sizeof(char));
    int strCount;

    for (strCount = 0; fgets(str, MAXLEN, input) != nullptr; ++strCount);
    rewind(input);

    c_string* buffSorted = (c_string*)calloc(strCount, sizeof(char**));
    c_string* buffUnsorted = (c_string*)calloc(strCount, sizeof(char**));

    for (int k = 0; k < strCount; ++k)
    {
        fgets(str, MAXLEN, input);
        deleteNSymbol(str);
        *buffSorted++ = str;
        str = (c_string)calloc(MAXLEN, sizeof(char));
    }

    buffSorted -= strCount;
    coppyBuff(buffSorted, buffUnsorted, strCount);

    myQsort(buffSorted, strCount, sizeof(c_string), compareStrRev);

    printf("Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffSorted[k]); }
    printf("\n*****************\n");
    printf("Not sorted array:\n\n");

    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffUnsorted[k]); }

    for (int j = 0; j < strCount; ++j)
        free(buffUnsorted[j]);
    free(buffUnsorted);
}