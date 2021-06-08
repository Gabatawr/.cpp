#pragma once
#include "header.h"

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

class Directory
{
public: vector<Contact*> list;
	
		Directory() = default;
		explicit Directory(const char*);
	   ~Directory();

		void print(string&);
		void search(string&);
		void edit(std::string&);

		void add(string&);
		void del(string&);

		void save(const char*);
};
