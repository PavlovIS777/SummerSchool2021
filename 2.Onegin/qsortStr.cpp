#include "qsortStr.h"
#include "comparator.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void deleteNSymbol(c_string s)
{
    while (*s != '\n' && *s != '\0') { ++s; }
    *s = '\0';
}

void swap(ptr_t* lhv, ptr_t* rhv)
{
    ptr_t tmp = *lhv;
    *lhv = *rhv;
    *rhv = tmp;
}

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void))
{
    assert(inputData != nullptr);

    if (num <= 1) {return;}
    
    int left  = -1;
    int right = num;
    int mid   = (left + right) / 2;
    
    ++left;
    --right;

    ptr_t leftBoard  = (ptr_t)inputData + left * size;
    ptr_t rightBoard = (ptr_t)inputData + right * size;
    ptr_t reference  = (ptr_t)inputData + mid * size;

    do
    {
        while (left < num ? (compare(reference, leftBoard) > 0) : 0)
        {
            leftBoard += size;
            ++left;
        }
        while (right > 0 ? compare(reference, rightBoard) < 0 : 0)
        {
            rightBoard -= size;
            --right;
        }
        
        if (left <= right)
        {
            swap((ptr_t*)leftBoard, (ptr_t*)rightBoard);
            leftBoard += size;
            rightBoard -= size;
            --right;
            ++left;
        }
        
    } while (left <= right);

    if (right > 0)
        myQsort((ptr_t)inputData, right + 1, size, compare);
    if (left < num )
        myQsort((ptr_t)inputData + left * size, num - left, size, compare);
}