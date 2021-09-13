#ifndef QSORTSTR_H
#define QSORTSTR_H

#define MAXLINES 8192
#define MAXLEN 1024

#pragma warning(disable:4996)

void deleteNSymbol(char* s);

void qsortStr(void* inputData, int num, int size, int compareStr(const void* s_void, const void* t_void));

void swapStr(void** lhv, void** rhv);

int stdQsort();

#endif //QSORTSTR_H