#include "Header.h"

void do_task_2()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 2:\t"
				<< "Написать функцию, которая удаляет из строки символ с заданным номером" << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		int str_size = 128;
		
		cout << " Enter string: ";
		char* str = new char[str_size];
		cin >> str; str_cut_trash(str, str_size);
		
		cout << " Enter delete index: _\b";
		int index;
		cin >> index;
		
		str_get(str, str_size, index);
		cout << "\n String after: "; str_echo(str); cout << "\n\n";
		
	} while (task_restart());
}