#include "Header.h"

void len_sort_in_range(char** arr_str, int first, int last)
{
	for (int i = first; i < last; i++)
		for (int j = i + 1; j <= last; j++)
			if (str_compare_length(arr_str[i], arr_str[j]) > 0) {
				char* tmp = arr_str[i];
				arr_str[i] = arr_str[j];
				arr_str[j] = tmp;
			}
}

void qsort_by_letter_index(char** arr_str, int first, int last, int index)
{
	
	int f = first;
	int l = last;
	int mid = arr_str[(f + l) / 2][index];

	while (f < l) {
		while (arr_str[f][index] < mid) f++;
		while (arr_str[l][index] > mid) l--;
		if (f <= l) std::swap(arr_str[f++], arr_str[l--]);
	}
	
	if (first < l) qsort_by_letter_index(arr_str, first, l, index);
	if (f < last) qsort_by_letter_index(arr_str, f, last, index);
}

int last_letter_pos (char** arr_str, int first, int last, int index)
{
	for (int i = first + 1, tmp = arr_str[first][index]; i <= last; i++)
	{
		if (tmp == arr_str[i][index]) continue;
		return i - 1;
	}
	return last;
}

void alph_sort_by_index(char** arr_str, int first, int last, int index)
{
	int f, l = last, ind = index;
	
	qsort_by_letter_index(arr_str, first, last, index);

	last = last_letter_pos(arr_str, first, last, index);
	f = last + 1;
	
	len_sort_in_range(arr_str, first, last);

	index++;
	while (first <= last)
	{
		if (arr_str[first][index] == '\0') { first++; continue; }
		break;
	}

	if (first < last) alph_sort_by_index(arr_str, first, last, index);
	if (f < l) alph_sort_by_index(arr_str, f, l, ind);
}

void alph_sort(char** arr_str, int arr_size, int pos_sym = 0)
{
	for (auto first = 0, last = arr_size - 1, index = pos_sym; first < last; first = last + 1, last = arr_size - 1)
	{
		alph_sort_by_index(arr_str, first, last, index);
		last = last_letter_pos(arr_str, first, last, index);
	}
}

void do_task_1()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 1:\t"
				<< "Написать программу," << "\n\t\t"
				<< "которая дает пользователю ввести 5 фамилий студентов, а затем сортирует их по возрастанию." << "\n"
				<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		// Выдилаем память под массив
		auto size_arr_surnames = 5;
		char** arr_surnames = new char* [size_arr_surnames];

		// Наполняем массив
		cout << "\n Enter 5 surnames of students\n\n";
		for (auto i = 0; i < size_arr_surnames; i++)
		{
			cout << " " << i + 1 << ". ";
			arr_surnames[i] = str_cin();
		}

		// Все буквы в нижний регистр
		for (auto i = 0; i < size_arr_surnames; i++) str_lowercase(arr_surnames[i]);
		
		// Сортируем по алфавиту
		alph_sort(arr_surnames, size_arr_surnames);
		
		// Первую букву в верхний регистр
		for (auto i = 0; i < size_arr_surnames; i++) str_up_begin(arr_surnames[i]);
		
		// Выводим массив
		cout << "\n Surnames of students: { ";
		for (auto i = 0; i < size_arr_surnames; i++)
		{
			cout << "\""; str_echo(arr_surnames[i]);
			if (i < size_arr_surnames - 1) cout << "\", ";
		}
		cout << "\" }";

		// Очистка памяти
		for (auto i = 0; i < size_arr_surnames; i++) delete[] arr_surnames[i];
		delete[] arr_surnames;

		cout << "\n\n";

	} while (task_restart());
}