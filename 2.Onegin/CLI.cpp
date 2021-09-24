#include "CLI.h"
#include "qsortStr.h"
#include "comparator.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int normalChar(int symbol)
{
    return symbol > 0 ? symbol : 256 - symbol;
}

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
    for (int k = 0; k < strCount; ++k) { wprintf(L"%ls\n", buffSorted[k].string); }
    printf("\n*****************\n");
    printf("stdQsort Sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { wprintf(L"%ls\n", buffStdSorted[k].string); }
    printf("\n*****************\n");
    printf("Not sorted array:\n\n");
    for (int k = 0; k < strCount; ++k) { wprintf(L"%ls\n", buffUnsorted[k].string); }
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
        size_t len = wcslen(poem);
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
    wchar_t* symbol    = 0;
    size_t countStr = 0;
    
    while (symbol = wcschr(string, '\n'))
    {
        *symbol = '\0';
        string = symbol + 1;
        ++countStr;
    }

    return countStr;
}

c_string oneginStr(int* stringsCount)
{
    setlocale(LC_ALL, "ru_RU.utf8");
    FILE* oneginInput = fopen("oneginRus.bin", "rb");
    if (oneginInput == nullptr)
    {
        printf("Can't open input file");
        assert(oneginInput);
    }

    fseek(oneginInput, 0, SEEK_END);
    size_t bytes = ftell(oneginInput);
    rewind(oneginInput);

    char* oneginStr = (char*)safeCalloc(bytes + 1, sizeof(char));

    fread(oneginStr, sizeof(char), bytes, oneginInput);

    wchar_t* wcharOneginStr = (wchar_t*)safeCalloc(bytes, sizeof(wchar_t));
    mbstowcs(wcharOneginStr, oneginStr, strlen(oneginStr));
    if (stringsCount != nullptr)
        *stringsCount = strParser(wcharOneginStr);

    return wcharOneginStr;
}
