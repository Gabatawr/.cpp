#pragma once
#include "Material.h"

class Stock
{
public:
	static Stock* Create();
	static void Delete();

	Material** raw = new Material* [3];

	void add(int*);
	bool take(int*);
	
	
private:
	static Stock* ptr;
	
	Stock();
	~Stock();
	Stock(const Stock*) = delete;
	Stock& operator=(const Stock*) = delete;
};

