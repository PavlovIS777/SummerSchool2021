#include "comparator.h"
#include "types.h"
#include <string.h>
#include <ctype.h>

int compareStr(const void* s_void, const void* t_void)
{
    MyString s = *(MyString*)s_void;
    MyString t = *(MyString*)t_void;
    int sLen = 0;
    int tLen = 0;

    while ((sLen < s.len) && (tLen < t.len))
    {
        if (!iswalpha(s.string[sLen])) { ++sLen; continue; }
        if (!iswalpha(t.string[tLen])) { ++tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        ++sLen;
        ++tLen;
    }

    int result = sLen - tLen;
    while (sLen < s.len)
    {
        if (!iswalpha(s.string[sLen])) { ++sLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        ++sLen;
    }

    while (tLen < t.len)
    {
        if (!iswalpha(t.string[tLen])) { ++tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        ++tLen;
    }

    return result;
}

int compareInt(const void* x1, const void* x2) 
{
    int y1 = *(int*)x1;
    int y2 = *(int*)x2;
    return (y1 - y2);
}

int compareStrRev(const void* s_void, const void* t_void)
{
    MyString s = *(MyString*)s_void;
    MyString t = *(MyString*)t_void;
    int sLen = 0;
    int tLen = 0;

    while ((sLen < s.len) && (tLen < t.len))
    {
        if (!iswalpha(s.string[sLen])) { ++sLen; continue; }
        if (!iswalpha(t.string[tLen])) { ++tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return -1; }
        else if (s.string[sLen] < t.string[tLen]) { return 1; }
        ++sLen;
        ++tLen;
    }

    int result = sLen - tLen;
    while (sLen < s.len)
    {
        if (!iswalpha(s.string[sLen])) { ++sLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return -1; }
        else if (s.string[sLen] < t.string[tLen]) { return 1; }
        ++sLen;
    }

    while (tLen < t.len)
    {
        if (!iswalpha(t.string[tLen])) { ++tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return -1; }
        else if (s.string[sLen] < t.string[tLen]) { return 1; }
        ++tLen;
    }

    return -result;
}

int compareIntRev(const void* x1, const void* x2)
{
    return -(*(int*)x1 - *(int*)x2);
}

int endCompareStr(const void* s_void, const void* t_void)
{
    MyString s = *(MyString*)s_void;
    MyString t = *(MyString*)t_void;
    int sLen = s.len - 1;
    int tLen = t.len - 1;

    while ((sLen + 1) && (tLen + 1))
    {
        if (!iswalpha(s.string[sLen])) { --sLen; continue; }
        if (!iswalpha(t.string[tLen])) { --tLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        --sLen;
        --tLen;
    }
    
    int result = sLen - tLen;
    while (sLen + 1)
    {
        if (!iswalpha(s.string[sLen])) { --sLen; continue; }

        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        --sLen;
    }

    while (tLen + 1)
    {
        if (!iswalpha(t.string[tLen])) { --tLen; continue; }
        
        if (s.string[sLen] > t.string[tLen]) { return 1; }
        else if (s.string[sLen] < t.string[tLen]) { return -1; }
        --tLen;
    }

    return result;
}

int iswalpha(int symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

int cmp(const void* s_void, const void* t_void)
{
    MyString s = *(MyString*)s_void;
    MyString t = *(MyString*)t_void;
    return wcscmp(s.string, t.string);
}
