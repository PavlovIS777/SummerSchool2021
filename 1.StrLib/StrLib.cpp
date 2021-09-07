#include "StrLib.h"
#include <string.h>

int customPuts(const char* string)
{
    if (string == nullptr) { return EOF; }

    size_t strLength = -1; // ��� ������������� (����� ����, �� ��)
    for (strLength = 0; char tmp = string[strLength]; ++strLength)// ������ �������� ok
    {
        fputc(tmp, stdout);
    }
    fputc('\n', stdout);

    return strLength; // � ����������-�� int! � ����� ����� "++"? ok
}


char* customStrchr(char* string, char symbol) // ������ �� const char* string? (����)
{
    if (string == nullptr) { return nullptr; }

    for (size_t symbolPos = 0; char currentSymbol = string[symbolPos]; ++symbolPos)
    {
        if (currentSymbol == symbol) {
            return string + symbolPos;
        }
    }

    return nullptr;
}


size_t customStrlen(const char* str)
{
    if (str == nullptr) { return EOF; }

    size_t symbolPos = 0;

    while (str[symbolPos])
    {
        ++symbolPos;
    }

    return symbolPos;
}


int customStrcpy(const char* srcstr, char* destination) // ����� ���� ����
{
    if (destination == nullptr || srcstr == nullptr) { return EOF; }

    int copiesNumber = 0;

    while (char tmp = *srcstr)
    {
        ++copiesNumber;
        *destination = tmp; // ������ ����� � ��� ������
        ++destination;
        ++srcstr;
    }

    *destination = '\0';

    return copiesNumber;
}


int customStrncpy(const char* srcstr, char* destination, int n)// ����....
{
    if (destination == nullptr || srcstr == nullptr || n < 0) { return EOF; }

    int copiesNumber = 0;
    int newSymbol = '\0';
    while ((newSymbol = *srcstr) && n)
    {
        ++copiesNumber;
        *destination = newSymbol;
        --n;
        ++srcstr;
        ++destination;
    }

    *destination = '\0';
    return copiesNumber;
}


int customStrcat(char* destination, const char* srcstr)
{
    if (destination == nullptr || srcstr == nullptr) { return EOF; }
    int copiesNumber = 0;

    destination += customStrlen(destination);

    while (char tmp = *srcstr)
    {
        ++copiesNumber;
        *destination = tmp;
        ++destination;
        ++srcstr;
    }

    *destination = '\0';

    return copiesNumber;
}


int customStrncat(char* destination, const char* srcstr, int n) // ����������� ��������� - ������ ���� ������� ������ ��������. ������ (������ ���� ���� � ������ ����������, �������?)
{                                                               // ����� ������ ��� �� �� 10 ��� ���� ����� �����������. 
    if (destination == nullptr || srcstr == nullptr || n <= 0) { return EOF; }

    int copiesNumber = 0;

    destination += customStrlen(destination);
    int newSymbol = '\0';

    while ((newSymbol = *srcstr) && n)
    {
        ++copiesNumber;
        *destination = newSymbol;
        ++destination;
        ++srcstr;
        --n;
    }

    *destination = '\0';
    return copiesNumber;
}


int customFgets(FILE* fp, int MAXLEN, char* string)
{         // nullptr            ��� ��������� � ���� ���������? (
    if (fp == nullptr || string == nullptr || MAXLEN < 1) { return EOF; }
    int getsNumber = 0;
    int receivedChar = '\0'; // �������������; ������ ��������; fgetc ���������� int - �����
    do
    {
        receivedChar = fgetc(fp);
        ++getsNumber;
        *string = receivedChar;
        ++string;
        --MAXLEN;
    } while (receivedChar != '\n' && receivedChar != EOF && MAXLEN > 1);

    *string = '\0';

    return getsNumber;
}


char* customStrdup(const char* string)
{//             nullptr?
    if (string == nullptr) { return nullptr; }

    int len = customStrlen(string); // ��� �������������� EOF (��, ������ �� ����� ���� ������� ������ ���� string == nullptr, �� ����� ������ ������, � ��� ����� ����� ��������� ���)?

    if (len == EOF)
    {
        return nullptr;
    }
    else ++len;

    char* copiedStr = (char*)calloc(len, sizeof(char));

    copiedStr = (char*)memcpy((void*)copiedStr, (void*)string, len);

    return copiedStr;
}


int customGetline(char* string, int MAXLEN, char separator)
{//                        ��� � ����������?
    if (string == nullptr || MAXLEN <= 0) { return EOF; }

    int lineLength = 0;
    int receivedChar = fgetc(stdin); // ����� char?!

    while (receivedChar != separator && MAXLEN > 1)
    {
        ++lineLength;
        *string = receivedChar;
        ++string;
        --MAXLEN;
        receivedChar = fgetc(stdin);
    }

    *string = '\0';
    return lineLength; // ���������� ������ �����?
}