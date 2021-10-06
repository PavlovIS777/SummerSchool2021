#include "unitTest.h"
#include "stackConfig.h"
#include "StackOverflow.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#if PROTECTION_LEVEL == 1
void stackPushPopTest()
{
	MyStack stack = createStack(sizeof(int));
	int arr[1280];
	for (int i = 0; i < 1280; ++i)
	{
		arr[i] = (i * i - i / 2 + 3) % 10000000;
	}
	for (int i = 0; i < 1024; ++i)
	{
		int tmp = i * i - i / 2 + 3 % 10000000;
		pushMyStack(&stack, (ptr_t)&tmp, sizeof(int));
	}
	for (int i = 768; i < 1024; ++i)
	{
		popMyStack(&stack);
	}
	for (int i = 768; i < 1280; ++i)
	{
		int tmp = i * i % 10000000;
		arr[i] = tmp;
		pushMyStack(&stack, (ptr_t)&tmp, sizeof(int));
	}
	int k = 0;
	for (int j = 0, k = 0; j < stack.dataStruct.blockCount; ++j)
	{
		for (int i = 0; (j + 1 == stack.dataStruct.blockCount && i < stack.dataStruct.currentLen) ||
			(j + 1 < stack.dataStruct.blockCount && i < 256); ++i, ++k)
		{
			if (arr[k] != *(int*)(stack.dataStruct.dataBlocks[j] + i * stack.size))
			{
				printf("pos: %d, arr: %d, stack: %d\n", k, arr[k], *(int*)(stack.dataStruct.dataBlocks[j] + i * stack.size));
			}
		}
	}
}

void stackLeftCanaryTest()
{
	MyStack stack = createStack(sizeof(int));
	ptr_t bug = (ptr_t)&stack - 8;
	for (int i = 0; i < 20; ++i)
	{
		*bug++ = -1;
		if (isValidMyStack(&stack)) { abort(); }
	}

}

void stackRightCanaryTest()
{
	MyStack stack = createStack(sizeof(int));
	ptr_t bug = (ptr_t)&stack.secondCanary + 8;
	for (int i = 0; i < 20; ++i)
	{
		*bug-- = -1;
		if (isValidMyStack(&stack)) { return; }
	}
}

void arrayStackLeftCanaryTest()
{
	MyStack stack = createStack(sizeof(int));
	for (int k = 0; k < 1541; ++k)
	{
		pushMyStack(&stack, (ptr_t)&k, sizeof(int));
	}
	for (int i = 0; i < stack.dataStruct.blockCount; ++i)
	{
		ptr_t tmp = stack.dataStruct.dataBlocks[i] - sizeof(canary_t);
		*tmp++ = -1;
		*tmp++ = -1;
		*tmp++ = -1;
	}
	isValidMyStack(&stack);
	dumpStack(&stack);
}

void arrayStackRightCanaryTest()
{
	MyStack stack = createStack(sizeof(int));
	for (int k = 0; k < 1541; ++k)
	{
		pushMyStack(&stack, (ptr_t)&k, sizeof(int));
	}
	for (int i = 0; i+2 < stack.dataStruct.blockCount; ++i)
	{
		ptr_t tmp = stack.dataStruct.dataBlocks[i] + sizeof(canary_t) + STACK_BLOCK_CAPACITY * stack.size;
		*tmp-- = -1;
		*tmp-- = -1;
		*tmp-- = -1;
	}
	isValidMyStack(&stack);
	dumpStack(&stack);
}

void stackHashTest()
{
	MyStack stack = createStack(sizeof(int));
	for (int k = 0; k < 1541; ++k)
	{
		pushMyStack(&stack, (ptr_t)&k, sizeof(int));
	}
	int arrPos = rand() % 256;
	int arrNum = rand() % (stack.dataStruct.blockCount - 1);
	ptr_t tmp = stack.dataStruct.dataBlocks[arrNum] + arrPos * stack.size;
	*tmp = rand();
	isValidMyStack(&stack);
	dumpStack(&stack);
}
#endif
