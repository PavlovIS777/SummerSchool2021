#include "StrLib.h"
//#include <stdio.h>
int main(void)
{
    const char str[] = "3132";
    char* searchChar = strchrCustom(str, '1');
    printf("%c", *searchChar);
    return 1;
}