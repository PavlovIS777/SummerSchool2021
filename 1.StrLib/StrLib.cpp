#include "StrLib.h"


int customPuts(const char* string)
{
    if (string == nullptr) {return EOF;}

    size_t symbolPos;
    for(symbolPos = 0; string[symbolPos]; ++symbolPos)
    {
        fputc(string[symbolPos], stdout);
    }
    fputc('\n', stdout);
    return ++symbolPos;//вернуть sy
}


char* customStrchr(char* string, char symbol)
{
    if (string == nullptr || symbol < 0 || isnan(symbol)) {return nullptr;}

    for(size_t symbolPos = 0; string[symbolPos]; ++symbolPos)
    {
        if (string[symbolPos] == symbol) {
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


int customStrcpy(const char* destination, char* srcstr)
{
    if(destination == nullptr || srcstr == nullptr) {return EOF;}

    while (*destination)
    {
        *srcstr = *destination;
        ++destination;
        ++srcstr;
    }

    return 1;
}


int customStrncpy(const char* destination, char* srcstr, int n)
{   
    if (destination == nullptr || srcstr == nullptr || isnan(n) || n < 0) {return EOF;}

    while (*destination && *srcstr && n)
    {
        *srcstr = *destination;
        --n;
        ++srcstr;
        ++destination;
    }
    
    return 1;
}


int customStrcat(char* destination, char* srcstr)
{
    if(destination == nullptr || srcstr == nullptr) {return EOF;}

    while(*destination)
    {
        ++destination;
    }

    do
    {
        *destination = *srcstr;
        ++destination;
        ++srcstr;
    } while (*srcstr);
    return 1;
}


int customStrncat(char* destination, char* srcstr, int n)
{
    if (destination == nullptr || srcstr == nullptr || n < 0 || isnan(n)) {return EOF;}

    while (*destination)
    {
        ++destination;
    }

    do
    {
        --n;
        *destination = *srcstr;
        ++destination;
        ++srcstr;
    } while (*srcstr && n);

    return n;
}


int customFgets(FILE* fp, int MAXLEN, char* string)
{
    if (fp == NULL || string == nullptr || MAXLEN < 0 || isnan(MAXLEN)) {return EOF;}
    
    char temp;
    do
    {
        temp = fgetc(fp);
        *string = temp;
        ++string;
        --MAXLEN;
    } while (temp != '\n' && temp != EOF  && MAXLEN > 1 );

    return 1;
}


char* customStrdup(char* string)
{
    if (string == NULL) {return nullptr;}
    
    int len = customStrlen(string) + 1;

    char* copy = (char*)calloc(len, sizeof(char));
    
    copy = (char*)memcpy(copy, string, len);

    return copy;
}


int customGetline(char* string, int MAXLEN, char separator)
{
    if (string == nullptr || MAXLEN < 0 || isnan(MAXLEN)) {return EOF;}

    char tmp = fgetc(stdin);
    while(tmp != separator && MAXLEN > 1)
    {
        *string = tmp;
        ++string;
        --MAXLEN;
        tmp = fgetc(stdin);
    }

    return 1;
}