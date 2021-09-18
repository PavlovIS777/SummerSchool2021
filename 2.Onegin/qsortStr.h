#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "types.h"

#pragma warning(disable:4996)

const int MAXLINES = 8192;
const int MAXLEN   = 1024;

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void));

void swap(myString* lhv, myString* rhv);

#endif //QSORTSTR_H