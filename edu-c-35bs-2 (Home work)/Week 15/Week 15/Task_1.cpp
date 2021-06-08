#include "Header.h"

int Action(int* arr, int arr_size, int (*optional)(int*, int))
{
	if (optional == nullptr) return int(arr_avg(arr, arr_size));
	return optional(arr, arr_size);
}

void do_task_1()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 1:\t"
				<< "Написать программу, которая содержит функцию Action, принимающую в качестве аргумента," << "\n\t\t"
				<< "указатели на два массива (А и В) и размеры массивов, а также указатель на функцию." << "\n\n\t\t"

				<< "Пользователю отображается меню, в котором он может выбрать max, min, avg:" << "\n\t\t"
				<< " - eсли выбран max — передается указатель на функцию, которая ищет максимум," << "\n\t\t"
				<< " - если выбран min — передается указатель на функцию, которая ищет минимум," << "\n\t\t"
				<< " - если выбран avg — передается указатель на функцию, которая ищет среднее." << "\n\n\t\t"

				<< "Возвращаемое значение функции Action результат выбора пользователя max, min, avg." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int arr_a_size; cout << "\n Size array A: _\b"; cin >> arr_a_size;
		int* arr_a = nullptr; arr_create_random(arr_a, arr_a_size);
		cout << " A:"; arr_echo_el(arr_a, arr_a_size); cout << "\n";

		int arr_b_size; cout << "\n Size array B: _\b"; cin >> arr_b_size;
		int* arr_b = nullptr; arr_create_random(arr_b, arr_b_size);
		cout << " B:"; arr_echo_el(arr_b, arr_b_size); cout << "\n";

		int (*calculate[3])(int*, int) = { arr_min, arr_max, nullptr }; // nullptr - because type arr_avg = double

		int choice; cout << "\n Calculate[ min(0) | max(1) | avg(2) ] Enter: _\b"; cin >> choice;

		cout << "\n Array A: " << Action(arr_a, arr_a_size, calculate[choice]);
		cout << "\n Array B: " << Action(arr_b, arr_b_size, calculate[choice]) << "\n";

	} while (task_restart());
}