#ifndef CLI_H
#define CLI_H

#include "types.h"  
#include <stdio.h>

void consoleSortInterface(FILE* input, int strCount);

void coppyBuff(buff srcBuff, buff destBuff, int len);

int stringsCount(FILE* input);

void buffsOutput(buff buffSorted, buff buffUnsorted, buff buffStdSorted, int strCount);
#endif // !CLI_H


