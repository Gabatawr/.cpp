#pragma once
#include "String.h"

enum class Types_of_reservoirs { Ocean, Sea, Lake, Pond, Reservoir };

class Reservoir
{
public:
	String name;
	Types_of_reservoirs type;

	unsigned width;
	unsigned length;
	unsigned max_deep;
	
private:
	unsigned volume;
	unsigned area;
	
public:	
	Reservoir();
	Reservoir(const char*, Types_of_reservoirs);
	Reservoir(const char*, Types_of_reservoirs, unsigned, unsigned);
	Reservoir(const char*, Types_of_reservoirs, unsigned, unsigned, unsigned);
	Reservoir(const Reservoir&);
	
	void calc_area();
	void calc_volume();

	unsigned get_volume() const;
	unsigned get_area() const;

	Reservoir& operator = (const Reservoir&);

	bool operator == (Reservoir&) const;
	bool operator != (Reservoir&) const;

	bool compare_area(Reservoir&) const;
};

