#include "Apartment.h"

Apartment::Apartment()
{
	size = rand() % 6;
	lodgers = new Human[size];
}

Apartment::~Apartment()
{
	delete[] lodgers;
}

void Apartment::print() const
{
	if (size == 0) std::cout << " Lodgers: 0 |";
	else 
	{
		std::cout << " Lodgers: " << size << " | ";
		for (unsigned i = 0; i < size; i++) std::cout << "#" << i + 1 << " " << lodgers[i].name << "  ";
	}
}
