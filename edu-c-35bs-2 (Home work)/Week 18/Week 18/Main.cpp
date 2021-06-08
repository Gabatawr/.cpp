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
			<< "\n ┃    Tasks of week 18   ┃"
			<< "\n ┣━━━━━┳━━━━━┳━━━━━┳━━━━━┫"
			<< "\n ┃  1  ┃  2  ┃  3  ┃  4  ┃"
			<< "\n ┗━━━━━┻━━━━━┻━━━━━┻━━━━━┛"
			<< "\n\n Enter Task: _\b";

		int choice; cin >> choice;
		if (choice == 0) return;

		void (*ptr_tasks[4])() = { do_task_1, do_task_2, do_task_3, do_task_4 };
		if (1 <= choice && choice <= 4) ptr_tasks[--choice]();
	}
}

