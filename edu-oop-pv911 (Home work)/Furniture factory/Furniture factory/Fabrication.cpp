#include "Fabrication.h"

Furniture::Furniture()
{
	type = Type::def;
	raw = new int[3];
	raw[0] = raw[1] = raw[2] = 0;
}

Furniture::~Furniture()
{
	delete raw;
}

Chair::Chair()
{
	this->type = Type::chair;
	this->raw[0] = rand() % 10;
	this->raw[1] = rand() % 15;
	this->raw[2] = rand() % 5;
}

Table::Table()
{
	this->type = Type::table;
	this->raw[0] = rand() % 5;
	this->raw[1] = rand() % 30;
	this->raw[2] = rand() % 15;
}

Fabrication::Fabrication()
{
	created_chair = created_table = 0;
}

Fabrication::~Fabrication()
{
	queue.remove();
}
