#include "header.h"

int main()
{
#pragma region Presetting

	srand(time(0));
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

#pragma endregion
	
#pragma region Description

	/*
	 
	 */

#pragma endregion 
	
	do { system("cls");

		Factory Chair_and_Table;

		Chair_and_Table.work(720);
		
		std::cout << "\n\n";
	} while (restart());
}