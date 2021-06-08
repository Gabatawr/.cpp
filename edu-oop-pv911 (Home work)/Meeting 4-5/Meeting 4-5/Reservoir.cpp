#include "Reservoir.h"

const char* rand_name();

Reservoir::Reservoir()
{
	name = rand_name();
	type = Types_of_reservoirs(rand() % 3 + 2);
	
	width = rand() % 4000 + 1000;
	length = rand() % 4000 + 1000;
	max_deep = rand() % 40 + 10;
	
	this->calc_volume();
	this->calc_area();
}
Reservoir::Reservoir(const char* name, Types_of_reservoirs type)
{
	this->name = name;
	this->type = type;
	
	width = 0;
	length = 0;
	max_deep = 0;
	volume = 0;
	area = 0;
}
Reservoir::Reservoir(const char* name, Types_of_reservoirs type, unsigned width, unsigned length)
{
	this->name = name;
	this->type = type;
	
	this->width = width;
	this->length = length;
	max_deep = 0;
	
	this->volume = 0;
	this->calc_area();
}
Reservoir::Reservoir(const char* name, Types_of_reservoirs type, unsigned width, unsigned length, unsigned max_deep)
{
	this->name = name;
	this->type = type;
	
	this->width = width;
	this->length = length;
	this->max_deep = max_deep;
	
	this->calc_volume();
	this->calc_area();
}

Reservoir::Reservoir(const Reservoir& other)
{
	this->name = other.name;
	this->type = other.type;

	this->width = other.width;
	this->length = other.length;
	this->max_deep = other.max_deep;

	this->volume = other.volume;
	this->area = other.area;
}

void Reservoir::calc_volume()
{
	if (width > 0 && length > 0 && max_deep > 0) volume = width * length * max_deep;
	else volume = 0;
}
void Reservoir::calc_area()
{
	if (width > 0 && length > 0) area = width * length;
	else area = 0;
}

unsigned Reservoir::get_volume() const
{
	return volume;
}
unsigned Reservoir::get_area() const
{
	return area;
}

Reservoir& Reservoir::operator = (const Reservoir& other)
{
	this->name = other.name;
	this->type = other.type;

	this->width = other.width;
	this->length = other.length;
	this->max_deep = other.max_deep;

	this->volume = other.volume;
	this->area = other.area;

	return *this;
}

bool Reservoir::operator == (Reservoir& other) const
{
	return this->type == other.type;
}
bool Reservoir::operator != (Reservoir& other) const
{
	return this->type != other.type;
}

bool Reservoir::compare_area(Reservoir& other) const
{
	if (*this == other)
	{
		std::cout << this->area << (this->area > other.area ? " > " : this->area < other.area ? " < " : " = ") << other.area;
		return true;
	}
	return false;
}

