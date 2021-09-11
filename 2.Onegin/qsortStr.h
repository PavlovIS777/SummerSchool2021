#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "compareStr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000

#pragma warning(disable:4996)

enum LEXSICAL_COMPARE_STATUS
{
    LOWER  = 1,
    BIGGER = 2
};

void deleteNSymbol(char* s);

void qsortStr(void* inputData, int num, int size, int compareStr(const void* s_void, const void* t_void));

void swapStr(char* inputData[], int firstInd, int secondInd);

int stdQsort();

#endif //QSORTSTR_H