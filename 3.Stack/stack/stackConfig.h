#ifndef STACKCONFIG_H
#define STACKCONFIG_H
#pragma warning(disable:4996)
#include <stdio.h>

#define PROTECTION_LEVEL 0

typedef char* ptr_t;

#if PROTECTION_LEVEL == 1
typedef size_t canary_t;
#endif

const size_t STACK_BLOCK_CAPACITY = 256;


#if PROTECTION_LEVEL == 1
enum STACK_ERRORS
{
	NO_ERROR				,
	NULL_PTR_ERROR			,
	SIZE_ERROR				,
	ARRAY_PTR_ERROR			,
	HASH_ERROR				,
	LEFT_CANARY_ERROR		,
	RIGHT_CANARY_ERROR		,
	ARRAY_LEFT_CANARY_ERROR	,
	ARRAY_RIGHT_CANARY_ERROR
};
#endif

#endif // !STACKCONFIG_H
