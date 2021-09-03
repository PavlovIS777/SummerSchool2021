#include "compareStr.h"
#include "qsortStr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* test[] = {"abc", "aaa", "afg"};
    //qsortStr(test, 0, 2);
    qsort(test, 3, sizeof (char*), compareStr);
    for(int i = 0; i < 3; ++i)
        printf("%s ", test[i]);
    return 0;
}