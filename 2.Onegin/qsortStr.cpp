#include "qsortStr.h"
#include "comparator.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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


void swap(MyString* lhv, MyString* rhv, size_t size)
{
    MyString tmp = *lhv;
    *lhv = *rhv;
    *rhv = tmp;
}

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void))
{
    assert(inputData != nullptr);
    if (num <= 1)
        return;

    int left = 0;
    int right = num - 2;
    int mid = num / 2;

    ptr_t leftBoard = (ptr_t)inputData + left * size;
    ptr_t rightBoard = (ptr_t)inputData + right * size;
    ptr_t reference = (ptr_t)inputData + mid * size;
    
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
            swap((MyString*)leftBoard, (MyString*)rightBoard, size);
            ++left;
            --right;
            rightBoard -= size;
            leftBoard += size;
        }
        
    } while (left <= right);

    if (right > 0)
        myQsort(inputData, right + 1, size, compare);

    if (left < num)
        myQsort(leftBoard, num - left, size, compare);
}
