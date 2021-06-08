/**
 * Week 6
 *
 * Theme:
 *   Циклы.
 *
 * @author Artem Kashyrin
 *
*/

#include <iostream>
#include <windows.h>

using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool useMenu = true;

	do {
		// used in all case 
		char userChoice;
		char taskAgain;
		int userEnter;
		bool useMenuTask = true;
		bool useTask = true;
		bool repiatCommand = false;

		cout << "\n\n|-----------------------" << "|" << endl;
		cout << "|\tMain Menu\t|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| 1 - Homework 1\t" << "|" << endl;
		cout << "| 2 - Homework 2\t" << "|" << endl;
		cout << "| 3 - Bonus tasks\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| 0 or q - exit\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "\n Enter: ";
		cin >> userChoice;

		switch (userChoice) {

		case '3': // Bonus tasks
			while (useMenuTask) {
				cout << "\n\n|-----------------------" << "|" << endl;
				cout << "|    Bonus tasks\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 1 - Butterfly\t\t" << "|" << endl;
				cout << "| 2 - Sandglass\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\n Enter Task: #";
				cin >> userChoice;

				switch (userChoice) {

				case '2': // Sandglass
					//Task description

					do {
						//Variables
						int row;

						//Body
						cout << "\n Enter the odd number of rows: ";
						cin >> row;

						if (row % 2 == 0) {
							cout << " Error, need an odd number (rows = " << row + 1 << ").";
							row++;
						}

						if (row < 5) {
							cout << " At least 5 rows for correct display (rows = 5).";
							row = 5;
						}

						cout << endl << endl;

						for (int r = 1; r <= row - (row / 2 - 0.5); r++) {
							for (int st = 2; st <= r; st++) {
								cout << " ";
							}
							for (int sp = row - 2 * r; sp > -2; sp--) {
								cout << "*";
							}
							for (int st = 1; st <= r && st < row / 2 + 0.5; st++) {
								cout << " ";
							}
							cout << endl;
						}

						for (int r = 1; r <= row - (row / 2 + 0.5); r++) {
							for (int st = row / 2; st >= r+1; st--) {
								cout << " ";
							}
							for (int sp = -1; sp <= r * 2 - 0.5; sp++) {
								cout << "*";
							}
							for (int st = row / 2; st >= r; st--) {
								cout << " ";
							}
							cout << endl;
						}

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << " Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '1': // Butterfly
					//Task description

					do {
						//Variables
						int row;

						//Body
						cout << "\n Enter the odd number of rows: ";
						cin >> row;

						if (row % 2 == 0) {
							cout << " Error, need an odd number (rows = " << row+1 << ").";
							row++;
						}
						
						if (row < 5) {
							cout << " At least 5 rows for correct display (rows = 5).";
							row = 5;
						} 
						
						cout << endl << endl;

						for (int r = 1; r <= row - (row / 2 - 0.5); r++) {
							for (int st = 1; st <= r; st++) {
								cout << "*";
							}
							for (int sp = row - 2 * r; sp > 0; sp--) {
								cout << " ";
							}
							for (int st = 1; st <= r && st < row / 2 + 0.5; st++) {
								cout << "*";
							}
							cout << endl;
						}

						for (int r = 1; r <= row - (row / 2 + 0.5); r++) {
							for (int st = row / 2; st >= r; st--) {
								cout << "*";
							}
							for (int sp = 1; sp <= r * 2 - 0.5; sp++) {
								cout << " ";
							}
							for (int st = row / 2; st >= r; st--) {
								cout << "*";
							}
							cout << endl;
						}

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << " Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case 'b':
				case 'B':
				case '0':
					useMenuTask = false;
					break;

				default:
					cout << " Repiat command " << endl;
					break;
				}
			}
			break;

		case '2': // Week tasks
			while (useMenuTask) {
				cout << "\n\n|-----------------------" << "|" << endl;
				cout << "|      Homework 2\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 1 - Task 2.1\t\t" << "|" << endl;
				cout << "| 2 - Task 2.2\t\t" << "|" << endl;
				cout << "| 3 - Task 2.3\t\t" << "|" << endl;
				cout << "| 4 - Task 2.4\t\t" << "|" << endl;
				cout << "| 5 - Task 2.5\t\t" << "|" << endl;
				cout << "| 6 - Task 2.6\t\t" << "|" << endl;
				cout << "| 7 - Task 2.7\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\n Enter Task: #";
				cin >> userChoice;

				switch (userChoice) {

				case '7': // Task 2.7
					//Task description
					cout << "\n Пользователь вводит два целых числа. Необходимо вывести все целые числа, на которые оба введенных числа делятся без остатка.\n";

					do {
						//Variables
						int a, b, count = 0;

						//Body
						cout << "\n Enter \"A\" then \"B\"\n";
						cin >> a >> b;
						cout << endl;

						for (int c = 1; c <= a && c <= b; c++) {
							if (a % c == 0 && b % c == 0) {
								cout << " " << c;
								count++;
							}
						}
						cout << "\n Found " << count << " numbers" << endl;
						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '6': // Task 2.6
					//Task description
					cout << "\n Пользователь вводит целое число. Необходимо вывести все целые числа, на которое заданное число делиться без остатка.\n";

					do {
						//Variables
						int a, count = 0;

						//Body
						cout << "\n Enter A: ";
						cin >> a;
						cout << endl;
						for (int b = 1; b <= a; b++) {
							if (a % b == 0) {
								cout << " " << b;
								count++;
							}
						}
						cout << "\n Found " << count << " numbers" << endl;

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '5': // Task 2.5
					//Task description
					cout << "\n Пользователь вводит целое число А. Программа должна определить, что куб суммы цифр этого числа равен А*А.\n";

					do {
						//Variables
						int a, b = 0, c;

						//Body
						cout << "\n Enter A: ";
						cin >> a;

						c = a;
						while (c > 0) {
							b = b + c % 10;
							c /= 10;
						}
						if (a * a == b * b * b) {
							cout << " Yes!\n";
						}
						else {
							cout << " No..\n";
						}

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '4': // Task 2.4
					//Task description
					cout << "\n Пользователь вводит любое целое число А. Необходимо вывести все целые числа В, для которых А делиться без остатка на В*В и не делиться без остатка на В*В*В.\n";

					do {
						//Variables
						int a, count = 0;

						//Body
						cout << "\n Enter A: ";
						cin >> a;

						cout << endl;
						for (int b = 1; b * b <= a && b < 65536; b++) { //at b >= 65536 an error, I don’t know why
							if (a % (b * b) == 0 && a % (b * b * b) != 0) {
								cout << " " << b;
								count++;
							}
						}
						if (count > 0) {
							cout << "\n " << count << " numbers found";
						}
						else {
							cout << " No numbers found";
						}

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '3': // Task 2.3
					//Task description
					cout << "\n Пользователь вводит любое целое число. Необходимо из этого целого числа удалить все цифры 3 и 6 и вывести обратно на экран.\n";

					do {
						//Variables
						unsigned long long int n, tmp = 1;

						//Body
						cout << "\n Enter number: ";
						cin >> n;

						while (n > 0) { //invern number and del 3 && 6
							if (n % 10 != 3 && n % 10 != 6) {
								tmp *= 10;
								tmp += n % 10;
							}
							n = n / 10;
						}

						while (tmp >= 10) { //inver number to normal
							n *= 10;
							n += tmp % 10;

							tmp /= 10;
						}

						cout << "\n Total number: " << n;

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '2': // Task 2.1
					//Task description
					cout << "\n Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых все цифры разные.\n";

					do {
						//Variables
						int a1, a2, a3, count, n;

						//Body
						cout << "\n Integers not having the identical numbers:" << endl;

						for (count = 0, n = 100; n < 1000; n++) {

							a3 = n % 10;
							a2 = (n % 100) / 10;
							a1 = (n % 1000) / 100;

							if (a1 != a2 && a1 != a3 && a2 != a3) {
								count++;
								cout << n << " ";
							}
						}

						cout << "\n\n Total " << count << " numbers found";

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '1': // Task 2.1
					//Task description
					cout << "\n Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых есть две одинаковые цифры.\n";

					do {
						//Variables
						int a1, a2, a3, count, n;

						//Body
						cout << "\n Integers having two identical numbers:" << endl;

						for (count = 0, n = 100; n < 1000; n++) {

							a3 = n % 10;
							a2 = (n % 100) / 10;
							a1 = (n % 1000) / 100;

							if (a1 == a2 && a1 != a3 || a1 == a3 && a1 != a2 || a2 == a3 && a2 != a1) {
								count++;
								cout << n << " ";
							}
						}

						cout << "\n\n Total " << count << " numbers found";

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case 'b':
				case 'B':
				case '0':
					useMenuTask = false;
					break;
				default:
					cout << " Repiat command " << endl;
					break;
				}
			}
			break;

		case '1': // Week tasks
			while (useMenuTask) {
				cout << "\n\n|-----------------------" << "|" << endl;
				cout << "|      Homework 1\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 1 - Task 1.1\t\t" << "|" << endl;
				cout << "| 2 - Task 1.2\t\t" << "|" << endl;
				cout << "| 3 - Task 1.3\t\t" << "|" << endl;
				cout << "| 4 - Task 1.4\t\t" << "|" << endl;
				cout << "| 5 - Task 1.5\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\n Enter Task: #";
				cin >> userChoice;

				switch (userChoice) {

				case '5': // Task 5
					//Task description
					cout << "\n Написать программу, которая выводит на экран таблицу умножения на k.\n";

					do {
						//Variables
						int k, s;

						//Body
						cout << "\n Enter k: ";
						cin >> k;
						cout << endl;

						for (int i = 1; i <= 10; i++) {
							s = k * i;
							cout << k << " * " << i << " = " << s << endl;
						}
						
						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '4': // Task 4
					//Task description
					cout << "\n Найти произведение всех целых чисел от a до 20.\n";

					do {
						//Variables
						int a;
						long long int c = 1;

						//Body
						cout << "\n Enter a: " << endl;
						cin >> a;

						if (1 <= a && a <= 20) {
							for (int i = 20; i >= a; i--) {
								c *= i;
							}
							cout << " Total = " << c << endl;
						}
						else {
							cout << " a - incorrect (1 <= a <= 20)" << endl;
						}
						
						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '3': // Task 3
					//Task description
					cout << "\n Найти среднее арифметическое всех целых чисел от 1 до 1000.\n";

					do {
						//Variables
						double a = 0;

						//Body
						for (int i = 1; i <= 1000; i++) {
							a += i;
						}
						cout << " Average = " << a/1000 << endl;

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '2': // Task 2
					//Task description
					cout << "\n Напишите программу, которая запрашивает два целых числа x и y, после чего вычисляет и выводит значение x в степени y.\n";

					do {
						//Variables
						int x, y;

						//Body
						cout << "\n Enter \"x\" and then \"y\": " << endl;
						cin >> x >> y;

						for (int i = x; y > 1; y--) {
							x *= i;
						}
						cout << " x^y = " << x << endl;

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case '1': // Task 1
					//Task description
					cout << "\n Напишите программу, которая вычисляет сумму целых чисел от а до 500.\n";

					do {
						//Variables
						int a, c = 0, count = 0;

						//Body
						cout << "\n Enter a: " << endl;
						cin >> a;

						for (int b = 500; a < b; a++, b--) {
							c += a + b;
							count++;
						}

						cout << " Steps = " << count << "; Sum = " << c << endl;

						//Return?
						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\n Enter: ";
							cin >> taskAgain;
							if (taskAgain == 'y' || taskAgain == 'Y') {
								repiatCommand = false;
							}
							else if (taskAgain == 'n' || taskAgain == 'N') {
								useTask = false;
								repiatCommand = false;
							}
							else {
								cout << " Repiat command " << endl;
								repiatCommand = true;
							}
						} while (repiatCommand);
					} while (useTask);
					break;

				case 'b':
				case 'B':
				case '0':
					useMenuTask = false;
					break;
				default:
					cout << " Repiat command " << endl;
					break;
				}
			}
			break;

		case 'q':
		case 'Q':
		case '0':
			useMenu = false;
			break;

		default:
			cout << " Repiat command " << endl;
			break;
		}
	} while (useMenu);

	system("pause");
	return;
}