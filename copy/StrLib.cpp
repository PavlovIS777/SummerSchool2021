#include "StrLib.h"

// int customPuts(const char* str)
// {
//     if (str == nullptr)
//         return -2;
//     size_t letterPos = 0;
//     while (str[letterPos])
//     {
//         if(str[letterPos] == EOF) {
//             return EOF;
//         }
//         fputc(str[letterPos], stdout);
//         ++letterPos;
//     }
//     printf("\n");
//     return 1;
// }

char * strchrCustom( const char * string, char symbol)
{
    size_t symbolPos = 0;
    
    while (string[symbolPos])
    {
        if(string[symbolPos] == symbol) {
            char* output = (char*)(&string[symbolPos]);       
            
            return output;
        }
    }
    
    return nullptr;
}