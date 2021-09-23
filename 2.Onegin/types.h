#ifndef TYPES_H
#define TYPES_H

typedef wchar_t** buff;
typedef char* ptr_t;
typedef wchar_t* c_string;

struct MyString
{
	c_string string;
	size_t len;
};
#endif // !TYPES_H
