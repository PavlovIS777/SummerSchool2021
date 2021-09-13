#include "qsortStr.h"
#include "compareStr.h"
#include <stdlib.h>
#include <stdio.h>

void deleteNSymbol(char* s) {
    while (*s != '\n' && *s != '\0') { ++s; }
    *s = '\0';
}

void swapStr(void** lhv, void** rhv)
{
    void* tmp = *lhv;
    *lhv = *rhv;
    *rhv = tmp;
}

void qsortStr(void* inputData, int num, int size, int compareStr(const void* s_void, const void* t_void))
{
    if (num <= 1) {return;}
    
    int left  = -1;
    int right = num;
    int mid   = (left + right) / 2;
    
    ++left;
    --right;

    char* leftBoard  = (char*)inputData + left * size;
    char* rightBoard = (char*)inputData + right * size;
    char* reference  = (char*)inputData + mid * size;

    do
    {

        while (left < num ? (compareStr(reference, leftBoard) > 0) : 0)
        {
            leftBoard += size;
            ++left;
        }
        while (right > 0 ? compareStr(reference, rightBoard) < 0 : 0)
        {
            rightBoard -= size;
            --right;
        }
        
        if (left <= right)
        {
            swapStr((void**)leftBoard, (void**)rightBoard);
            leftBoard += size;
            rightBoard -= size;
            --right;
            ++left;
        }
        
    } while (left <= right);

    if (right > 0)
        qsortStr(inputData, right + 1, size, compareStr);
    if (left < num - 1)
        qsortStr((char*)inputData + left * size, num - left, size, compareStr);
}

int stdQsort()
{
    char* buff[MAXLINES] = {};
    FILE* input = fopen("input.txt", "r");
    char* str = (char*)calloc(MAXLEN, sizeof(char));
    int i;
    for (i = 0; fgets(str, MAXLEN, input) != nullptr; ++i) {
        deleteNSymbol(str);
        buff[i] = str;
        str = (char*)calloc(MAXLEN, sizeof(char));
    }
    qsort(buff, i, sizeof(char*), compareStr);
    for (int j = 0; j < i; ++j)
        printf("%s\n", buff[j]);
    return 1;
}