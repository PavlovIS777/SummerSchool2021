#ifndef STRLIB_H
#define STRLIB_H


#include <stdio.h>

int customPuts(const char* str);

char* customStrchr(const char* string, char symbol);

size_t customStrlen(const char* str);

char* customStrcopy(const char* strToCopy, char* strToPaste);
#endif //STRLIB_H