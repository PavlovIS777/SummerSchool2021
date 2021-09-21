#include "CLI.h"
#include <stdlib.h>
#include "qsortStr.h"
#include <time.h>
#include "comparator.h"

int main(void)
{
	//consoleSortInterface();
	int count = 5;
	int* arr = (int*)calloc(count, sizeof(int));

	srand(1771894123);
	for (int i = 0; i < count; ++i)
	{
		arr[i] = rand();
	}
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n\n\n\n\n\n\n");
	myQsort(arr, count, sizeof(int), compareInt);

	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
