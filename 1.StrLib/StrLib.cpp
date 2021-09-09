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


char* customStrchr(char* string, char symbol)
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


int customStrcpy(const char* srcstr, char* destination)
{
    if (destination == nullptr || srcstr == nullptr) { return EOF; }

    int copiesNumber = 0;

        while (char recievedChar = *srcstr)
    {
        ++copiesNumber;
        *destination = recievedChar;
        ++destination;
        ++srcstr;
    }

    *destination = '\0';

    return copiesNumber;
}


int customStrncpy(const char* srcstr, char* destination, int n)
{
    if (destination == nullptr || srcstr == nullptr || n < 0) { return EOF; }

    int copiesNumber = 0;
    int newSymbol = '\0';
    while ((newSymbol = *srcstr) && n)
    {
        ++copiesNumber;
        *destination = newSymbol;
        --n;
        ++srcstr;
        ++destination;
    }

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

    while (char recievedChar = *srcstr)
    {
        ++copiesNumber;
        *destination = recievedChar;
        ++destination;
        ++srcstr;
    }

    *destination = '\0';

    return copiesNumber;
}


int customStrncat(char* destination, const char* srcstr, int n) 
{
    if (destination == nullptr || srcstr == nullptr || n <= 0) { return -1; }

    int copiesNumber = 0;

    destination += customStrlen(destination);
    int newSymbol = '\0';

    while ((newSymbol = *srcstr) && n)
    {
        ++copiesNumber;
        *destination = newSymbol;
        ++destination;
        ++srcstr;
        --n;
    }

    *destination = '\0';
    return copiesNumber;
}


int customFgets(FILE* fp, int MAXLEN, char* string)
{
    if (fp == nullptr || string == nullptr || MAXLEN < 1) { return EOF; }
    int getsNumber = 0;
    int receivedChar = '\0';
    do
    {
        receivedChar = fgetc(fp);
        ++getsNumber;
        *string = receivedChar;
        ++string;
        --MAXLEN;
    } while (receivedChar != '\n' && receivedChar != EOF && MAXLEN > 1);

    *string = '\0';

    return getsNumber;
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


int customGetline(char* string, int MAXLEN, char separator)
{
    if (string == nullptr || MAXLEN <= 0) { return EOF; }

    int lineLength = 0;
    int receivedChar = fgetc(stdin);

    while (receivedChar != separator && MAXLEN > 1)
    {
        ++lineLength;
        *string = receivedChar;
        ++string;
        --MAXLEN;
        receivedChar = fgetc(stdin);
    }

    *string = '\0';
    return lineLength;
}