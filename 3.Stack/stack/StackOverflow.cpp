#include "StackOverflow.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>

#define MAX_SIZE 1000

void* safeCalloc(size_t count, size_t size)
{
    void* temp = calloc(count, size);
    if (temp != nullptr)
        return temp;
    else
    {
        printf("Can't allocte memory.");
        assert(temp);
        return nullptr;
    }
}

MyStack* createStack(size_t size)
{
	MyStack* stack = (MyStack*)safeCalloc(1, sizeof(MyStack));
    stack->topBlock = nullptr;
    stack->size = size;
    stack->len = 0;
	return stack;
}

ForwardList* createBlock()
{
    return (ForwardList*)safeCalloc(1, sizeof(ForwardList));
}

void push(MyStack** stack, void* data)
{
    is_valid(*stack);

    size_t size = (*stack)->size;
    ForwardList* newBlock = createBlock();
    void* tmp = safeCalloc(1, size);
    
    memcpy(tmp, data, size);
    newBlock->data = tmp;
    newBlock->next = (*stack)->topBlock;
    (*stack)->topBlock = newBlock;
    (*stack)->len++;
}

void pop(MyStack** stack)
{
    is_valid(*stack);

    if ((*stack)->len == 0) { return; }

    ForwardList* tmp = (*stack)->topBlock;
    (*stack)->topBlock = tmp->next;
    free(tmp);
    (*stack)->len--;
}

size_t stackSize(const MyStack* stack)
{
    is_valid(stack);
    return stack->len;
}

void is_valid(const MyStack* stack)
{
    assert(stack);
    assert(stack->len < MAX_SIZE);
}

size_t capacity(const MyStack* stack)
{
    is_valid(stack);
    return MAX_SIZE;
}
