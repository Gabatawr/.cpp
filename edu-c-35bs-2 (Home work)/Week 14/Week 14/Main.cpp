#include "Header.h"

void main()
{
	#pragma region Presetting
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	srand(time(0));

	char u_enter;
	#pragma endregion
	
	while (true)
	{
		system("cls"); 
		cout<< "\n ┏━━━━━━━━━━━━━━━━━━━┓"
			<< "\n ┃  Tasks of week 14 ┃"
			<< "\n ┣━━━┳━━━┳━━━┳━━━┳━━━┫"
			<< "\n ┃ 1 ┃ 2 ┃ 3 ┃ 4 ┃ 5 ┃"
			<< "\n ┣━━━┻━━━┻━━━╋━━━┻━━━┫"
			<< "\n ┃░░░░░░░░░░░┃exit[0]┃"
			<< "\n ┗━━━━━━━━━━━┻━━━━━━━┛"
			<< "\n\n Enter Task: _\b";
		cin >> u_enter;

		switch (u_enter) 
		{
			case '1': start_task_1();
			break;

			case '2': start_task_2();
			break;

			case '3': start_task_3();
			break;

			case '4': start_task_4();
			break;

			case '5': start_task_5();
			break;

			case '0': return;

			default:
			cout << " Invalid command. ";
			system("pause");
		}
	}
}

