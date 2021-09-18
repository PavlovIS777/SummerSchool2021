#include "comparator.h"
#include "types.h"
#include <string.h>
#include <ctype.h>

int compareStr(const void* s_void, const void* t_void)
{
    myString s = *(myString*)s_void;
    myString t = *(myString*)t_void;
    int sLen = 0;
    int tLen = 0;

    while ((sLen < s.len) && (tLen < t.len))
    {
        if (!isLetter(s.string[sLen])) { ++sLen; continue; }
        if (!isLetter(t.string[tLen])) { ++tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        ++sLen;
        ++tLen;
    }

    int result = sLen - tLen;
    while (sLen < s.len)
    {
        if (!isLetter(s.string[sLen])) { ++sLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        ++sLen;
    }

    while (tLen < t.len)
    {
        if (!isLetter(t.string[tLen])) { ++tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        ++tLen;
    }

    return result;
}

int compareInt(const void* x1, const void* x2) 
{
    return (*(int*)x1 - *(int*)x2);
}

int compareStrRev(const void* s_void, const void* t_void)
{
    return -1;
}

int compareIntRev(const void* x1, const void* x2)
{
    return -(*(int*)x1 - *(int*)x2);
}

int endCompareStr(const void* s_void, const void* t_void)
{
    myString s = *(myString*)s_void;
    myString t = *(myString*)t_void;
    int sLen = s.len - 1;
    int tLen = t.len - 1;

    while ((sLen + 1) && (tLen + 1))
    {
        if (!isLetter(s.string[sLen])) { --sLen; continue; }
        if (!isLetter(t.string[tLen])) { --tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        --sLen;
        --tLen;
    }
    
    int result = sLen - tLen;
    while (sLen + 1)
    {
        if (!isLetter(s.string[sLen])) { --sLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        --sLen;
    }

    while (tLen + 1)
    {
        if (!isLetter(t.string[tLen])) { --tLen; continue; }
        
        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        --tLen;
    }

    return result;
}

int isLetter(int symbol)
{
    return ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) ? 1 : 0;
}

int cmp(const void* s_void, const void* t_void)
{
    myString s = *(myString*)s_void;
    myString t = *(myString*)t_void;
    return strcmp(s.string, t.string);
}