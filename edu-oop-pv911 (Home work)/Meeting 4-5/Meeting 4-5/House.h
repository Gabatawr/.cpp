#pragma once
#include "Apartment.h"

class House
{
public:
	unsigned size;
	Apartment* rooms;
	
	House();
	House(unsigned);
	~House();

	void print() const;
};

