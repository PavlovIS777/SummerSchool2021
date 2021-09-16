#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "types.h"

constexpr auto MAXLINES = 8192;
constexpr auto MAXLEN   = 1024;

#pragma warning(disable:4996)

void deleteNSymbol(c_string s);

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void));

void swap(ptr_t* lhv, ptr_t* rhv);

int stdQsort();

#endif //QSORTSTR_H