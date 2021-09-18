#ifndef CLI_H
#define CLI_H

#include "types.h"  
#include <stdio.h>

#define MAXONEGINLEN 32768

void consoleSortInterface();

void coppyBuff(myString* srcBuff, myString* destBuff, int len);

void buffsOutput(myString* buffSorted, myString* buffUnsorted, myString* buffStdSorted, size_t strCount);

c_string oneginStr(int* stringsCount);

size_t strParser(c_string string);
#endif // !CLI_H


