#include "Header.h"

void do_task_5()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 5:\t"
				<< "Написать программу, которая заменяет все символы точки «.»" << "\n\t\t"
				<< "в строке, введенной пользователем, на символы восклицательного знака «!»" << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int str_size = 128;
		
		cout << " Enter string: ";
		char* str = new char[str_size];
		cin >> str; str_cut_trash(str, str_size);
		
		str_symbol_replace(str, '.', '!');
		cout << "\n String after: "; str_echo(str); cout << "\n\n";
		
	} while (task_restart());
}