/**
 * Randomaizer
 *
 * @author Artem Kashyrin
 *
*/

#include <iostream>
#include <windows.h>

#include <ctime>   // For time()
#include <cstdlib> // For srand() and rand()
#include <random>  // For random_device and mt19937
using namespace std;



void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Initialize random number generator. (1-100) r = (rand() % 100) + 1;
	srand(time(0));
	int randFix = rand();

	// Initialize random number generator the Mersenne Twister
	random_device rd;
	mt19937 mersenne(rd());

	
	enum { Rows = 2, Cols };



	int arr2[Rows][Cols] = { 1 };



	cout << arr2[1][2];




	
	/*
	int cases, random_V1, random_V2;

	cout << " Enter number: ";
	cin >> cases;
	uniform_int_distribution<> randMT(1, cases);

	for (int i = 0; i < 10000; i++) {
		random_V1 = (rand() % cases) + 1;
		random_V2 = randMT(rd);

		cout << random_V1 << " " << random_V2 << endl;
	}
	*/

	system("pause");
	return;
}