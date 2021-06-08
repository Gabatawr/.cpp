#pragma once
#include <iostream>

class String
{
private:
	static int count;
	int size;
	char* line;
	
public:	
	String();
	String(int);
	String(const char*);
	String(char*, int);
	~String();

	static int get_count();
	
	int len();

	friend std::ostream& operator << (std::ostream&, const String&);
	friend std::istream& operator >> (std::istream&, String&);
};