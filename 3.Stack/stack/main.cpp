#include "StackOverflow.h"
#include "unitTest.h"
#include <stdio.h>



int main(void)
{
	MyStack dStack = createStack(int);
	for (int i = 0; i < 1501; ++i)
	{
		double tmp = (i * 55.0) / 13.0;
		pushMyStack(&dStack, (ptr_t)&tmp);
	}
	stackPushPopTest();
	return 0;
}