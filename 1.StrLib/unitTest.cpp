#include "StrLib.h"
#include <string.h>
//#include <stdio.h>

int main(void)
{
    char str[] = "312";
    char* str_test = nullptr;
    str_test = customStrdup(str);
    //customFgets(fp, sizeof(str2)/sizeof(char), str2);
    //customStrcat(str2, str);
    //customStrncpy(str, str2, 4);
    printf("%s", str_test);

    return 1;
}