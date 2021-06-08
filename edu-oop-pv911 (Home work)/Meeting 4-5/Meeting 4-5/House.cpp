#include "House.h"

House::House()
{
	size = rand() % 55 + 10;
	rooms = new Apartment[size];
}

House::House(unsigned size)
{
	if (size == 0) size++;
	this->size = size;
	rooms = new Apartment[this->size];
}

House::~House()
{
	delete[] rooms;
}

void House::print() const
{
	std::cout << "\n This house has " << size << " apartments\n\n";
	for (auto i = 0; i < size; i++)
	{
		std::cout << " Apartment #" << (i < 9 ? "0" : "") << i + 1 << " |";
		rooms[i].print();
		std::cout << "\n";
	}
}
