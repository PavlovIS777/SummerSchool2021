#include "StackOverflow.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <string.h>

#define STACK_CAPACITY 10
const canary_t CANARY = 0xBADCACA;

size_t hashFunc(const char* str, size_t len, size_t init) {
    unsigned long long int hash = init;
    for (size_t it = 0; it < len; str++, it++) {
        hash += (unsigned char)(*str);
        hash += (hash << 20);
        hash ^= (hash >> 12);
    }

    hash += (hash << 6);
    hash ^= (hash >> 22);
    hash += (hash << 29);

    return hash;
}

size_t hash(MyStack* stack)
{
    ptr_t startStack = (ptr_t) (&stack->firstCanary);
    ptr_t endStack = (ptr_t)&stack->secondCanary + sizeof(canary_t);
    ptr_t startArray = (ptr_t)&stack->data;

    size_t stackHashLen = endStack - startStack;
    size_t hashStack = hashFunc(startStack, stackHashLen, 0);
    size_t hash = hashFunc(startArray, STACK_CAPACITY, hashStack);

    return hash;
}

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

MyStack createStack(size_t size)
{
    size_t securityMem = sizeof(size_t) / size;
    void* stackArray = safeCalloc(STACK_CAPACITY + 3 * securityMem, size);
    canary_t* firstCanary = (canary_t*)stackArray;
    canary_t* secondCanary = (canary_t*)((ptr_t)stackArray + sizeof(canary_t) + STACK_CAPACITY * size);
    *firstCanary =  CANARY;
    *secondCanary = CANARY;
    MyStack stack = { *firstCanary, 0, size,(char*)stackArray + sizeof(canary_t), nullptr,* secondCanary,  0 };
    canary_t canary = CANARY;
    
    canary_t* tmp = (canary_t*)stackArray;
    *tmp = canary;
    
    tmp = (canary_t*)((char*)stackArray + sizeof(canary_t) + STACK_CAPACITY * size);
    *tmp++ = canary;

    stack.hash = hash(&stack);

    return stack;
}

void dumpStack(const MyStack* stack)
{  
    printf("\t  INFO ABOUT STACK\n\n"
           "\tLEFT CANARY:  %d\n"
           "\tHASH:         %zu\n"
           "\tSIZE:         %d\n"
           "\tLENGHT:       %d\n"
           "\tCAPACITY:     %d\n"
           "\tRIGHT CANARY: %d\n\n"
           "\t\tARRAY\n\n"
           "\tLEFT ARRAY CANARY:  %zu\n"
           "\tRIGHT ARRAY CANARY: %zu\n"
           "\tARRAY PTR: %p\n\n", stack->firstCanary, stack->hash, stack->size,
                                  stack->len, STACK_CAPACITY, stack->secondCanary,
                                  *(canary_t*)(stack->data - sizeof(canary_t)),
                                  *(canary_t*)(stack->data + STACK_CAPACITY * stack->size), stack->data);
    size_t len = stack->len;
    printf("\t  STACK BLOCKS:\n\n");
    for (int i = 0; i < len; ++i)
    {
        printf("\t************\n"
               "\tBLOCK: %d\n"
               "\tBLOCK PTR: %p\n"
               "\t************\n\n", i + 1, stack->data + i * stack->size);
    }
}

void pushMyStack(MyStack* stack, ptr_t element, size_t sizeOfElement)
{
    if (isValidMyStack(stack, hash(stack)))
        abort();
    stack->top = stack->data + stack->len * stack->size;
    *(stack->top) = *element;
    stack->len++;
    stack->hash = hash(stack);
}

void popMyStack(MyStack* stack)
{
    if (isValidMyStack(stack, hash(stack)))
        return;
    stack->len--;
    stack->hash = hash(stack);
}

int isValidMyStack(const MyStack* stack, size_t hash)
{
    int ERROR = 0;
    if (stack == nullptr) {
        ERROR = NULL_PTR_ERROR;
        printf("\tNULLPTR STACK\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (stack->size < 0) 
    {
        ERROR = SIZE_ERROR;
        printf("\tSIZE BELLOW ZERO\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (stack->data == nullptr)
    {
        ERROR = ARRAY_PTR_ERROR;
        printf("\tNULLPTR ARRAY\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (stack->firstCanary != CANARY)
    {
        ERROR = LEFT_CANARY_ERROR;
        printf("\tLEFT CANARY ERROR\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (stack->secondCanary != CANARY)
    {
        ERROR = RIGHT_CANARY_ERROR;
        printf("\tRIGHT CANARY ERROR\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (*((canary_t*)(stack->data - sizeof(canary_t))) != CANARY)
    {
        ERROR = ARRAY_LEFT_CANARY_ERROR;
        printf("\tARRAY LEFT CANARY ERROR\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (!(*(canary_t*)((ptr_t)stack->data + STACK_CAPACITY * stack->size) & CANARY))
    {
        ERROR = ARRAY_RIGHT_CANARY_ERROR;
        printf("\tARRAY RIGHT CANARY ERROR\n\n");
        dumpStack(stack);
        return ERROR;
    }
    if (stack->hash != hash)
    {
        ERROR = HASH_ERROR;
        printf("\tHASH ERROR\n\n");
        dumpStack(stack);
        return ERROR;
    }
    return 0;
}

ptr_t peekMyStack(MyStack* stack, size_t elementPos)
{
    if (isValidMyStack(stack, hash(stack)))
        abort();
    if (elementPos > stack->len || elementPos == 0)
        return nullptr;
    else
        return stack->data + stack->len - elementPos;
}
