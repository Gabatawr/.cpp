#include "Header.h"

void do_task_4()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 4:\t"
				<< "Написать функцию, которая вставляет в строку в указанную позицию заданный символ." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int str_size = 128;
		
		cout << " Enter string: ";
		char* str = new char[str_size];
		cin >> str; str_cut_trash(str, str_size);

		cout << "\n Enter insert symbol: '_'\b\b";
		char symbol;
		cin >> symbol;
		
		cout << "\n Enter insert index: _\b";
		int index;
		cin >> index;
		
		str_put(str, str_size, symbol, index);
		cout << "\n String after: "; str_echo(str); cout << "\n\n";
		
	} while (task_restart());
}