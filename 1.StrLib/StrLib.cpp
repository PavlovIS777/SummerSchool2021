#include "StrLib.h"

int customPuts(const char* str)
{
    if (str == nullptr)
        return EOF; //код ошибки енам.
    size_t symbolPos = 0;
    while (str[symbolPos])
    {
        fputc(str[symbolPos], stdout);
        ++symbolPos;
    }
    fputc('\n', stdout);
    return 1;
}

char* customStrchr(char* string, char symbol)
{
    size_t symbolPos = 0;

    while (string[symbolPos])
    {
        if (string[symbolPos] == symbol) {
            return string + symbolPos;
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

