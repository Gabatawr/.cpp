#include <iostream>

bool restart()
{
	std::cout << "\n Restart[y/n] _\b";
	char choice; std::cin >> choice;

	if (choice == 'y' || choice == 'Y') return true;
	if (choice == 'n' || choice == 'N') return false;

	std::cout << " Invalid command..\n"; return restart();
}
