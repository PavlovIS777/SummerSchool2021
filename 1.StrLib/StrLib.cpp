#include "StrLib.h"
#include <string.h>

int customPuts(const char* string)
{
    if (string == nullptr) { return EOF; }

    size_t strLength = -1; // нет инициализации (нафиг надо, но ок)
    for (strLength = 0; char tmp = string[strLength]; ++strLength)// плохое название ok
    {
        fputc(tmp, stdout);
    }
    fputc('\n', stdout);

    return strLength; // а возвращаем-то int! и зачем здесь "++"? ok
}


char* customStrchr(char* string, char symbol) // почему не const char* string? (урыл)
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


int customStrcpy(const char* srcstr, char* destination) // здесь есть баги
{
    if (destination == nullptr || srcstr == nullptr) { return EOF; }

    int copiesNumber = 0;

    while (char tmp = *srcstr)
    {
        ++copiesNumber;
        *destination = tmp; // дважды лезем в эту память
        ++destination;
        ++srcstr;
    }

    *destination = '\0';

    return copiesNumber;
}


int customStrncpy(const char* srcstr, char* destination, int n)// баги....
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


int customStrncat(char* destination, const char* srcstr, int n) // аналогичные замечания - налицо твое желание делать копипаст. АЙАЙАЙ (знаешь куда идти с такими поправками, душнила?)
{                                                               // зачем писать что то по 10 раз если можно копипастить. 
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
{         // nullptr            что случилось с этим названием? (
    if (fp == nullptr || string == nullptr || MAXLEN < 1) { return EOF; }
    int getsNumber = 0;
    int receivedChar = '\0'; // инициализация; плохое название; fgetc возвращает int - фикси
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

    int len = customStrlen(string); // как обрабатывается EOF (да, сейчас он может быть получен только если string == nullptr, но проги иногда меняют, и это место может сгенерить баг)?

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
{//                        что с кодстайлом?
    if (string == nullptr || MAXLEN <= 0) { return EOF; }

    int lineLength = 0;
    int receivedChar = fgetc(stdin); // опять char?!

    while (receivedChar != separator && MAXLEN > 1)
    {
        ++lineLength;
        *string = receivedChar;
        ++string;
        --MAXLEN;
        receivedChar = fgetc(stdin);
    }

    *string = '\0';
    return lineLength; // возвращать размер линии?
}