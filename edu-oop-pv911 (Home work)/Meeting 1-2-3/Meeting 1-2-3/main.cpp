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
	int const meeting_number = 3;

#pragma endregion

	do {
		system("cls");

		std::cout
			<< "\n  ┏━━━━━┳━━━━━┳━━━━━┓"
			<< "\n  ┃  1  ┃  2  ┃  3  ┃"
			<< "\n  ┗━━━━━┻━━━━━┻━━━━━┛"
			<< "\n   Enter Meeting: #_\b";

		int choice_menu;
		std::cin >> choice_menu;

		void (*start[meeting_number])() = { meeting_1, meeting_2, meeting_3 };

		if (1 <= choice_menu && choice_menu <= meeting_number) start[choice_menu - 1]();
		else return 0;

	} while (true);
}