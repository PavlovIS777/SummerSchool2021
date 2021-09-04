#include "StrLib.h"
#include <string.h>
//#include <stdio.h>

int main(void)
{
    
    char* str = "e123";
    char* sec = customStrdup(str);
    int tmp = customStrlen(sec);
    printf("%s\n", str);
    printf("%d\n", tmp);
    printf("%d", sizeof(str)/sizeof(char));
}