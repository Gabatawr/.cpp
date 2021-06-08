#include "Header.h"

void do_task_7()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 7:\t"
				<< "Пользователь вводит строку." << "\n\t\t"
				<< "Определить количество букв, количество цифр и количество" << "\n\t\t"
				<< "остальных символов, присутствующих в строке." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int str_size = 128;
		
		cout << " Enter string: ";
		char* str = new char[str_size];
		cin >> str; str_cut_trash(str, str_size);

		int digits = str_count_digits(str);
		int letters = str_count_letters(str);

		cout << "\n Counted: [" << digits << "] digits, [" << letters << "] letters and [" << str_len(str, str_size) - digits - letters << "] other symbols\n\n";
		
	} while (task_restart());
}