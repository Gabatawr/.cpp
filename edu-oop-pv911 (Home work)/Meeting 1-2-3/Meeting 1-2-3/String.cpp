#include "String.h"
#define size_def 81

int String::count = 0;

String::String()
{
	size = size_def;
	line = new char[size_def];
	
	for (auto i = 0; i < size; i++) line[i] = '#';
	line[size - 1] = '\0';
	
	count++;
}

String::String(int str_size)
{
	if (++str_size < 2) size = size_def;
	size = str_size;
	line = new char[size];

	for (auto i = 0; i < size; i++) line[i] = '#';
	line[size - 1] = '\0';

	count++;
}

String::String(const char* str)
{
	int s = 0;
	while (str[s++] != '\0');
	size = ++s;
	
	line = new char[size];
	for (auto i = 0; i < size; i++) line[i] = str[i];

	count++;
}

String::String(char* str, int str_size) : String(str_size)
{
	if (str != nullptr) for (auto i = 0; i < size - 1; i++) line[i] = str[i];
}

String::~String()
{
	delete[] line;
	count--;
}

int String::get_count()
{
	return count;
}

int String::len()
{
	return size - 1;
}

std::ostream& operator << (std::ostream& out, const String& str)
{
	return out << (const char*)str.line;
}

std::istream& operator >> (std::istream& in, String& str)
{
	if (in.peek() == '\n') in.ignore();
	return in.getline(str.line, str.size);
}