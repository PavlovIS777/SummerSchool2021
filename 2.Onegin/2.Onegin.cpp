#include "CLI.h"
#include "unitTests.h"
#include "comparator.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	//consoleSortInterface();
	testFunc(endCompareStr);
}
