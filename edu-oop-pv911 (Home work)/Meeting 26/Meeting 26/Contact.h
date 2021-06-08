#pragma once
#include "header.h"

class Contact
{
friend class Directory;

public:  string company;
		 string busyness;
private: string owner;
		 string phone;
		 string address;
		 
public:  Contact();
		~Contact() = default;
	
		 void edit();
	
friend   std::ostream& operator << (std::ostream&, Contact&);
		 string& at(int);
};
