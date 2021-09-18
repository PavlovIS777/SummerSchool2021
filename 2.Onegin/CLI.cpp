#include "CLI.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>
#include <wchar.h>
#include "qsortStr.h"
#include "comparator.h"


void coppyBuff(myString* srcBuff, myString* destBuff, int len)
{
    memcpy(destBuff, srcBuff, len * sizeof(myString));
}

void buffsOutput(myString* buffSorted, myString* buffStdSorted, myString* buffUnsorted, size_t strCount)
{
    assert(buffSorted != nullptr); assert(buffUnsorted != nullptr);

    printf("*****************\n");
    printf("Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffSorted[k].string); }
    printf("\n*****************\n");
    printf("stdQsort Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffStdSorted[k].string); }
    printf("\n*****************\n");
    printf("Not sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffUnsorted[k].string); }
}

void consoleSortInterface()
{
    int strCount = 0;
    c_string poem = oneginStr(&strCount);

    myString* buffSorted = (myString*)calloc(strCount, sizeof(myString));
    myString* buffStdSorted = (myString*)calloc(strCount, sizeof(myString));
    myString* buffUnsorted = (myString*)calloc(strCount, sizeof(myString));

    for (size_t i = 0; i < strCount; ++i)
    {
        size_t len = strlen(poem);
        buffSorted[i].string = poem;
        buffSorted[i].len = len;
        poem += len + 1;
    }

    coppyBuff(buffSorted, buffStdSorted, strCount);
    coppyBuff(buffSorted, buffUnsorted, strCount);


    myQsort(buffSorted, strCount, sizeof(myString), compareStr);
    qsort(buffStdSorted, strCount, sizeof(myString), endCompareStr);

    buffsOutput(buffSorted, buffStdSorted, buffUnsorted, strCount);
}

size_t strParser(c_string string)
{
    char* symbol    = 0;
    size_t countStr = 0;
    
    while (symbol = strchr(string, '\n'))
    {
        *symbol = '\0';
        string += strlen(string) + 1;
        ++countStr;
    }

    return countStr;
}

c_string oneginStr(int* stringsCount)
{
    FILE* oneginInput = fopen("input.txt", "rb");
    FILE* Txt = fopen("output.txt", "wb");
    assert(oneginInput != nullptr);

    fseek(oneginInput, 0, SEEK_END);
    int bytes = ftell(oneginInput);
    rewind(oneginInput);

    c_string oneginStr = (c_string)calloc(bytes, sizeof(char));

    fread(oneginStr, sizeof(char), bytes, oneginInput);
    fwrite(oneginStr, sizeof(char), bytes, Txt);
    
    *stringsCount = strParser(oneginStr);

    return oneginStr;
}