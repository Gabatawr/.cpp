#include <iostream>
#include <cstdlib>
#include <ctime>

#define INTEGER
#define CHAR
#define DOUBLE

#include "function.h"


int main ()
{
	srand(time(0));

#ifdef INTEGER
	int array_int_size = 10;
	auto* array_int = new int[array_int_size];
	FillArrRandVal(array_int, array_int_size, true, 0, 100);
	std::cout << "\n\n Array int: ";
	PrintArrVal(array_int, array_int_size);
	std::cout << "\n Min: " << FindArrMinVal(array_int, array_int_size);
	std::cout << "\n Max: " << FindArrMaxVal(array_int, array_int_size);
	qSortArrVal(array_int, array_int_size);
	std::cout << "\n After sort: ";
	PrintArrVal(array_int, array_int_size);
	delete[] array_int;
#endif

#ifdef CHAR
	int array_char_size = 10;
	auto* array_char = new char[array_char_size];
	FillArrRandVal(array_char, array_char_size, true, 97, 122);
	std::cout << "\n\n Array char: ";
	PrintArrVal(array_char, array_char_size);
	std::cout << "\n Min: '" << FindArrMinVal(array_char, array_char_size) << "'";
	std::cout << "\n Max: '" << FindArrMaxVal(array_char, array_char_size) << "'";
	qSortArrVal(array_char, array_char_size);
	std::cout << "\n After sort: ";
	PrintArrVal(array_char, array_char_size);
	delete[] array_char;
#endif

#ifdef DOUBLE
	int array_double_size = 10;
	auto* array_double = new double[array_double_size];
	FillArrRandVal(array_double, array_double_size, true, 10.1, 10.2);
	std::cout << "\n\n Array double: ";
	PrintArrVal(array_double, array_double_size);
	std::cout << "\n Min: " << FindArrMinVal(array_double, array_double_size);
	std::cout << "\n Max: " << FindArrMaxVal(array_double, array_double_size);
	qSortArrVal(array_double, array_double_size);
	std::cout << "\n After sort: ";
	PrintArrVal(array_double, array_double_size);
	delete[] array_double;
#endif

	std::cout << "\n\n";
	system("pause");
	return 0;
}
