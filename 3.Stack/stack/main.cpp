#include "StackOverflow.h"
#include <stdio.h>

int main(void)
{
	MyStack stack = createStack(sizeof(int));
	int x = 10;
	size_t s = 100;
	int* p = &x;
	
	pushMyStack(&stack, (ptr_t)p, sizeof(int));
	pushMyStack(&stack, (ptr_t)p, sizeof(int));
	pushMyStack(&stack, (ptr_t)p, sizeof(int));
	size_t* p2 = &s;
	pushMyStack(&stack, (ptr_t)p, sizeof(int));
	popMyStack(&stack);
	pushMyStack(&stack, (ptr_t)p, sizeof(int));

	return 0;
}