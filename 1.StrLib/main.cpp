#include "StrLib.h"
//#include <stdio.h>

int main(void)
{
    const char* str = "312";
    char* searchChar = customStrchr(str, '3');
    printf("%c\n", *searchChar);
    customPuts(str);
    printf("%d", customStrlen(str));

    return 1;
}