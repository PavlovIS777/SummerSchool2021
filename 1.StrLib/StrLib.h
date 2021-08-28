#ifndef STRLIB_H
#define STRLIB_H


#include <stdio.h>
#include <stdlib.h>

int customPuts(const char* str);

char* customStrchr(const char* string, char symbol);

size_t customStrlen(const char* str);

int customStrcpy(const char* strToCopy, char* strToPaste);

void customStrncpy(const char* strToCopy, char* strToPaste, int n);

void customStrcat(char* destination, char* srcstr);

void customStrncat(char* destination, char* srcstr, int n);

int customFgets(FILE* fp, int MAXLEN, char* string);

char* customStrdup(char* string);
#endif //STRLIB_H