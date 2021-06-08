#include "Header.h"

void do_task_4()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 4:\t"
				<< "Транспонирование матрицы:" << "\n\t\t"
				<< "Операция после которой столбцы прежней матрицы становятся строками, а строки столбцами." << "\n\n\t\t"
				<< "Напишите функцию транспонирования матрицы." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		int** mtx = nullptr;
		auto row = 10, col = 5;
		mtx_create(mtx, row, col);

		cout << "\n\n\t Matrix create: \n\t----------------\n";
		mtx_rand(mtx, row, col, true, 10, 100); mtx_echo(mtx, row, col);
		cout << "\n\tNext: "; system("pause");

		cout << "\n\n\t After transpose: \n\t------------------\n";
		mtx_transpose(mtx, row, col); mtx_echo(mtx, row, col);
		cout << "\n\tExit: "; system("pause");

		cout << "\n\n\t Transpose again: \n\t------------------\n";
		mtx_transpose(mtx, row, col); mtx_echo(mtx, row, col);
		cout << "\n\tExit: "; system("pause");
		
		for (auto i = 0; i < row; i++) delete[] mtx[i];
		delete[] mtx;
		
	} while (task_restart());
}