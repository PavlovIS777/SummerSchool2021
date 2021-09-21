#include "CLI.h"
#include "qsortStr.h"
#include "comparator.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>
#include <wchar.h>


void coppyBuff(MyString* srcBuff, MyString* destBuff, int len)
{
    memcpy(destBuff, srcBuff, len * sizeof(MyString));
}

void buffsOutput(MyString* buffSorted, MyString* buffStdSorted, MyString* buffUnsorted, size_t strCount)
{
    assert(buffSorted != nullptr); 
    assert(buffUnsorted != nullptr);
    assert(buffStdSorted != nullptr);

    printf("*****************\n");
    printf("Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { printf("%s\n", buffSorted[k].string); }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n*****************\n");
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
    assert(poem != nullptr);

    MyString* buffSorted = (MyString*)safeCalloc(strCount, sizeof(MyString));
    MyString* buffStdSorted = (MyString*)safeCalloc(strCount, sizeof(MyString));
    MyString* buffUnsorted = (MyString*)safeCalloc(strCount, sizeof(MyString));
    
    for (size_t i = 0; i < strCount; ++i)
    {
        size_t len = strlen(poem);
        buffSorted[i].string = poem;
        buffSorted[i].len = len;
        poem += len + 1;
    }
    coppyBuff(buffSorted, buffStdSorted, strCount);
    coppyBuff(buffSorted, buffUnsorted, strCount);

    myQsort(buffSorted, strCount, sizeof(MyString), compareStrRev);
    qsort(buffStdSorted, strCount, sizeof(MyString), endCompareStr);

    buffsOutput(buffSorted, buffStdSorted, buffUnsorted, strCount);
}

size_t strParser(c_string string)
{
    char* symbol    = 0;
    size_t countStr = 0;
    
    while (symbol = strchr(string, '\n'))
    {
        *symbol = '\0';
        string = symbol + 1;
        ++countStr;
    }

    return countStr;
}

c_string oneginStr(int* stringsCount)
{
    FILE* oneginInput = fopen("onegin.bin", "rb");
    if (oneginInput == nullptr)
    {
        printf("Can't open input file");
        assert(oneginInput);
    }

    fseek(oneginInput, 0, SEEK_END);
    int bytes = ftell(oneginInput);
    rewind(oneginInput);

    c_string oneginStr = (c_string)safeCalloc(bytes, sizeof(char));

    fread(oneginStr, sizeof(char), bytes, oneginInput);
    
    if (stringsCount != nullptr)
        *stringsCount = strParser(oneginStr);

    return oneginStr;
}
