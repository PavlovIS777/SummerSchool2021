#include "compareStr.h"

int compareStr(const void* s_void, const void* t_void)
{
    char* s = (char*) s_void;
    char* t = (char*) t_void;
    while (*s != '\0' && *t != '\0')
    {
        if (*s < *t) {
            return -1;

        } else if (*s > *t) {
            return 1;
        
        } else {
            ++s;
            ++t;
        }
    }
    if (*s == '\0' && *t != '\0')
        return -1;
    if (*t == '\0' && *s != '\0')
        return 1;

    return 0;
}