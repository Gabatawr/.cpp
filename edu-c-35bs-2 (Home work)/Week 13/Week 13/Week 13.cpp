/**
 * Week 13
 *
 * Theme:
 *   Функции. Перегрузка функций. Рекурсия.
 *
 * @author Artem Kashyrin
 *
*/

#include "my-lib_of_week-13.h"

void main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand(time(0));

	while (true)
	{
		system("cls");

		cout << endl;
		cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		cout << " ┃    Tasks of week 13    ┃" << endl;
		cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout << " ┃ Task 1\t\t  ┃" << endl;
		cout << " ┃ Task 2\t\t  ┃" << endl;
		cout << " ┃ Task 3\t\t  ┃" << endl;
		cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout << " ┃ 0 - exit\t\t  ┃" << endl;
		cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

		cout << "\n Enter Task: #_\b";
		char u_enter;
		cin >> u_enter;

		switch (u_enter) {

		case '3':
			do {
				system("cls");
				// description
				cout << "\n     Task 3:\t"
					<< "Написать игру «Крестики-нолики». " << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				start_XO_Game();
			} while (restart_task());
			break;

		case '2':
			do {
				system("cls");
				// description
				cout << "\n     Task 2:\t"
					<< "Написать игру «Пятнашки»." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				start_pGame();
			} while (restart_task());
			break;

		case '1':
			do {
				system("cls");
				// description
				cout << "\n     Task 1:\t"
					<< "Дана шахматная доска размером 8×8 и шахматный конь." << "\n\t\t"
					<< "Программа должна запросить у пользователя координаты клетки поля и поставить туда коня." << "\n\t\t"
					<< "Задача программы найти и вывести путь коня, при котором он обойдет все клетки доски," << "\n\t\t"
					<< "становясь в каждую клетку только один раз. В программе необходимо использовать рекурсию." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				int pos_x, pos_y;
				
				do {
					cout << " Enter start position 1..8: X\b";
					cin >> pos_x;
				} while (pos_x < 1 || pos_x > 8);
				
				do {
					cout << " Enter start position 1..8: Y\b";
					cin >> pos_y;
				} while (pos_x < 1 || pos_x > 8);
				
				cout << "\n Start: ";
				system("pause");

				start_horse_journey(--pos_y, --pos_x);
				
			} while (restart_task());
			break;

		case '0':
			return;

		default:
			cout << " Invalid command. ";
			system("pause");
			break;
		}
	}
}
