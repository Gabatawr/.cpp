#include "Fabric.h"

Base* Base::get(type T)
{
	if (T == rnd)
	{
		switch (rand() % 4)
		{
			case 1:  return new A;
			case 2:  return new B;
			case 3:  return new C;
			default: return new Z;
		}
	}
	
	return T == a ? new A :
		   T == b ? new B :
		   T == c ? new C : (Base*)new Z;
}

void A::print()
{
	std::cout << " A\n";
}
void B::print()
{
	std::cout << " B\n";
}
void C::print()
{
	std::cout << " C\n";
}
void Z::print()
{
	std::cout << " Z\n";
}
