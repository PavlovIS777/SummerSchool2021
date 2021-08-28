#include "StrLib.h"

int customPuts(const char* str)
{
    if (str == nullptr)
        return -2;
    size_t symbolPos = 0;
    while (str[symbolPos])
    {
        if (str[symbolPos] == EOF) {
            return EOF;
        }
        fputc(str[symbolPos], stdout);
        ++symbolPos;
    }
    printf("\n");
    return 1;
}

char* customStrchr(const char* string, char symbol)
{
    size_t symbolPos = 0;

    while (string[symbolPos])
    {
        if (string[symbolPos] == symbol) {
            char* output = (char*)(&string[symbolPos]);

            return output;
        }
        ++symbolPos;
    }

    return nullptr;
}

size_t customStrlen(const char* str)
{
    size_t symbolPos = 0;
    
    while (str[symbolPos])
    {
        ++symbolPos;
    }
    
    return symbolPos;
}

char* customStrcopy(const char* strToCopy, char* strToPaste)
{
    size_t symbolPos = 0;
    while (strToCopy[symbolPos])
    {
        strToPaste[symbolPos] = strToCopy[symbolPos];
    }

}

