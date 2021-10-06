#ifndef UNITTEST_H
#define UNITTEST_H

#if PROTECTION_LEVEL == 1
void stackPushPopTest();

void stackLeftCanaryTest();

void stackRightCanaryTest();

void arrayStackLeftCanaryTest();

void arrayStackRightCanaryTest();

void stackHashTest();
#endif
#endif // !UNITTEST_H
