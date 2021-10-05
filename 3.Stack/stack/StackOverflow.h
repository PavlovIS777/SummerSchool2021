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
	canary_t firstCanary;
	size_t len;
	size_t size;
	MyData dataStruct;
	ptr_t top;
	canary_t secondCanary;
	size_t hash; 
};

void newStackDataBlock(MyStack* stack);

void dumpStack(const MyStack* stack);

void* safeCalloc(size_t count, size_t size);

MyStack createStack(size_t size);

void pushMyStack(MyStack* stack, ptr_t element, size_t sizeOfElement);

ptr_t popMyStack(MyStack* stack);

int isValidMyStack(const MyStack* stack);

size_t hashFunc(const char* str, size_t len, size_t init);

size_t myHash(const MyStack* stack);
#endif // !STACKOVERFLOW_H