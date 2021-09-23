#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "types.h"

#pragma warning(disable:4996)

const int MAXLINES = 8192;
const int MAXLEN   = 1024;

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void));

void swap(ptr_t* lhv, ptr_t* rhv, int size);

void* safeCalloc(size_t count, int size);

void safeMemcpy(void* dest, const void* src, size_t size);

#endif //QSORTSTR_H
