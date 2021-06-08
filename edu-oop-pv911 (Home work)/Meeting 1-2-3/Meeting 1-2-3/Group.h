#pragma once
#include <fstream>
#include "Contact.h"
#include "alph_qsort.h"

class Group
{
private:
	int size;
public:
	Contact** list;
	
	Group();
	Group(int);
	Group(char*);
	~Group();

	void print(char*) const;
	void search(char*) const;
	void edit(char*);
	void sort(char*);

	void add(char*);
	void remove(char*);

	void save();

private:
	char* techFun_load(std::ifstream&, int);
};
