#include "unitTests.h"
#include "comparator.h"
#include "qsortStr.h"
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

void testFunc(int compare(const void* s_void, const void* t_void))
{
	srand(L'�' + L'�' + L'�' + L'�' + L'�');
	size_t testStrCount = 20 + rand() % 20;
	MyString* testBuff = (MyString*)calloc(testStrCount, sizeof(MyString));
	for (int k = 0; k < testStrCount; ++k)
	{
		size_t testStrLen = 20 + rand() % 20;
		c_string testStr = (c_string)calloc(testStrLen, sizeof(wchar_t));
		testStr[0] = L'�' + rand() % 33 - 1;
		for (int j = 1; j < testStrLen - 2; ++j)
			testStr[j] = L'�' + rand() % 33 - 1;
		testStr[testStrLen - 2] = '\n';
		testBuff[k].string = testStr;
		testBuff[k].len = testStrLen - 1;
	}

	myQsort(testBuff, testStrCount, sizeof(MyString), compare);

	for (int l = 0; l < testStrCount - 1; ++l)
	{
		if (compare(&testBuff[l + 1].string, &testBuff[l].string) < 0)
		{
			wprintf(L"*****�������********\n");
			wprintf(L"�������� ������� ����� � �������� �������:\n\n");
			wprintf(L"1-�� ������: %ls\n", testBuff[l].string);
			wprintf(L"2-�� ������: %ls\n", testBuff[l + 1].string);
			wprintf(L"********************\n\n");
		}
	}
}
