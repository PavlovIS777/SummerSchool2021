#include "StrLib.h"
#include <string.h>
//#include <stdio.h>

int main(void)
{
    char str[] = "312dasdas   3213 13 123 123 123 t";
    char str_test[10] = "";
    //customFgets(fp, sizeof(str2)/sizeof(char), str2);
    //customStrcat(str2, str);
    //customStrncpy(str, str2, 4);
    customGetline(str_test, 10, '\n');
    printf("%s", str_test);

    return 1;
}