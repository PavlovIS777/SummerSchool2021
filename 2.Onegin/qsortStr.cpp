#include "qsortStr.h"

void swapStr(char* inputData[], int firstInd, int secondInd)
{
    char* tmp = inputData[firstInd];
    inputData[firstInd] = inputData[secondInd];
    inputData[secondInd] = tmp;
}

void qsortStr(char* inputData[], int left, int right)
{
    if (left >= right) {return;}

    int refStr     = (left + right) / 2;
    int leftBoard  = left;
    int rightBoard = right;

    do
    {
        while(compareStr(inputData[refStr], inputData[leftBoard]) == 1)
            ++leftBoard;
        while(compareStr(inputData[refStr], inputData[rightBoard]) == -1)
            --rightBoard;
        
        if (compareStr(inputData[leftBoard], inputData[rightBoard]) == 1)
        {
            swapStr(inputData, leftBoard, rightBoard);
        }
    } while (leftBoard < rightBoard);

    if (leftBoard < right) {qsortStr(inputData, leftBoard - 1, right);}

    if (rightBoard > left) {qsortStr(inputData, left, rightBoard);}
}