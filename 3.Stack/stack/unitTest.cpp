#include "unitTest.h"
#include "StackOverflow.h"

size_t voidCompare(void* firstElement, void* secondElement, size_t size)
{
	char* lhv = (char*)firstElement;
	char* rhv = (char*)secondElement;
	size_t i;
	for (i = 1; i < size && *lhv == *rhv; ++i, ++lhv, ++rhv);
	return i - size;
}

void pushTest(void* element, size_t elementSize)
{
	MyStack* testStack = createStack(elementSize);
	size_t len = testStack->len;
	void* tmp = testStack->topBlock;
	push(&testStack, element);
	if (voidCompare(testStack->topBlock->data, element, elementSize) || testStack->len == len)
	{
		printf("*****************************************************\n"
			"\t\tWrong Stack Push test\n"
			"Top posize_ter:\t\t %p, Len:\t   %zu\n"
			"Top posize_ter after push:  %p, New Len: %zu\n"
			"*****************************************************\n\n", tmp, len, testStack->topBlock, testStack->len);
	}
	else
	{
		printf("**** Test Passed ****\n\n");
	}
	free(testStack->topBlock);
	free(testStack);
}

void popTest(MyStack* testStack)
{
	void* tmp = testStack->topBlock;
	size_t len = testStack->len;
	pop(&testStack);

	if (tmp == testStack->topBlock || testStack->len == len)
	{
		printf("*****************************************************\n"
			"\t\tWrong Stack Pop test\n"
			"Top posize_ter:\t\t%p, Len:\t   %zu\n"
			"Top posize_ter after pop:  %p, New Len: %zu\n"
			"*****************************************************\n\n", testStack->topBlock, len, tmp, testStack->len);
	}
	else
	{
		printf("**** Test Passed ****\n\n");
	}
}