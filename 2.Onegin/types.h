#ifndef TYPES_H
#define TYPES_H

typedef char** buff;
typedef char* ptr_t;
typedef char* c_string;

struct MyString
{
	c_string string;
	size_t len;
};
#endif // !TYPES_H
