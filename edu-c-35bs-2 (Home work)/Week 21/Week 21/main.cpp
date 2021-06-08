/**
 * Week 21
 *
 * Theme:
 *    Files
 *
 * @author Artem Kashyrin
 *
*/

#include <windows.h>
#include <iostream>
#include <cstdlib>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	while (true)
	{
		system("cls");
		std::cout
			<< "\n ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"
			<< "\n ┃     Tasks of week  21     ┃"
			<< "\n ┣━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┫"
			<< "\n ┃ 1 ┃ 2 ┃ 3 ┃ 4 ┃ 5 ┃ 6 ┃ 7 ┃"
			<< "\n ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛"
			<< "\n\n Enter Task: _\b";

		int choice_menu;
		std::cin >> choice_menu;
		if (choice_menu == 0) return 0;

		void (*ptr_tasks[7])() = { task_1, task_2, task_3, task_4, task_5, task_6, task_7 };
		if (1 <= choice_menu && choice_menu <= 7) ptr_tasks[--choice_menu]();
	}
}

bool task_restart()
{
	std::cout << "\n Restart task? (0 / 1)\n Enter: _\b";
	char u_enter; std::cin >> u_enter;

	if (u_enter == '1') return true;
	if (u_enter == '0') return false;

	std::cout << " Invalid command..\n";
	return task_restart();
}