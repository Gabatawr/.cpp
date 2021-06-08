#include "Header.h"

void do_task_3()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 3:\t"
				<< "Написать функцию, которая удаляет из строки все вхождения в нее заданного символа." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int str_size = 128;
		
		cout << " Enter string: ";
		char* str = new char[str_size];
		cin >> str; str_cut_trash(str, str_size);
		
		cout << " Enter delete symbol: '_'\b\b";
		char symbol;
		cin >> symbol;
		
		str_symbol_delete(str, str_size, symbol);
		cout << "\n String after: "; str_echo(str); cout << "\n\n";
		
	} while (task_restart());
}