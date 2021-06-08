#pragma once
#include "Human.h"

class Apartment
{
public:
	unsigned size;
	Human* lodgers;
	
	Apartment();
	~Apartment();

	void print() const;
};

