#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

#include "stackConfig.h"

struct MyStack
{
	canary_t firstCanary;
	size_t len;
	size_t size;
	ptr_t data;
	ptr_t top;
	canary_t secondCanary;
	size_t hash; 

};

void dumpStack(const MyStack* stack);

void* safeCalloc(size_t count, size_t size);

MyStack createStack(size_t size);

void pushMyStack(MyStack* stack, ptr_t element, size_t sizeOfElement);

void popMyStack(MyStack* stack);

int isValidMyStack(const MyStack* stack, size_t hash);

size_t hashFunc(const char* str, size_t len, size_t init);

size_t hash(MyStack* stack);

ptr_t peekMyStack(MyStack* stack, size_t elementPos);
#endif // !STACKOVERFLOW_H