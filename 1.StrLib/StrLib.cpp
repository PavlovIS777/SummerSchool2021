#include "StrLib.h"


int customPuts(const char* string)
{
    if (string == nullptr) {return EOF;}

    size_t symbolPos;
    for(symbolPos = 0; char tmp = string[symbolPos]; ++symbolPos)
    {
        fputc(tmp, stdout);
    }
    fputc('\n', stdout);
    return ++symbolPos;
}


char* customStrchr(char* string, char symbol)
{
    if (string == nullptr) {return nullptr;}

    for(size_t symbolPos = 0; char currentSymbol = string[symbolPos]; ++symbolPos)
    {
        if (currentSymbol == symbol) {
            return string + symbolPos;
        }
    }

    return nullptr;
}


size_t customStrlen(const char* str)
{
    if (str == nullptr) {return EOF;}

    size_t symbolPos = 0;
    
    while (str[symbolPos])
    {
        ++symbolPos;
    }
    
    return symbolPos;
}


int customStrcpy(const char* srcstr, char* destination)
{
    if(destination == nullptr || srcstr == nullptr) {return EOF;}
    int copiesNumber = 0;
    while (*srcstr)
    {
        ++copiesNumber;
        *destination = *srcstr;
        ++destination;
        ++srcstr;
    }
    ++destination;
    *destination = '\0';
    return copiesNumber;
}


int customStrncpy(const char* srcstr, char* destination, int n)
{   
    if (destination == nullptr || srcstr == nullptr || n < 0) {return EOF;}

    if (customStrlen(srcstr) < n) {return customStrcpy(srcstr, destination);}
    int copiesNumber = 0;
    while (*srcstr && n)
    {
        ++copiesNumber;
        *destination = *srcstr;
        --n;
        ++srcstr;
        ++destination;
    }
    ++destination;
    *destination = '\0';
    return copiesNumber;
}


int customStrcat(char* destination, char* srcstr)
{
    if(destination == nullptr || srcstr == nullptr) {return EOF;}
    int copiesNumber = 0;
    while(*destination)
    {
        ++destination;
    }

    do
    {
        ++copiesNumber;
        *destination = *srcstr;
        ++destination;
        ++srcstr;
    } while (*srcstr);
    ++destination;
    *destination = '\0';
    return copiesNumber;
}


int customStrncat(char* destination, char* srcstr, int n)
{
    if (destination == nullptr || srcstr == nullptr || n <= 0) {return EOF;}
    int copiesNumber = 0;
    if (customStrlen(srcstr) < n){
        return customStrcat(destination, srcstr);
    }
    while (*destination)
    {
        ++destination;
    }

    do
    {
        ++copiesNumber;
        --n;
        *destination = *srcstr;
        ++destination;
        ++srcstr;
    } while (*srcstr && n);
    ++destination;
    *destination = '\0';
    return copiesNumber;
}


int customFgets(FILE* fp, int MAXLEN, char* string)
{
    if (fp == NULL || string == nullptr || MAXLEN <= 0) {return EOF;}
    int getsNumber = 0;
    char temp;
    do
    {
        temp = fgetc(fp);
        ++getsNumber;
        *string = temp;
        ++string;
        --MAXLEN;
    } while (temp != '\n' && temp != EOF  && MAXLEN > 1 );
    ++string;
    *string = '\0';
    return getsNumber;
}


char* customStrdup(char* string)
{
    if (string == NULL) {return nullptr;}
    
    int len = customStrlen(string) + 1;

    char* copiedStr = (char*)calloc(len, sizeof(char));
    
    copiedStr = (char*)memcpy((void*)copiedStr, (void*)string, len);

    return copiedStr;
}


int customGetline(char* string, int MAXLEN, char separator)
{
    if (string == nullptr || MAXLEN < 0) {return EOF;}

    char receivedChar = fgetc(stdin);
    while(receivedChar != separator && MAXLEN > 1)
    {
        *string = receivedChar;
        ++string;
        --MAXLEN;
        receivedChar = fgetc(stdin);
    }

    return 1;
}