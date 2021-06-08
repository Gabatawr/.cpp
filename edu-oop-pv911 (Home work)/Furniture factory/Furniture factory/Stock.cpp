#include "Stock.h"

Stock* Stock::ptr = nullptr;

Stock::Stock()
{
	raw[0] = new Textile;
	raw[1] = new Wood;
	raw[2] = new Metal;
}
Stock::~Stock()
{
	for (auto i = 0; i < 3; i++)delete raw[i];
}

Stock* Stock::Create()
{
	if (not ptr) ptr = new Stock();
	return ptr;
}

void Stock::Delete()
{
	if (ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

void Stock::add(int* arr)
{
	raw[0]->add(arr[0]); raw[1]->add(arr[1]); raw[2]->add(arr[2]);
	delete arr;
}

bool Stock::take(int* arr)
{
	if (arr[0] > raw[0]->size() || arr[1] > raw[1]->size() || arr[2] > raw[2]->size()) return false;
	return raw[0]->take(arr[0]) && raw[1]->take(arr[1]) && raw[2]->take(arr[2]);
}
