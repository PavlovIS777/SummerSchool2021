#include "CLI.h"
#include <string.h>
#include <stdlib.h>
#include "qsortStr.h"
#include "comparator.h"
#include <assert.h>

void coppyBuff(buff srcBuff, buff destBuff, int len)
{
    memcpy(destBuff, srcBuff, len * sizeof(buff));
}

int stringsCount(FILE* input)
{
    assert(input != nullptr);
    c_string str = (c_string)calloc(MAXLEN, sizeof(char));
    int strCount;

    for (strCount = 0; fgets(str, MAXLEN, input) != nullptr; ++strCount);
    rewind(input);

    return strCount;
}

void buffsOutput(buff buffSorted, buff buffUnsorted, buff buffStdSorted, int strCount)
{
    assert(buffSorted != nullptr); assert(buffUnsorted != nullptr);

    printf("*****************\n");
    printf("Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffSorted[k]); }
    printf("\n*****************\n");
    printf("stdQsort Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffSorted[k]); }
    printf("\n*****************\n");
    printf("Not sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffUnsorted[k]); }
}

void consoleSortInterface(FILE* input, int strCount)
{
    assert(input != nullptr);

    c_string str = (c_string)calloc(MAXLEN, sizeof(char));
    c_string* buffSorted = (c_string*)calloc(strCount, sizeof(char**));
    c_string* buffStdSorted = (c_string*)calloc(strCount, sizeof(char**));
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
    coppyBuff(buffSorted, buffStdSorted, strCount);

    myQsort(buffSorted, strCount, sizeof(c_string), compareStrRev);
    qsort(buffStdSorted, strCount, sizeof(char*), compareStr);
    buffsOutput(buffSorted, buffUnsorted, buffStdSorted, strCount);

    for (int j = 0; j < strCount; ++j)
        free(buffUnsorted[j]);
    free(buffUnsorted);
}