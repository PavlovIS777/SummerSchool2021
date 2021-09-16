#include "StrLib.h"
#include "unitTests.h"

#pragma warning (disable:4996)

int main()
{
    FILE* input = fopen("input.txt", "r");
    char* dest = (char*)calloc(2, sizeof(char*));
    customStrlenTest();
    return 0;
}