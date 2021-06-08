#include "Header.h"

#pragma region Technical Functions
bool task_restart()
{
	cout << "\n Restart task? (0 / 1)\n Enter: _\b";
	char u_enter; cin >> u_enter;

	if (u_enter == '1') return true;
	if (u_enter == '0') return false;

	cout << " Invalid command..\n";
	return task_restart();
}
#pragma endregion

#pragma region Task 1
void start_task_1() {
	do {
		system("cls");
		cout << "\n     Task 1:\t"
			<< "Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры)." << "\n\t\t"
			<< "Необходимо создать третий массив минимально возможного размера, в котором" << "\n\t\t"
			<< "нужно собрать элементы массива A, которые не включаются в массив B, без повторений." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";

		int arr_a_size; cout << " Array A size: "; cin >> arr_a_size;
		int* arr_a = nullptr; arr_create_random(arr_a, arr_a_size, false, 1, arr_a_size);
		cout << " A:"; arr_quick_sort(arr_a, 0, arr_a_size - 1); arr_echo_el(arr_a, arr_a_size);

		int arr_b_size; cout << "\n\n Array B size: "; cin >> arr_b_size;
		int* arr_b = nullptr; arr_create_random(arr_b, arr_b_size, false, 1, arr_b_size);
		cout << " B:"; arr_quick_sort(arr_b, 0, arr_b_size - 1); arr_echo_el(arr_b, arr_b_size);

		int arr_c_size; int* arr_c = nullptr;
		arrs_unique_to_A(arr_a, arr_a_size, arr_b, arr_b_size, arr_c, arr_c_size);
		
		cout << "\n\n Array C size: " << arr_c_size << "\n C:"; arr_quick_sort(arr_c, 0, arr_c_size - 1); arr_echo_el(arr_c, arr_c_size); cout << "\n";

		arr_delete(arr_a, arr_b, arr_c);

	} while (task_restart());
}
#pragma endregion

#pragma region Task 2
void start_task_2() {
	do {
		system("cls");
		cout << "\n     Task 2:\t"
			<< "Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры)." << "\n\t\t"
			<< "Необходимо создать третий массив минимально возможного размера, в котором" << "\n\t\t"
			<< "нужно собрать элементы массивов A и B, которые не являются общими для них, без повторений." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		int arr_a_size; cout << " Array A size: "; cin >> arr_a_size;
		int* arr_a = nullptr; arr_create_random(arr_a, arr_a_size, false, 1, arr_a_size * 2);
		cout << " A:"; arr_quick_sort(arr_a, 0, arr_a_size - 1); arr_echo_el(arr_a, arr_a_size);

		int arr_b_size; cout << "\n\n Array B size: "; cin >> arr_b_size;
		int* arr_b = nullptr; arr_create_random(arr_b, arr_b_size, false, 1, arr_b_size * 2);
		cout << " B:"; arr_quick_sort(arr_b, 0, arr_b_size - 1); arr_echo_el(arr_b, arr_b_size);

		int arr_au_size; int* arr_au = nullptr;
		arrs_unique_to_A(arr_a, arr_a_size, arr_b, arr_b_size, arr_au, arr_au_size);

		int arr_bu_size; int* arr_bu = nullptr;
		arrs_unique_to_A(arr_b, arr_b_size, arr_a, arr_a_size, arr_bu, arr_bu_size);

		int arr_c_size; int* arr_c = nullptr;
		arrs_combine_AB(arr_au, arr_au_size, arr_bu, arr_bu_size, arr_c, arr_c_size);

		cout << "\n\n Array C size: " << arr_c_size << "\n C:"; arr_quick_sort(arr_c, 0, arr_c_size - 1); arr_echo_el(arr_c, arr_c_size); cout << "\n";

		arr_delete(arr_a, arr_b, arr_au, arr_bu, arr_c);

	} while (task_restart());
}
#pragma endregion

#pragma region Task 3
void start_task_3() {
	do {
		system("cls");
		cout << "\n     Task 3:\t"
			<< "Написать следующие функции для работы с динамическим массивом:" << "\n\t\t"
			<< " ? Функция распределения динамической памяти." << "\n\t\t"
			<< " + Функция инициализации динамического массива." << "\n\t\t"
			<< " + Функция печати динамического массива." << "\n\t\t"
			<< " + Функция удаления динамического массива." << "\n\t\t"
			<< " + Функция добавления элемента в конец массива." << "\n\t\t"
			<< " + Функция вставки элемента по указанному индексу." << "\n\t\t"
			<< " + Функция удаления элемента по указанному индексу." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";

		cout << " Implementation of these functions and many others, in the \"Array_libMY.h\" file.\n";

	} while (task_restart());
}
#pragma endregion

#pragma region Task 4

// Return only: flag(true) - prime numbers; flag(false) - composite number.
void prime_numbers(int*& arr, int& arr_size, bool flag)
{
	for (auto i = 0; i < arr_size; i++)
	{	
		bool is_prime = true;
		for(auto j = 1; j < arr[i]; j++)
		{
			if(arr[i] != 2 && (arr[i] % j == 0 && (j != 1 || j == arr[i])))
			{
				is_prime = false;
				break;
			}
			if (j > 2) j++;
		}
		if (flag && (!is_prime || arr[i] == 1)) arr_el_get(arr, arr_size, i--);
		if (!flag && (is_prime || arr[i] == 1)) arr_el_get(arr, arr_size, i--);
	}
}

void start_task_4() {
	do {
		system("cls");
		cout << "\n     Task 4:\t"
			<< "Написать функцию, которая получает указатель на динамический массив и его размер." << "\n\t\t"
			<< "Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		int arr_size; cout << " Enter array size: "; cin >> arr_size;
		
		int* arr = nullptr; arr_create_random(arr, arr_size, true, 1, arr_size + 1);
		cout << " You array before:"; arr_echo_el(arr, arr_size);

		cout << "\n\n Note, \"1\" is not a prime number and is not a composite number.";
		bool flag; cout << "\n Return only numbers [prime(1)/composite(0)] Enter: _\b"; cin >> flag;

		prime_numbers(arr, arr_size, flag);
		cout << "\n You array after: "; arr_echo_el(arr, arr_size); cout << "\n";

		delete[] arr;

	} while (task_restart());
}

#pragma endregion

#pragma region Task 5

// [Negative Zero Positive]_sort by arrays
void NZP_sort(const int* arr, const int arr_size, int*& arr_n, int& arr_n_size, int*& arr_z, int& arr_z_size, int*& arr_p, int& arr_p_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] < 0) arr_n_size++;
		else if (arr[i] == 0) arr_z_size++;
		else arr_p_size++;
	}
	
	arr_n = new int[arr_n_size];
	arr_z = new int[arr_z_size];
	arr_p = new int[arr_p_size];

	for (int i = 0, count_n = arr_n_size, count_z = arr_z_size, count_p = arr_p_size; i < arr_size; i++)
	{
		if (arr[i] < 0) arr_n[--count_n] = arr[i];
		else if (arr[i] == 0) arr_z[--count_z] = arr[i];
		else arr_p[--count_p] = arr[i];
	}
}

void start_task_5() {
	do {
		system("cls");
		cout << "\n     Task 5:\t"
			<< "Написать функцию, которая получает указатель на статический массив и его размер." << "\n\t\t"
			<< "Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		int arr_size; cout << " Enter array size: "; cin >> arr_size;

		int* arr = nullptr; arr_create_random(arr, arr_size, false, arr_size * -1, arr_size + 1);
		cout << "\n Before: "; arr_echo_el(arr, arr_size);

		int arr_n_size = 0; int* arr_n = nullptr;
		int arr_z_size = 0; int* arr_z = nullptr;
		int arr_p_size = 0; int* arr_p = nullptr;
		
		NZP_sort(arr, arr_size, arr_n, arr_n_size, arr_z, arr_z_size, arr_p, arr_p_size);

		cout << "\n\n After:\t"; arr_echo_el(arr_n, arr_n_size); arr_echo_el(arr_z, arr_z_size); arr_echo_el(arr_p, arr_p_size); cout << "\n";

		arr_delete(arr, arr_n, arr_z, arr_p);
		
	} while (task_restart());
}
#pragma endregion