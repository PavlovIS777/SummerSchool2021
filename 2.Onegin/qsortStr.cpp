#include "qsortStr.h"
#include "comparator.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(myString* lhv, myString* rhv)
{
    myString tmp = *lhv;
    *lhv = *rhv;
    *rhv = tmp;
}

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void))
{
    assert(inputData != nullptr);

    int left = 0;
    int right = num - 1;
    int mid = num / 2;

    ptr_t leftBoard = (ptr_t)inputData;
    ptr_t rightBoard = (ptr_t)inputData + right * size;
    ptr_t reference = (ptr_t)inputData + mid * size;
    
    if (num <= 1)
        return;
    do
    {
        while (left < num ? (compare(reference, leftBoard) > 0) : 0)
        {
            leftBoard += size;
            ++left;
        }
        while (right > 0 ? (compare(reference, rightBoard) < 0) : 0)
        {
            rightBoard -= size;
            --right;
        }
        
        if (left <= right)
        {
            swap((myString*)leftBoard, (myString*)rightBoard);
            leftBoard += size;
            rightBoard -= size;
            --right;
            ++left;
        }
        
    } while (left <= right);

    if (right > 0)
        myQsort(inputData, num - 1, size, compare);

    if (left < num)
        myQsort((void*)((ptr_t)inputData + left * size), num - left, size, compare);
}