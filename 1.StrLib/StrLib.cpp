#include "StrLib.h"
#include <string.h>

int customPuts(const char* string, FILE* output)
{
    if (string == nullptr || output == nullptr) { return EOF; }

    int strLength = -1;
    for (strLength = 0; char outputSymbol = string[strLength]; ++strLength)
    {
        fputc(outputSymbol, output);
    }
    fputc('\n', output);

    return strLength;
}


char* customStrchr(char* string, int symbol)
{
    if (string == nullptr) { return nullptr; }

    for (size_t symbolPos = 0; char currentSymbol = string[symbolPos]; ++symbolPos)
    {
        if (currentSymbol == symbol) {
            return string + symbolPos;
        }
    }

    return nullptr;
}


int customStrlen(const char* str)
{
    if (str == nullptr) { return EOF; }

    int symbolPos = 0;

    while (str[symbolPos])
    {
        ++symbolPos;
    }

    return symbolPos;
}


int customStrcpy(char* destination, const char* srcstr)
{
    if (destination == nullptr || srcstr == nullptr) { return EOF; }

    int copiesNumber = 0;

    while (*srcstr ? ++copiesNumber : 0)
        *destination++ = *srcstr++;

    *destination = '\0';

    return copiesNumber;
}


int customStrncpy(char* destination, const char* srcstr, int n)
{
    if (destination == nullptr || srcstr == nullptr || n < 0) { return EOF; }

    int copiesNumber = 0;

    while (*srcstr && n-- ? ++copiesNumber : 0)
        *destination++ = *srcstr++;

    *destination = '\0';
    return copiesNumber;
}


int customStrcat(char* destination, const char* srcstr)
{
    if (destination == nullptr || srcstr == nullptr) { return EOF; }
    int copiesNumber = 0;

    int destLem = customStrlen(destination);
    if (destLem == -1) { return EOF; }

    destination += destLem;

    while (*srcstr ? ++copiesNumber : 0)
        *destination++ = *srcstr++;

    *destination = '\0';

    return copiesNumber;
}


int customStrncat(char* destination, const char* srcstr, int n) 
{
    if (destination == nullptr || srcstr == nullptr || n <= 0) { return -1; }

    int copiesNumber = 0;

    destination += customStrlen(destination);

    while (*srcstr && n-- ? ++copiesNumber : 0)
        *destination++ = *srcstr++;

    *destination = '\0';
    return copiesNumber;
}


char* customFgets(char* string, int MAXLEN, FILE* fp)
{
    if (fp == nullptr || string == nullptr || MAXLEN < 2) { return nullptr; }
    
    int getsNumber = 0;
    int receivedChar = -1;
    
    do
    {
        receivedChar = fgetc(fp);
        *string++ = receivedChar;
        ++getsNumber;
        --MAXLEN;
    } while (receivedChar != '\n' && receivedChar != EOF && MAXLEN > 1);

    *string = '\0';

    return string - getsNumber;
}


char* customStrdup(const char* string)
{
    if (string == nullptr) { return nullptr; }

    int len = customStrlen(string);

    if (len == -1)
    {
        return nullptr;
    }
    else ++len;

    char* copiedStr = (char*)calloc(len, sizeof(char));

    copiedStr = (char*)memcpy((void*)copiedStr, (void*)string, len);

    return copiedStr;
}


int customGetline(char** lineptr, int MAXLEN    )
{
    if (MAXLEN <= 1) { return EOF; }

    lineptr = (lineptr == nullptr) ? (char**)calloc(MAXLEN, sizeof(char*)) : lineptr;

    int lineLength = 0;
    int chr = 0;
    char* receivedCharPtr = *lineptr;

    do
    {
        chr = fgetc(stdin);
        *receivedCharPtr++ = chr;
        --MAXLEN;
    } while (chr != '\n' && MAXLEN > 1);

    *receivedCharPtr = '\0';
    return lineLength;
}