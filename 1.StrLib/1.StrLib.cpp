#include "StrLib.h"
#pragma warning (disable:4996)
int main()
{
    FILE* in = fopen("input.txt", "r");
    char rt[100] = "123A";
    char* str = (char*)malloc(100 * sizeof(char));
    customGetline(str, 100, '\n');
    printf("%s", str);
    return 0;
}