#include "StrLib.h"
#include "unitTests.h"

#pragma warning (disable:4996)

int main()
{
    FILE* input = fopen("input.txt", "r");
    char* dest = (char*)calloc(10, sizeof(char*));
    customGetline(&dest, 10);
    printf("%s", dest);
    return 0;
}