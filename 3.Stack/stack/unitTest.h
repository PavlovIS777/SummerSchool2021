#ifndef UNITTEST_H
#define UNITTEST_H

#include <stdio.h>
#include <stdlib.h>
#include "StackOverflow.h"
#include "unitTest.h"

void pushTest(void* element, size_t elementSize);

void popTest(MyStack* testStack);

size_t voidCompare(void* firstElement, void* secondElement, size_t size);
#endif // !UNITTEST_H
