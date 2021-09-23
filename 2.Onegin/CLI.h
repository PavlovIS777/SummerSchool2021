#ifndef CLI_H
#define CLI_H

#include "types.h"  
#include <stdio.h>

#define MAXONEGINLEN 32768

void consoleSortInterface();

void coppyBuff(MyString* srcBuff, MyString* destBuff, int len);

void buffsOutput(MyString* buffSorted, MyString* buffUnsorted, MyString* buffStdSorted, size_t strCount);

c_string oneginStr(int* stringsCount);

size_t strParser(c_string string);

int normalChar(int symbol);
#endif // !CLI_H
