#include "comparator.h"
#include "types.h"
#include <string.h>

int compareStr(const void* s_void, const void* t_void)
{
    return strcmp(*(c_string*)s_void, *(c_string*)t_void);
}

int compareInt(const void* x1, const void* x2) 
{
    return (*(int*)x1 - *(int*)x2);
}

int compareStrRev(const void* s_void, const void* t_void)
{
    return -strcmp(*(c_string*)s_void, *(c_string*)t_void);
}

int compareIntRev(const void* x1, const void* x2)
{
    return -(*(int*)x1 - *(int*)x2);
}

int endCompareStr(const void* s_void, const void* t_void)
{
    int sLen = 0;
    int tLen = 0;
    c_string s = *(c_string*)s_void;
    c_string t = *(c_string*)t_void;
    
    while (s[sLen] ? ++sLen : 0);
    while (t[tLen] ? ++tLen : 0);

    while (sLen && tLen)
    {
        --sLen;
        --tLen;

        if (s[sLen] > t[tLen]) { return 1; }
        else if (s[sLen] < t[tLen]) { return -1; }
    }
    
    int result = sLen - tLen;
    while (sLen)
    {
        -sLen;
        if (s[sLen] > t[tLen]) { return 1; }
        else if (s[sLen] < t[tLen]) { return -1; }
    }

    while (tLen)
    {
        --tLen;
        if (s[sLen] > t[tLen]) { return 1; }
        else if (s[sLen] < t[tLen]) { return -1; }
    }

    return result;
}

