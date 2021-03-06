#ifndef STRLIB_H
#define STRLIB_H

// ????????
//



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//outputs string to stdout(console), returns number of printed symbols.
int customPuts(const char* str, FILE* output);

//search symbol in string and returns pointer of this symbol.
char* customStrchr(char* string, int symbol);

// returns lenght of the string.
int customStrlen(const char* str);

//copies srcstr string to the destination string.
int customStrcpy(char* destination, const char* srcstr);

//copies first n symbol of the srcstr string to the destination string.
int customStrncpy(char* destination, const char* srcstr, int n);

//puts srcstr string to the end of destination string.
int customStrcat(char* destination, const char* srcstr);

//puts first n symbols of the srcstr string to the end of destination string.
int customStrncat(char* destination, const char* srcstr, int n);

//writes stroke line from input file to the string.
char* customFgets(char* string, int MAXLEN, FILE* fp);

//returns pointer on the copy of the string.
char* customStrdup(const char* string);

//writes line from the stdin(console) to the string.
int customGetline(char** lineptr , int MAXLEN, FILE* stream);

#endif //STRLIB_H