#include "Header.h"

#pragma region Technical Functions

bool task_restart()
{
	cout << "\n Restart task? (0 / 1)\n Enter: _\b";
	char u_enter; cin >> u_enter;

	if (u_enter == '1') return true;
	if (u_enter == '0') return false;

	cout << " Invalid command..\n";
	return task_restart();
}

#pragma endregion