#include "compareStr.h"
#include <string.h>

int compareStr(const void* s_void, const void* t_void)
{
    char** s = (char**) s_void;
    char** t = (char**) t_void;
    return strcmp(*s, *t);
}