#include "StackOverflow.h"
#include "unitTest.h"
#include <stdio.h>

int main(void)
{
	stackPushPopTest();
	MyStack stack = createStack(sizeof(char*));
	int arr[1280];
	char s[] = "313123";
	char t[] = "acxzcxz";
	pushMyStack(&stack, s, sizeof(char*));
	pushMyStack(&stack, t, sizeof(char*));
	char* k = popMyStack(&stack);
	k[1] = 'G';
	printf("%s", k);
	return 0;
}