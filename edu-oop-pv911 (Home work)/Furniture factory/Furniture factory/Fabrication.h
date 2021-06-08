#pragma once
#include "List.h"

enum class Type { def, chair, table };

class Furniture
{
public:
	int* raw;
	
	Type type;
	Furniture();
	virtual ~Furniture();
};

class Chair : public Furniture { public: Chair(); };
class Table : public Furniture { public: Table(); };


class Fabrication
{
public:
	int created_chair;
	int created_table;

	List<Furniture*> queue;

	Fabrication();
	~Fabrication();
};