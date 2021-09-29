#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

struct ForwardList
{
	void* data;
	ForwardList* next;

};

struct MyStack
{
	size_t len;
	size_t size;
	ForwardList* topBlock;
};

void* safeCalloc(size_t count, size_t size);

MyStack* createStack(size_t size);

ForwardList* createBlock();

void push(MyStack** stack, void* data);

void pop(MyStack** stack);

size_t stackSize(const MyStack* stack);

void is_valid(const MyStack* stack);

size_t capacity(const MyStack* stack);
#endif // !STACKOVERFLOW_H