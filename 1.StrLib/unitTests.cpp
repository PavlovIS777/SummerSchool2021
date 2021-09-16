#include "unitTests.h"

#pragma warning (disable:4996)
#pragma warning (disable:4067)
#pragma warning (disable:2008)

int customStrlenTest()
{
	FILE* input = fopen("strlenTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i) {
		char* buffer = (char*)malloc(100 * sizeof(char));
		int testLen = -1;
		int strlibLen = -1;
		getc(input);
		getc(input);

		fscanf(input, "%[^\n]", buffer);
		fscanf(input, "%d", &testLen);

		if (testLen == (strlibLen = customStrlen(buffer)))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				   "\t*** EXPECTED: %d ***\n"
				   "\t*** RECIEVED: %d ***\n\n", i + 1, testLen, strlibLen);
		}

		free(buffer);
	}
	fclose(input);

	return 1;
}

int customStrchrTest()
{
	FILE* input = fopen("strStrchrTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* buffer = (char*)malloc(100 * sizeof(char));
		char* symbol      = nullptr;
		int symbolPosTest = -1;
		char symbolTest    = -1;

		getc(input);
		getc(input);
		fscanf(input, "%[^\n]", buffer);
		getc(input);
		fscanf(input, "%c", &symbolTest);
		fscanf(input, "%d", &symbolPosTest);
		
		symbol = customStrchr(buffer, symbolTest);
		if ((symbol == nullptr && symbolPosTest == -1) || (symbol - buffer + 1 == symbolPosTest))
		{
			printf(TEST_PASSED);
		}
		else
		{
			if (symbolPosTest == -1 and symbol != nullptr)
			{
				printf("\t*** TEST %d ERROR ***\n"
					"\t*** EXPECTED: nullptr ***\n"
					"\t*** RECIEVED: %d ***\n\n", i + 1, symbol - buffer + 1);
			}
			else
			{
				printf("\t*** TEST %d ERROR ***\n"
					"\t*** EXPECTED: %d ***\n"
					"\t*** RECIEVED: %d ***\n\n", i + 1, symbolPosTest, symbol - buffer + 1);
			}
			
		}

		free(buffer);
	}
	fclose(input);

	return 1;
}

int customStrcpyTest()
{
	FILE* input = fopen("StrcpyTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* dest = (char*)malloc(200 * sizeof(char));
		char* src = (char*)malloc(100 * sizeof(char));
		char* outp = (char*)malloc(300 * sizeof(char));

		getc(input);
		getc(input);
		fscanf(input, "%[^\n]", dest);
		getc(input);
		fscanf(input, "%[^\n]", src);
		getc(input);
		fscanf(input, "%[^\n]", outp);

		customStrcpy(dest, src);

		if (!strcmp(dest, outp))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, outp, dest);
		}

		free(dest);
		free(src);
		free(outp);
	}
	fclose(input);

	return 1;
}

int customStrncpyTest()
{
	FILE* input = fopen("StrNcpyTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* dest = (char*)malloc(200 * sizeof(char));
		char* src = (char*)malloc(100 * sizeof(char));
		char* outp = (char*)malloc(300 * sizeof(char));
		int symbolCount = -1;

		getc(input);
		getc(input);
		fscanf(input, "%[^\n]", dest);
		getc(input);
		fscanf(input, "%[^\n]", src);
		fscanf(input, "%d", &symbolCount);
		getc(input);
		fscanf(input, "%[^\n]", outp);

		customStrncpy(dest, src, symbolCount);

		if (!strcmp(dest, outp))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, outp, dest);
		}

		free(dest);
		free(src);
		free(outp);
	}
	fclose(input);

	return 1;
}

int customStrcatTest()
{
	FILE* input = fopen("StrcatTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* dest = (char*)calloc(300, sizeof(char));
		char* src = (char*)malloc(100 * sizeof(char));
		char* outp = (char*)malloc(300 * sizeof(char));

		getc(input);
		getc(input);
		fscanf(input, "%[^\n]", dest);
		getc(input);
		fscanf(input, "%[^\n]", src);
		getc(input);
		fscanf(input, "%[^\n]", outp);

		customStrcat(dest, src);

		if (!strcmp(dest, outp))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, outp, dest);
		}

		free(dest);
		free(src);
		free(outp);
	}
	fclose(input);

	return 1;
}

int customStrncatTest()
{
	FILE* input = fopen("StrncatTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* dest = (char*)calloc(300, sizeof(char));
		char* src = (char*)malloc(100 * sizeof(char));
		char* outp = (char*)malloc(300 * sizeof(char));
		int symbolCount = -1;
		getc(input);
		getc(input);
		fscanf(input, "%[^\n]", dest);
		getc(input);
		fscanf(input, "%[^\n]", src);
		fscanf(input, "%d", &symbolCount);
		getc(input);
		fscanf(input, "%[^\n]", outp);

		customStrncat(dest, src, symbolCount);

		if (!strcmp(dest, outp))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, outp, dest);
		}

		free(dest);
		free(src);
		free(outp);
	}

	fclose(input);

	return 1;
}

int customFgetsTest()
{
	FILE* input = fopen("customFgetsTest.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	char fileBuffer[1000];
	int fileBufferPos = 0;
	int tmp = -1;
	while ((tmp = getc(input)) != EOF)
	{
		fileBuffer[fileBufferPos] = tmp;
		++fileBufferPos;
	}
	
	rewind(input);
	fileBufferPos = 3;

	fscanf(input, "%d", &testsCount);
	getc(input);

	for (int i = 0; i < testsCount; ++i)
	{
		char* bufferFgets = (char*)malloc(1000 * sizeof(char));
		char* bufferFC = (char*)calloc(1000, sizeof(char));
		int lenBufferFC = 0;
		getc(input);
		customFgets(bufferFgets, 1000, input);
		while ((tmp = fileBuffer[fileBufferPos]) != '\n')
		{
			++lenBufferFC;
			*bufferFC = tmp;
			++fileBufferPos;
			++bufferFC;
		}

		*bufferFC = fileBuffer[fileBufferPos];
		lenBufferFC;
		bufferFC -= lenBufferFC;
		fileBufferPos += 2;

		if (!strcmp(bufferFgets, bufferFC))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, bufferFC, bufferFgets);
		}

		free(bufferFgets);
		free(bufferFC);
	}
	fclose(input);
	return 1;
}

int customStrdupTest()
{
	FILE* input = fopen("customStrdup.txt", "r");
	int testsCount = -1;

	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* str = (char*)calloc(1000, sizeof(char));
		char* customBuffer;
		char* cBuffer = (char*)calloc(1000, sizeof(char));
		
		getc(input);
		getc(input);
		fscanf(input, "%[^\n]", str);

		customBuffer = customStrdup(str);
		cBuffer = strdup(str);

		if (!strcmp(cBuffer, customBuffer))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, cBuffer, customBuffer);
		}

		free(customBuffer);
		free(cBuffer);
	}

	fclose(input);

	return 1;
}

int customGetlineTest()
{
	FILE* input = freopen("customGetline.txt", "r", stdin);
	int testsCount = -1;
	
	if (input == nullptr) { return 0; }

	fscanf(input, "%d", &testsCount);

	for (int i = 0; i < testsCount; ++i)
	{
		char* buffer = (char*)malloc(1000 * sizeof(char));
		char* bufferTest = (char*)malloc(1000 * sizeof(char));

		getc(input);
		getc(input);
		customGetline(&buffer, 1000, input);
		
		scanf("%[^\n]", bufferTest);
		

		if (!strcmp(buffer, bufferTest))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, bufferTest, buffer);
		}
		free(buffer);
		free(bufferTest);
	}
	fclose(input);
	
	return 1;
}

int customPutsTest()
{
	FILE* input = freopen("customPutsTest.txt", "r", stdin);
	int testsCount = -1;
	if (input == nullptr) { return 0; }
	
	fscanf(input, "%d", &testsCount);
	getc(input);

	for (int i = 0; i < testsCount; ++i)
	{
		FILE* output = fopen("customPutsTestOutput.txt", "w+");
		char* bufferPuts = (char*)calloc(1000, sizeof(char));
		char* bufferTest = (char*)calloc(1000, sizeof(char));

		getc(input);
		customGetline(&bufferTest, 1000, stdin);
		customPuts(bufferTest, output);
		fflush(output);
		fclose(output);
		output = fopen("customPutsTestOutput.txt", "r");
 		fscanf(output, "%s", bufferPuts);
		fclose(output);

		if (!strcmp(bufferPuts, bufferTest))
		{
			printf(TEST_PASSED);
		}
		else
		{
			printf("\t*** TEST %d ERROR ***\n"
				"\t*** EXPECTED: %s ***\n"
				"\t*** RECIEVED: %s ***\n\n", i + 1, bufferTest, bufferPuts);
		}
		
		free(bufferPuts);
		free(bufferTest);
	}
	fclose(input);
	remove("customPutsTestOutput.txt");
	return 1;
}