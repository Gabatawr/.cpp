#include "Header.h"

void main()
{
	#pragma region Presetting
	
		SetConsoleCP(65001);
		SetConsoleOutputCP(65001);

		srand(time(0));
	
	#pragma endregion
	while (true)
	{
		system("cls"); 
		cout<< "\n ┏━━━━━━━━━━━━━━━━━━━━━━━┓"
			<< "\n ┃   Tasks of week  19   ┃"
			<< "\n ┣━━━━━━━┳━━━━━━━┳━━━━━━━┫"
			<< "\n ┃   1   ┃   2   ┃   3   ┃"
			<< "\n ┗━━━━━━━┻━━━━━━━┻━━━━━━━┛"
			<< "\n\n Enter Task: _\b";

		int choice_menu; cin >> choice_menu;
		if (choice_menu == 0) return;

		void (*ptr_tasks[3])() = { do_task_1, do_task_2, do_task_3 };
		if (1 <= choice_menu && choice_menu <= 3) ptr_tasks[--choice_menu]();
	}
}

