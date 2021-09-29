#include "StackOverflow.h"
#include "unitTest.h"
#include <stdio.h>

int main(void)
{
    char str[] = "1231";
    MyStack* testStack = createStack(sizeof(char*));
    push(&testStack, str);
    push(&testStack, str);
    pushTest(str, sizeof(char*));
    popTest(testStack);
    return 0;
}