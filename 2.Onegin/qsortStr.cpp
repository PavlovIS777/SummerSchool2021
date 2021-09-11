#include "qsortStr.h"

void deleteNSymbol(char* s) {
    while (*s != '\n' && *s != '\0') { ++s; }
    *s = '\0';
}

void swapStr(void* lhv, void* rhv)
{
    char** s = (char**)lhv;
    char** tmp = (char**)calloc(1, sizeof(void*));
    char** t = (char**)rhv;

    memcpy(tmp, s, sizeof(char*));
    memcpy(s, t, sizeof(char*));
    memcpy(t, tmp, sizeof(char*));
    free(tmp);
}

void qsortStr(void* inputData, int num, int size, int compareStr(const void* s_void, const void* t_void))
{
    if (num <= 1) {return;}
    
    int left = 0;
    int right = num - 1;
    int mid = (left + right) / 2;

    do
    {
        while ((compareStr((char*)inputData + mid * size, (char*)inputData + left * size) > 0) && (left < num))
        {
            ++left;
        }
        while ((compareStr((char*)inputData + mid * size, (char*)inputData + right * size) < 0) && (right > 0))
        {
            --right;
        }
        
        if (left <= right)
        {
            swapStr((char*)inputData + left * size, (char*)inputData + right * size);
            --right;
            ++left;
        }
        
    } while (left <= right);

    if (right > 0)
        qsortStr(inputData, right + 1, size, compareStr);
    if (left < num)
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