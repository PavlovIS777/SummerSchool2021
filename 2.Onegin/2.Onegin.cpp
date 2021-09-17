#include "CLI.h"
#include <stdio.h>
#include <assert.h>

#pragma warning(disable:4996)

int main(void)
{
	FILE* input = fopen("input.txt", "r");
	assert(input != nullptr);

	int stringCount = stringsCount(input);

	consoleSortInterface(input, stringCount);

	return 0;
}
