#pragma once
#include "str_lib.h"

class Contact
{
public:
	char* name;	
private:
	char* home_phone;
	char* work_phone;
	char* mobile_phone;
	char* info;

public:
	Contact();
	Contact(char*);
	~Contact();
	
private:
	void replace_field(char*&);
public:
	void print(char*);
	void edit(char*);

	char* operator [] (int) const;

	friend class Group;
};
