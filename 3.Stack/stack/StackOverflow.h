#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

#include "stackConfig.h"

struct MyData
{
	size_t currentLen;
	size_t blockCount;
	ptr_t* dataBlocks;
};

struct MyStack
{
#if PROTECTION_LEVEL == 1
	canary_t firstCanary;
#endif
	size_t len;
	size_t size;
	MyData dataStruct;
	ptr_t top;
#if PROTECTION_LEVEL == 1
	canary_t secondCanary;
	size_t hash; 
#endif
};

void newStackDataBlock(MyStack* stack);

#if PROTECTION_LEVEL == 1
void dumpStack(const MyStack* stack);
#endif

void* safeCalloc(size_t count, size_t size);

MyStack createStack(size_t size);

void pushMyStack(MyStack* stack, ptr_t element, size_t sizeOfElement);

ptr_t popMyStack(MyStack* stack);

#if PROTECTION_LEVEL == 1
int isValidMyStack(const MyStack* stack);
#endif

#if PROTECTION_LEVEL == 1
size_t hashFunc(const char* str, size_t len, size_t init);

size_t myHash(const MyStack* stack);
#endif

#endif // !STACKOVERFLOW_H