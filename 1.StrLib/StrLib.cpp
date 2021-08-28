#include "StrLib.h"

int customPuts(const char* string)
{
    if (string == nullptr)
        return EOF;
    size_t symbolPos = 0;
    for(size_t symbolPos = 0; string[symbolPos]; ++symbolPos)
    {
        fputc(string[symbolPos], stdout);
    }
    fputc('\n', stdout);
    return 1;
}

char* customStrchr(char* string, char symbol)
{
    

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
    size_t symbolPos = 0;
    
    while (str[symbolPos])
    {
        ++symbolPos;
    }
    
    return symbolPos;
}

int customStrcpy(const char* strToCopy, char* strToPaste)
{
    if (sizeof(*strToCopy > *strToPaste))
        return EOF;
    while (*strToCopy != 0)
    {
        *strToPaste = *strToCopy;
        ++strToCopy;
        ++strToPaste;
    }

    return 1;
}

void customStrncpy(const char* strToCopy, char* strToPaste, int n)
{   
    while (*strToCopy != 0 && *strToPaste != 0 && n)
    {
        *strToPaste = *strToCopy;
        --n;
        ++strToPaste;
        ++strToCopy;
    }
    
    return;
}

void customStrcat(char* destination, char* srcstr)
{
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
}

void customStrncat(char* destination, char* srcstr, int n)
{
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
}

int customFgets(FILE* fp, int MAXLEN, char* string)
{
    if (fp == NULL){
        return EOF;
    }
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
    if (string == NULL)
        return nullptr;
    
    char* copy = (char*)malloc(sizeof(*string)+sizeof(char));

    while (*string)
    {
        *copy = *string;
        ++copy;
        ++string;
    }

    return copy;
}