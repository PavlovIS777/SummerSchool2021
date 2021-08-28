#ifndef STRLIB_H
#define STRLIB_H

// комменты
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <math.h>

//outputs string to stdout(console), returns number of printed symbols.
int customPuts(const char* str);

//search symbol in string and returns pointer of this symbol.
char* customStrchr(const char* string, char symbol);

// returns lenght of the string.
size_t customStrlen(const char* str);

//copies srcstr string to the destination string.
int customStrcpy(const char* destination, char* srcstr);

//copies first n symbol of the srcstr string to the destination string.
int customStrncpy(const char* destination, char* srcstr, int n);

//puts srcstr string to the end of destination string.
int customStrcat(char* destination, char* srcstr);

//puts first n symbols of the srcstr string to the end of destination string.
int customStrncat(char* destination, char* srcstr, int n);

//writes stroke line from input file to the string.
int customFgets(FILE* fp, int MAXLEN, char* string);

//returns pointer on the copy of the string.
char* customStrdup(char* string);

//writes line from the stdin(console) to the string.
int customGetline(char* string, int MAXLEN, char separator);

#endif //STRLIB_H