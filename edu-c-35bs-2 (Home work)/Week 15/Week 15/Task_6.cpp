#include "Header.h"

void do_task_6()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 6:\t"
				<< "Пользователь вводит строку символов и искомый символ," << "\n\t\t"
				<< "посчитать сколько раз он встречается в строке." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int str_size = 128;
		
		cout << " Enter string: ";
		char* str = new char[str_size];
		cin >> str; str_cut_trash(str, str_size);

		cout << " Enter count symbol: '_'\b\b";
		char symbol;
		cin >> symbol;
		
		cout << "\n Counted [" << str_symbol_count(str, str_size, symbol) << "] '" << symbol << "'\n\n";
		
	} while (task_restart());
}