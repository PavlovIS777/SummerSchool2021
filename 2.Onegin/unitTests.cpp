#include "CLI.h"
#include "unitTests.h"
#include "comparator.h"
#include "qsortStr.h"
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

void testFunc(int compare(const void* s_void, const void* t_void))
{
	int testStrCount = 0;
	c_string testStr = oneginStr(&testStrCount);

	MyString* testBuff = (MyString*)safeCalloc(testStrCount, sizeof(MyString));
	for (size_t i = 0; i < testStrCount; ++i)
	{
		size_t len = wcslen(testStr);
		testBuff[i].string = testStr;
		testBuff[i].len = len;
		testStr += len + 1;
	}
	myQsort(testBuff, testStrCount, sizeof(MyString), compare);

	for (int l = 0; l < testStrCount - 1; ++l)
	{
		if (compare(&testBuff[l + 1].string, &testBuff[l].string) < 0)
		{
			wprintf(L"*****абшибка********\n");
			wprintf(L"Неверный порядок строк в тестовом буффере:\n\n");
			wprintf(L"1-ая строка: %ls\n", testBuff[l].string);
			wprintf(L"2-ая строка: %ls\n", testBuff[l + 1].string);
			wprintf(L"********************\n\n");
		}
	}
	for (int l = 0; l < testStrCount; ++l)
	{
		wprintf(L"%ls\n", testBuff[l].string);
	}
}
