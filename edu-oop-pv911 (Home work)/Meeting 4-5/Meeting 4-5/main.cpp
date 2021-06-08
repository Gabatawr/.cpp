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
	
	do {
		system("cls");

		std::cout
			<< "\n ┏━━━━━┳━━━━━┓"
			<< "\n ┃  4  ┃  5  ┃"
			<< "\n ┗━━━━━┻━━━━━┛"
			<< "\n Enter Meeting: #_\b";

		int choice_menu;
		std::cin >> choice_menu;

		void (*start[meeting_number])() = { meeting_4, meeting_5 };

		if (4 <= choice_menu && choice_menu <= 5) start[choice_menu - 4]();
		else return 0;

	} while (true);
	
}