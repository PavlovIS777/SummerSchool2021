#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "types.h"

#pragma warning(disable:4996)

const int MAXLINES = 8192;
const int MAXLEN   = 1024;

void deleteNSymbol(c_string s);

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void));

void swap(ptr_t* lhv, ptr_t* rhv);

#endif //QSORTSTR_H