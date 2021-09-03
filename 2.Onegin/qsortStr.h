#ifndef QSORTSTR_H
#define QSORTSTR_H

#include "compareStr.h"

enum LEXSICAL_COMPARE_STATUS
{
    LOWER  = 1,
    BIGGER = 2
};


void qsortStr(char* inputData[], int left, int right);

void swapStr(char* inputData[], int firstInd, int secondInd);



#endif //QSORTSTR_H