#include "header.h"

int main()
{
#pragma region Presetting

	// randomization
	srand(time(0));

	// encoding
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	// variables
	int const meeting_number = 2;

#pragma endregion

#pragma region Description
	
	/**
	 * Тема: динамические структуры данных — очередь, очередь с приоритетами.
	 */
	
#pragma endregion

	do {
		system("cls");

		std::cout
			<< "\n ┏━━━━━┳━━━━━┓"
			<< "\n ┃  1  ┃  2  ┃"
			<< "\n ┗━━━━━┻━━━━━┛"
			<< "\n Enter Task: #_\b";

		int choice_menu;
		std::cin >> choice_menu;

		void (*start[meeting_number])() = { task_1, task_2 };

		if (1 <= choice_menu && choice_menu <= 2) start[choice_menu - 1]();
		else return 0;

	} while (true);
	
}