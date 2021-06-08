#include "Header.h"

int uniq_count               (int** arr_A, int row_A, int col_A, int** arr_B, int row_B, int col_B, int** arr_C, int row_C, int col_C);
int* uniq_fill(int size_un_A, int** arr_A, int row_A, int col_A, int** arr_B, int row_B, int col_B, int** arr_C, int row_C, int col_C);

void do_task_2()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 2:\t"
				<< "Есть 3 двумерных массива A, B, C." << "\n\t\t"
				<< "Количество строк и столбцов для них вводит пользователь с клавиатуры для каждого из них." << "\n\t\t"
				<< "Реализуйте:" << "\n\t\t"
				<< " 1. Создайте одномерный массив, который содержит общие значения для A, B, C;" << "\n\t\t"
				<< " 2. Создайте одномерный массив, который содержит уникальные значения для A, B, C;" << "\n\t\t"
				<< " 3. Создайте одномерный массив, который содержит общие значения для A и C;" << "\n\t\t"
				<< " 4. Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		int row_A = 0, col_A = 0, row_B = 0, col_B = 0, row_C = 0, col_C = 0;
		
		row_A = col_A = 5;
		row_B = col_B = 6;
		row_C = col_C = 7;
		
		//Пользовательский ввод
		/* 
		cout << " Enter row A: "; cin >> row_A;
		cout << " Enter col A: "; cin >> col_A;
		cout << " Enter row B: "; cin >> row_B;
		cout << " Enter col B: "; cin >> col_B;
		cout << " Enter row C: "; cin >> row_C;
		cout << " Enter col C: "; cin >> col_C;
		*/
		
		int min = -25, max = 26;

		// Создаем рандомные массивы
		int** arr_A = new int*[row_A];
		for (auto i = 0; i < col_A; i++) {
			arr_A[i] = nullptr;
			arr_create_random(arr_A[i], col_A, false, min, max);
		}
		int** arr_B = new int* [row_B];
		for (auto i = 0; i < col_B; i++) {
			arr_B[i] = nullptr;
			arr_create_random(arr_B[i], col_B, false, min, max);
		}
		int** arr_C = new int* [row_C];
		for (auto i = 0; i < col_C; i++) {
			arr_C[i] = nullptr;
			arr_create_random(arr_C[i], col_C, false, min, max);
		}
		// Выводим
		mtx_echo(arr_A, row_A, col_A); cout << '\n';
		mtx_echo(arr_B, row_B, col_B); cout << '\n';
		mtx_echo(arr_C, row_C, col_C); cout << '\n';

		// Подсчитываем и создаем массив общих чисел для А-В-С
		int size_tmp = 0;
		for (auto ia = 0; ia < row_A; ia++)
		{
			for (auto ja = 0; ja < col_A; ja++)
			{
				for (auto ib = 0; ib < row_B; ib++)
				{
					for (auto jb = 0; jb < col_B; jb++)
					{
						if (arr_A[ia][ja] == arr_B[ib][jb])
						{
							for (auto ic = 0; ic < row_C; ic++)
							{
								for (auto jc = 0; jc < col_C; jc++)
								{
									if (arr_A[ia][ja] == arr_C[ic][jc])
									{
										size_tmp++;
										goto next_A_mut_count;
									}
								}
							}
						}
					}
				}
			next_A_mut_count:;
			}
		}
		int* arr_tmp = new int[size_tmp];
		for (auto ia = 0, it = 0; ia < row_A; ia++)
		{
			for (auto ja = 0; ja < col_A; ja++)
			{
				for (auto ib = 0; ib < row_B; ib++)
				{
					for (auto jb = 0; jb < col_B; jb++)
					{
						if (arr_A[ia][ja] == arr_B[ib][jb])
						{
							for (auto ic = 0; ic < row_C; ic++)
							{
								for (auto jc = 0; jc < col_C; jc++)
								{
									if (arr_A[ia][ja] == arr_C[ic][jc])
									{
										arr_tmp[it++] = arr_A[ia][ja];
										goto next_A_mut_fill;
									}
								}
							}
						}
					}
				}
			next_A_mut_fill:;
			}
		}
		// Подсчитываем копии общих чисел, если есть удаляем из массива
		int copy_count = 0;
		for (auto i = 0; i < size_tmp - 1; i++)
		{
			bool trigger = false;
			for (auto j = i + 1; j < size_tmp; j++)
			{
				if (arr_tmp[i] == arr_tmp[j]) { trigger = true; break; }
			}
			if (trigger) copy_count++;
		}
		int* arr_tmp_old = nullptr;
		if (copy_count != 0)
		{
			arr_tmp_old = arr_tmp;
			size_tmp -= copy_count;
			arr_tmp = new int[size_tmp];
			for (auto i = 0, tmp = 0; i < size_tmp; i++)
			{
				arr_tmp[i] = arr_tmp_old[tmp];
				for (auto j = tmp++ + 1; j < size_tmp + copy_count; j++)
				{
					if (arr_tmp[i] == arr_tmp_old[j]) { i--; break; }
				}
			}
		}
		delete[] arr_tmp_old;
		// Выводим, очищаем память
		cout << " 1."; arr_echo_el(arr_tmp, size_tmp); delete[] arr_tmp;  cout << '\n';
		
		// Подсчитываем и создаем массивы для уникальны чисел
		int size_un_A = uniq_count(arr_A, row_A, col_A, arr_B, row_B, col_B, arr_C, row_C, col_C);
		int size_un_B = uniq_count(arr_B, row_B, col_B, arr_A, row_A, col_A, arr_C, row_C, col_C);
		int size_un_C = uniq_count(arr_C, row_C, col_C, arr_A, row_A, col_A, arr_B, row_B, col_B);
		int* arr_un_A = uniq_fill(size_un_A,arr_A, row_A, col_A, arr_B, row_B, col_B, arr_C, row_C, col_C);
		int* arr_un_B = uniq_fill(size_un_B, arr_B, row_B, col_B, arr_A, row_A, col_A, arr_C, row_C, col_C);
		int* arr_un_C = uniq_fill(size_un_C, arr_C, row_C, col_C, arr_A, row_A, col_A, arr_B, row_B, col_B);
		// Объединаем массивы уникальных элементов А и В массивов, удаляем лишнее
		int size_un_AB = 0; int* arr_un_AB = nullptr;
		arrs_combine_AB(arr_un_A, size_un_A, arr_un_B, size_un_B, arr_un_AB, size_un_AB);
		delete[] arr_un_A; delete[] arr_un_B;
		// Объединаем массивы уникальных элементов АВ и С массивов, удаляем лишнее
		int size_un_ABC = 0; int* arr_un_ABC = nullptr;
		arrs_combine_AB(arr_un_AB, size_un_AB, arr_un_C, size_un_C, arr_un_ABC, size_un_ABC);
		delete[] arr_un_AB; delete[] arr_un_C;
		// Выводим, очищаем память
		cout << " 2."; arr_echo_el(arr_un_ABC, size_un_ABC); delete[] arr_un_ABC; cout << '\n';

		// Подсчитываем и создаем массив общих чисел для А-С
		size_tmp = 0;
		for (auto ia = 0; ia < row_A; ia++)
		{
			for (auto ja = 0; ja < col_A; ja++)
			{
				for (auto ic = 0; ic < row_C; ic++)
				{
					for (auto jc = 0; jc < col_C; jc++)
					{
						if (arr_A[ia][ja] == arr_C[ic][jc])
						{
							size_tmp++;
							goto next_AC_mut_count;
						}
					}
				}
			next_AC_mut_count:;
			}
		}
		arr_tmp = new int[size_tmp];
		for (auto ia = 0, it = 0; ia < row_A; ia++)
		{
			for (auto ja = 0; ja < col_A; ja++)
			{
				for (auto ic = 0; ic < row_C; ic++)
				{
					for (auto jc = 0; jc < col_C; jc++)
					{
						if (arr_A[ia][ja] == arr_C[ic][jc])
						{
							arr_tmp[it++] = arr_A[ia][ja];
							goto next_AC_mut_fill;
						}
					}
				}
			next_AC_mut_fill:;
			}
		}
		// Подсчитываем копии общих чисел, если есть удаляем из массива
		copy_count = 0;
		for (auto i = 0; i < size_tmp - 1; i++)
		{
			bool trigger = false;
			for (auto j = i + 1; j < size_tmp; j++)
			{
				if (arr_tmp[i] == arr_tmp[j]) { trigger = true; break; }
			}
			if (trigger) copy_count++;
		}
		arr_tmp_old = nullptr;
		if (copy_count != 0)
		{
			arr_tmp_old = arr_tmp;
			size_tmp -= copy_count;
			arr_tmp = new int[size_tmp];
			for (auto i = 0, tmp = 0; i < size_tmp; i++)
			{
				arr_tmp[i] = arr_tmp_old[tmp];
				for (auto j = tmp++ + 1; j < size_tmp + copy_count; j++)
				{
					if (arr_tmp[i] == arr_tmp_old[j]) { i--; break; }
				}
			}
		}
		delete[] arr_tmp_old;
		// Выводим, очищаем память
		cout << " 3."; arr_echo_el(arr_tmp, size_tmp); delete[] arr_tmp;  cout << '\n';

		// Подсчитываем и создаем массив общих чисел для А-В-С
		size_tmp = 0;
		for (auto ia = 0; ia < row_A; ia++)
		{
			for (auto ja = 0; ja < col_A; ja++)
			{
				if (arr_A[ia][ja] < 0) size_tmp++;
				if (ia == row_A - 1 && ja == col_A - 1)
				{
					for (auto ib = 0; ib < row_B; ib++)
					{
						for (auto jb = 0; jb < col_B; jb++)
						{
							if (arr_B[ib][jb] < 0) size_tmp++;
							if (ib == row_B - 1 && jb == col_B - 1)
							{
								for (auto ic = 0; ic < row_C; ic++)
								{
									for (auto jc = 0; jc < col_C; jc++)
									{
										if (arr_C[ic][jc] < 0) size_tmp++;
									}
								}
							}
						}
					}
				}
			}
		}
		arr_tmp = new int[size_tmp];
		for (auto ia = 0, it = 0; ia < row_A; ia++)
		{
			for (auto ja = 0; ja < col_A; ja++)
			{
				if (arr_A[ia][ja] < 0) arr_tmp[it++] = arr_A[ia][ja];
				if (ia == row_A - 1 && ja == col_A - 1)
				{
					for (auto ib = 0; ib < row_B; ib++)
					{
						for (auto jb = 0; jb < col_B; jb++)
						{
							if (arr_B[ib][jb] < 0) arr_tmp[it++] = arr_B[ib][jb];
							if (ib == row_B - 1 && jb == col_B - 1)
							{
								for (auto ic = 0; ic < row_C; ic++)
								{
									for (auto jc = 0; jc < col_C; jc++)
									{
										if (arr_C[ic][jc] < 0) arr_tmp[it++] = arr_C[ic][jc];
									}
								}
							}
						}
					}
				}
			}
		}
		// Подсчитываем копии общих чисел, если есть удаляем из массива
		copy_count = 0;
		for (auto i = 0; i < size_tmp - 1; i++)
		{
			bool trigger = false;
			for (auto j = i + 1; j < size_tmp; j++)
			{
				if (arr_tmp[i] == arr_tmp[j]) { trigger = true; break; }
			}
			if (trigger) copy_count++;
		}
		arr_tmp_old = nullptr;
		if (copy_count != 0)
		{
			arr_tmp_old = arr_tmp;
			size_tmp -= copy_count;
			arr_tmp = new int[size_tmp];
			for (auto i = 0, tmp = 0; i < size_tmp; i++)
			{
				arr_tmp[i] = arr_tmp_old[tmp];
				for (auto j = tmp++ + 1; j < size_tmp + copy_count; j++)
				{
					if (arr_tmp[i] == arr_tmp_old[j]) { i--; break; }
				}
			}
		}
		delete[] arr_tmp_old;
		// Выводим, очищаем память
		cout << " 4."; arr_echo_el(arr_tmp, size_tmp); delete[] arr_tmp;  cout << '\n';
		
	} while (task_restart());
}


int uniq_count               (int** arr_A, int row_A, int col_A, int** arr_B, int row_B, int col_B, int** arr_C, int row_C, int col_C)
{
	int size_un_A = 0;
	for (auto ia = 0; ia < row_A; ia++)
	{
		for (auto ja = 0; ja < col_A; ja++)
		{
			for (auto ib = 0; ib < row_B; ib++)
			{
				for (auto jb = 0; jb < col_B; jb++)
				{
					if (arr_A[ia][ja] == arr_B[ib][jb]) goto next_A_no_un_count;
					if (ib == row_B - 1 && jb == col_B - 1)
					{
						for (auto ic = 0; ic < row_C; ic++)
						{
							for (auto jc = 0; jc < col_C; jc++)
							{
								if (arr_A[ia][ja] == arr_C[ic][jc]) goto next_A_no_un_count;
								if (ic == row_C - 1 && jc == col_C - 1) size_un_A++;
							}
						}
					}

				}
			}
		next_A_no_un_count:;
		}
	}
	return size_un_A;
}

int* uniq_fill(int size_un_A, int** arr_A, int row_A, int col_A, int** arr_B, int row_B, int col_B, int** arr_C, int row_C, int col_C)
{
	int* arr_un_A = new int[size_un_A];
	for (auto ia = 0, it = 0; ia < row_A; ia++)
	{
		for (auto ja = 0; ja < col_A; ja++)
		{
			for (auto ib = 0; ib < row_B; ib++)
			{
				for (auto jb = 0; jb < col_B; jb++)
				{
					if (arr_A[ia][ja] == arr_B[ib][jb]) goto next_A_no_un_fill;
					if (ib == row_B - 1 && jb == col_B - 1)
					{
						for (auto ic = 0; ic < row_C; ic++)
						{
							for (auto jc = 0; jc < col_C; jc++)
							{
								if (arr_A[ia][ja] == arr_C[ic][jc]) goto next_A_no_un_fill;
								if (ic == row_C - 1 && jc == col_C - 1) arr_un_A[it++] = arr_A[ia][ja];
							}
						}
					}

				}
			}
		next_A_no_un_fill:;
		}
	}
	return arr_un_A;
}