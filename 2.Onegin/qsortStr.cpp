#include "qsortStr.h"
#include "comparator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define rightBoard ((ptr_t)inputData + right * size)
#define leftBoard  ((ptr_t)inputData + left * size)
#define reference  ((ptr_t)inputData + ref * size)

void* safeCalloc(size_t count, int size)
{
    void* temp = calloc(count, size);
    if (temp != nullptr)
        return temp;
    else
    {
        printf("Can't allocte memory.");
        assert(temp);
        return nullptr;
    }
}

void safeMemcpy(void* dest, const void* src, size_t size)
{
    size_t count = size / sizeof(size_t);
    ptr_t lhv = (ptr_t)dest;
    ptr_t rhv = (ptr_t)src;

    for (int i = 0; i < count; ++i, size -= sizeof(size_t), lhv += sizeof(size_t), rhv += sizeof(size_t))
    {
        *(size_t*)lhv = *(size_t*)rhv;
    }

    while (size--)
    {
        char t = *lhv;
        *lhv = *rhv;
        ++lhv;
        ++rhv;
    }
}

void swap(ptr_t lhv, ptr_t rhv, int size)
{
    char tmp[128];
    size_t decimal = size / 128;
    size_t frac = size % 128;
    for (int i = 0; i < decimal; i++, ++lhv, ++rhv)
    {
        safeMemcpy(tmp, lhv, 128);
        safeMemcpy(lhv, rhv, 128);
        safeMemcpy(rhv, tmp, 128);
    }
    if (frac)
    {
        safeMemcpy(tmp, lhv, frac);
        safeMemcpy(lhv, rhv, frac);
        safeMemcpy(rhv, tmp, frac);
    }
    
}

void myQsort(void* inputData, int num, int size, int compare(const void* s_void, const void* t_void))
{
    assert(inputData != nullptr);

    if (num <= 1)
        return;
    
    int left = 0;
    int right = num - 1;
    int ref = 0;

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
            swap(leftBoard, rightBoard, size);
            ++left;
            --right;
        }
        
    } while (left <= right);
    
    if (right > 0)
        myQsort(inputData, right + 1, size, compare);
    if (left < num)
        myQsort(leftBoard, num - left, size, compare);
}
