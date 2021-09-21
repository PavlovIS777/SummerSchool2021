#include "qsortStr.h"
#include "comparator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define rightBoard ((ptr_t)inputData + right * size)
#define leftBoard  ((ptr_t)inputData + left * size)
#define reference  ((ptr_t)inputData + mid * size)
void* safeCalloc(size_t count, int size)
{
    void* temp = calloc(count, size);
    if (temp != nullptr)
        return temp;
    else
    {
        printf("Can't allocte memory.");
        assert(temp);
    }
}


void swap(void* lhv, void* rhv, size_t size)
{
    ptr_t tmp = (ptr_t)calloc(size, sizeof(char));
    
    memcpy(tmp, lhv, size);
    memcpy(lhv, rhv, size);
    memcpy(rhv, tmp, size);

    free(tmp);
}

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void))
{
    assert(inputData != nullptr);

    if (num <= 1)
        return;
    
    int left = 0;
    int right = num - 1;
    int mid = num/2;
    
    //if (num == 2)
    //    if (compare(leftBoard, rightBoard) > 0)
    //    {
    //        swap((void*)leftBoard, (void*)rightBoard, size);
    //        return;
    //    }
    //    else { return; }

    do
    {
        while (left < num ? (compare(reference, leftBoard) > 0) : 0)
        {
            ++left;
        }
        while (right > 0 ? (compare(reference, rightBoard) < 0) : 0)
        {
            --right;
        }
        
        if (left <= right)
        {
            swap((void*)leftBoard, (void*)rightBoard, size);
            ++left;
            --right;
        }
        
    } while (left <= right);
    if (right > 0)
        myQsort(inputData, right + 1, size, compare);
    if (left < num)
        myQsort(leftBoard, num - left, size, compare);
}
