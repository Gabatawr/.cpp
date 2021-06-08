#include "Header.h"

void do_task_1_2_3()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task:\t"
				<< "1. Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию." << "\n\t\t"
				<< "2. Написать функцию, удаляющую столбец двух-мерного массива по указанному номеру." << "\n\t\t"
				<< "3. Написать функцию, сдвиг строк и/или столбцов массива указанное количество раз и в указанную сторону." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		int** mtx = nullptr;
		auto row = 10, col = 5;
		mtx_create(mtx, row, col);
		
		cout << "\n\n\t Matrix create: \n\t----------------\n";
		mtx_rand(mtx, row, col, true, 10, 100); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");

		cout << "\n\n\t Add column at index 3: \n\t------------------------\n";
		mtx_add_col(mtx, row, col, 3); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");
		
		cout << "\n\n\t Delete column at index 3: \n\t---------------------------\n";
		mtx_del_col(mtx, row, col, 3); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");
		
		cout << "\n\n\t Right shift by 1: \n\t-------------------\n";
		mtx_shift(mtx, row, col); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");
		
		cout << "\n\n\t Bottom shift by 2: \n\t--------------------\n";
		mtx_shift(mtx, row, col, 'b', 2); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");
		
		cout << "\n\n\t Left shift by 3: \n\t------------------\n";
		mtx_shift(mtx, row, col, 'l', 3); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");
		
		cout << "\n\n\t Top shift by 4: \n\t-----------------\n";
		mtx_shift(mtx, row, col, 't', 4); mtx_echo(mtx, row, col);
		cout << "\n\tExit: "; system("pause");

		for (auto i = 0; i < row; i++) delete[] mtx[i];
		delete[] mtx;
		
	} while (task_restart());
}