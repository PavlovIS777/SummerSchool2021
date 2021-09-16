#ifndef COMPARATOR_H
#define COMPARATOR_H

int compareStr(const void* s_void, const void* t_void);

int compareStrRev(const void* s_void, const void* t_void);

int compareInt(const void* x1, const void* x2);

int compareIntRev(const void* x1, const void* x2);

int endCompareStr(const void* s, const void* t);
#endif //COMPARATOR_H