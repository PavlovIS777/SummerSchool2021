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
	ENABLE_PROTECTION(canary_t firstCanary;)
	size_t len;
	size_t size;
	MyData dataStruct;
	ptr_t top;
	ENABLE_PROTECTION(canary_t secondCanary;)
	ENABLE_PROTECTION(size_t hash;) 
};

void newStackDataBlock(MyStack* stack);

ENABLE_DUMP
(
	void stackIntPrint(const MyStack* stack, size_t blockPos, size_t elemPos);
	void dumpStack(const MyStack* stack, 
				   void printElement(const MyStack* stack, size_t blockPos, size_t elemPos));
)

void* safeCalloc(size_t count, size_t size);

MyStack createStack_(size_t size);

void pushMyStack(MyStack* stack, ptr_t element);

ptr_t popMyStack(MyStack* stack);

ENABLE_VALID_FUNCTION
(
	int isValidMyStack(const MyStack* stack);
)

ENABLE_PROTECTION
(
	size_t hashFunc(const char* str, size_t len, size_t init);
	size_t myHash(const MyStack* stack);
)

void myStackDestructor(MyStack* stack);

void stackIntPrint(const MyStack* stack, size_t blockPos, size_t elemPos);
#endif // !STACKOVERFLOW_H