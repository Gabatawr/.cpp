#pragma once
#include "header.h"
#include "Stock.h"
#include "Fabrication.h"

class Factory
{
public:
	int work_tyme;
	int current_tyme;

	int completed_orders;
	
	Fabrication* fabrication;
	Stock* stock;
	
	Factory();
	~Factory();

	void supply();
	Furniture* new_order(Type);

	void work(int);
};

