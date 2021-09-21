#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "types.h"

#pragma warning(disable:4996)

const int MAXLINES = 8192;
const int MAXLEN   = 1024;

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void));

void swap(void* lhv, void* rhv, size_t size);

void* safeCalloc(size_t count, int size);
#endif //QSORTSTR_H
