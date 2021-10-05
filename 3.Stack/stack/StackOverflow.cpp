#include "StackOverflow.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <string.h>


const canary_t CANARY = 0xBADCACA;
FILE* LOG = fopen("LOG.TXT", "w+");

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

size_t myHash(const MyStack* stack)
{
    ptr_t startStack = (ptr_t) (&stack->firstCanary);
    ptr_t endStack = (ptr_t)&stack->secondCanary + sizeof(canary_t);

    size_t hash = 0;
    for (int i = 0; i < stack->dataStruct.blockCount; ++i)
    {
        hash = hashFunc(stack->dataStruct.dataBlocks[i]-sizeof(canary_t), STACK_BLOCK_CAPACITY * stack->size + sizeof(canary_t), hash);
    }

    size_t stackHashLen = endStack - startStack;
    size_t hashStack = hashFunc(startStack, stackHashLen, hash);

    return hashStack;
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

void newStackDataBlock(MyStack* stack)
{
    size_t extraMem = sizeof(canary_t) / stack->size;
    ptr_t newBlock = (ptr_t)safeCalloc(256 + 2 * extraMem, stack->size);
    *(canary_t*)newBlock = CANARY;
    *(canary_t*)(newBlock + STACK_BLOCK_CAPACITY * stack->size + sizeof(canary_t)) = CANARY;
    stack->dataStruct.dataBlocks[stack->dataStruct.blockCount] = newBlock + sizeof(canary_t);
}
MyStack createStack(size_t size)
{
    ptr_t* dataBlocks = (ptr_t*)safeCalloc(256, sizeof(ptr_t));
    MyData dataStruct = {0, 0, dataBlocks};

    MyStack stack = { CANARY, 0, size, dataStruct, nullptr, CANARY,  0 };
    newStackDataBlock(&stack);
    stack.dataStruct.blockCount++;

    stack.hash = myHash(&stack);
    isValidMyStack(&stack);

    return stack;
}

void dumpStack(const MyStack* stack)
{  
    fprintf(LOG, "\t  INFO ABOUT STACK\n\n"
           "\tLEFT CANARY:  %zu\n"
           "\tHASH:         %zu\n"
           "\tSIZE:         %zu\n"
           "\tLENGHT:       %zu\n"
           "\tCAPACITY:     %zu\n"
           "\tRIGHT CANARY: %zu\n\n"
           "\t\tARRAY\n\n"
           "\tLEFT ARRAY CANARY:  %zu\n"
           "\tRIGHT ARRAY CANARY: %zu\n"
           "\tARRAY PTR: %p\n\n", stack->firstCanary, stack->hash, stack->size,
                                  stack->len, STACK_BLOCK_CAPACITY * stack->dataStruct.blockCount, stack->secondCanary,
                                  *(canary_t*)(stack->dataStruct.dataBlocks[0] - sizeof(canary_t)),
                                  *(canary_t*)(stack->dataStruct.dataBlocks[0] + STACK_BLOCK_CAPACITY * stack->size), stack->dataStruct.dataBlocks[0]);
    size_t len = stack->len;
    fprintf(LOG, "\t  STACK BLOCKS:\n\n");
    for (int j = 0; j < stack->dataStruct.blockCount; ++j)
    {
        fprintf(LOG, "\tARRAY %d\n", j + 1);
        for (int i = 0;(j + 1 == stack->dataStruct.blockCount && i < stack->dataStruct.currentLen) || 
                        (j + 1 < stack->dataStruct.blockCount && i < 256); ++i)
        {
            fprintf(LOG, "\t************\n"
                         "\tBLOCK: %d\n"
                         "\tBLOCK PTR: %p\n"
                         "\t************\n\n", i + 1, stack->dataStruct.dataBlocks[j] + i * stack->size);
        }
    }
}

void pushMyStack(MyStack* stack, ptr_t element, size_t sizeOfElement)
{
    if (isValidMyStack(stack))
        abort();

    if (stack->len == 256 * stack->dataStruct.blockCount)
    {
        newStackDataBlock(stack);
        stack->dataStruct.blockCount++;
        stack->dataStruct.currentLen = 0;
    }
    stack->top = stack->dataStruct.dataBlocks[stack->dataStruct.blockCount - 1] + stack->dataStruct.currentLen * stack->size;
    memcpy(stack->top, element, sizeOfElement);
    stack->len++;
    stack->dataStruct.currentLen++;
    stack->hash = myHash(stack);
}

ptr_t popMyStack(MyStack* stack)
{
    if (isValidMyStack(stack))
        abort();
    if (stack->len == 0) { return nullptr; }

    ptr_t top = (ptr_t)safeCalloc(1, stack->size);
    memcpy(top, stack->top, stack->size);

    if (stack->dataStruct.currentLen - 1 < 0 && stack->dataStruct.blockCount > 1) 
    {
        free(stack->dataStruct.dataBlocks[stack->dataStruct.blockCount - 1]);
        stack->dataStruct.currentLen = STACK_BLOCK_CAPACITY - 1;
        stack->dataStruct.blockCount--;
    }
    else
    {
        stack->dataStruct.currentLen--;
    }
    stack->top -= stack->size; 
    stack->len--;
    stack->hash = myHash(stack);

    return top;
}

int isValidMyStack(const MyStack* stack)
{
    if (stack == nullptr) {
        fprintf(LOG, "\tNULLPTR STACK\n\n");
        dumpStack(stack);
        return NULL_PTR_ERROR;
    }
    if (stack->dataStruct.dataBlocks == nullptr)
    {
        fprintf(LOG, "\tNULLPTR ARRAY\n\n");
        dumpStack(stack);
        return ARRAY_PTR_ERROR;
    }
    if (stack->firstCanary != CANARY)
    {
        fprintf(LOG, "\tLEFT CANARY ERROR\n\n");
        dumpStack(stack);
        return LEFT_CANARY_ERROR;
    }
    if (stack->secondCanary != CANARY)
    {
        fprintf(LOG, "\tRIGHT CANARY ERROR\n\n");
        dumpStack(stack);
        return RIGHT_CANARY_ERROR;
    }
    int ERROR = NO_ERROR;
    for (int i = 0; i < stack->dataStruct.blockCount; ++i)
    {
        if (*(canary_t*)(stack->dataStruct.dataBlocks[i] - sizeof(canary_t)) != CANARY)
        {
            ERROR = ARRAY_LEFT_CANARY_ERROR;
            fprintf(LOG, "ARRAY LEFT CANARY ERROR, ARRAY BLOCK: %d\n", i+1);
        }
    }
    if (ERROR == ARRAY_LEFT_CANARY_ERROR)
    {
        dumpStack(stack);
        return ERROR;
    }
    for (int i = 0; i < stack->dataStruct.blockCount; ++i)
    {
        if (*(canary_t*)(stack->dataStruct.dataBlocks[i] + STACK_BLOCK_CAPACITY * stack->size) != CANARY)
        {
            ERROR = ARRAY_RIGHT_CANARY_ERROR;
            fprintf(LOG, "ARRAY RIGHT CANARY ERROR, ARRAY BLOCK: %d\n", i+1);
        }
    }
    if (ERROR == ARRAY_RIGHT_CANARY_ERROR)
    {
        dumpStack(stack);
        return ERROR;
    }
    if (myHash(stack) != stack->hash)
    {
        fprintf(LOG, "\tHASH ERROR\n\n");
        dumpStack(stack);
        return HASH_ERROR;
    }
    return NO_ERROR;
}
