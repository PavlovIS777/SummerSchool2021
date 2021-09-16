#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrLib.h"

#define TEST_PASSED "\t*** TEST %d PASSED ***\n\n", i+1

int customStrlenTest();

int customStrchrTest();

int customStrcpyTest();

int customStrncpyTest();

int customStrcatTest();

int customStrncatTest();

int customFgetsTest();

int customStrdupTest();

int customGetlineTest();

int customPutsTest();
#endif // !UNITTESTS.H