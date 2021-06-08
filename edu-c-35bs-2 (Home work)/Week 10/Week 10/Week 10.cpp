/**
 * Week 10
 *
 * Theme:
 *   Многомерные массивы.
 *
 * @author Artem Kashyrin
 *
*/

#include <iostream>
#include <windows.h>

#include <iomanip>

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));
	
	bool useMenu = true;

	do {
		// used in all
		char userChoice;
		char taskAgain;
		bool useTask = true;
		bool repeatCommand;

		system("cls");
		
		cout << "\n|-----------------------" << "|" << endl;
		cout << "|    Tasks of week 10\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| Task 1\t\t" << "|" << endl;
		cout << "| Task 2\t\t" << "|" << endl;
		cout << "| Task 3\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| 0 or q - exit\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "\n Enter Task: #";
		cin >> userChoice;

		switch (userChoice) {

		case '3':
			do {
				system("cls");
				
				// Variables
				const auto arr_size = 10;
				int arr_rand[arr_size][arr_size] = {};
				int q = 0;
				char d = ' ';
				int temp;
				int count_iterations = 0;

				// Body
				for (int i = 0; i < arr_size; i++) {
					for (int j = 0; j < arr_size; j++) {
						arr_rand[i][j] = rand() % 100 + 1;
						for (int x = 0; x < i; x++) {
							for (int y = 0; y < arr_size; y++) {
								if (arr_rand[i][j] == arr_rand[x][y]) {
									arr_rand[i][j] = rand() % 100 + 1;
									x = -1;
									break;
								}
							}
						}
					}
				}
				
				do {
					system("cls");

					// Task description
					cout << "\n     Task 3:\t"
						<< "Создайте двухмерный массив. Заполните его случайными числами и покажите на экран." << "\n\t\t"
						<< "Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз)." << "\n\t\t"
						<< "Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический." << "\n"
						<< "_____________________________________________________________________________________________________________" << "\n\n";

					// output -----------------------------------------------------------------------------------------------------------------
					{
						const auto digit_size = 3; // max digits in number

						cout << "\n     " << setfill('-') << setw((3 + digit_size) * arr_size + 1) << "" << "\n    "; // header column line ---
						for (int i = 0; i < arr_size; i++) {
							cout << " | " << setw(digit_size / 2) << setfill(' ') << "" << i << setw(digit_size / 2) << ""; // output #column
							if (i == arr_size - 1) cout << " |";
						}
						cout << "\n " << setfill('-') << setw((3 + digit_size) * arr_size + 5) << "" << endl; // header row line ---
						for (int i = 0; i < arr_size; i++) {
							cout << " | " << i; // output #row
							for (int j = 0; j < arr_size; j++) {
								cout << " | " << setfill(' ') << setw(digit_size) << arr_rand[i][j]; // output number
								if (j == arr_size - 1) cout << " |";
							}
							cout << "\n " << setfill('-') << setw((3 + digit_size) * arr_size + 5) << "" << endl; // line ---
						}
					}
					// ------------------------------------------------------------------------------------------------------------------------
					
					if (count_iterations == 0) {
						cout << "\n\n Enter quantity[number] -> 2r <- direction[t; r; b; l]\n Enter: ";
						cin >> q >> d;
						cout << endl;
					}
					
					switch (d) {

						case 'l':
							for (int i = 0; i < q; i++) {
								for (int j = 0; j < arr_size; j++) {
									temp = arr_rand[j][0];
									for (int k = 0; k < arr_size - 1; k++) {
										arr_rand[j][k] = arr_rand[j][k + 1];
									}
									arr_rand[j][arr_size - 1] = temp;
								}
							}
							break;
						
						case 'r':
							for (int i = 0; i < arr_size - q; i++) {
								for (int j = 0; j < arr_size; j++) {
									temp = arr_rand[j][0];
									for (int k = 0; k < arr_size - 1; k++) {
										arr_rand[j][k] = arr_rand[j][k + 1];
									}
									arr_rand[j][arr_size - 1] = temp;
								}
							}
							break;
						
						case 'b':
							for (int i = 0; i < arr_size - q; i++) {
								for (int j = 0; j < arr_size; j++) {
									temp = arr_rand[0][j];
									for (int k = 0; k < arr_size - 1; k++) {
										arr_rand[k][j] = arr_rand[k + 1][j];
									}
									arr_rand[arr_size - 1][j] = temp;
								}
							}
							break;
						
						case 't':
							for (int i = 0; i < q; i++) {
								for (int j = 0; j < arr_size; j++) {
									temp = arr_rand[0][j];
									for (int k = 0; k < arr_size - 1; k++) {
										arr_rand[k][j] = arr_rand[k + 1][j];
									}
									arr_rand[arr_size - 1][j] = temp;
								}
							}
							break;
						
						default:
							cout << "\n Error!, need: quantity[number] and direction[t = top; r = right; b = bottom; l = left] --> 1t or 2r or 3b or 4l...";
							useTask = false;
							break;
					}

					if (count_iterations != 0 && useTask) {
						cout << "\n\n Enter: ";
						cin >> q >> d;
						cout << endl;
					}

					count_iterations++;
					
				} while (useTask);
				
				// Return?
				do {
					cout << "\n Try again? y/n" << endl;
					cout << " Enter: ";
					cin >> taskAgain;
					if (taskAgain == 'y' || taskAgain == 'Y') {
						useTask = true;
						repeatCommand = false;
					}
					else if (taskAgain == 'n' || taskAgain == 'N') {
						useTask = false;
						repeatCommand = false;
					}
					else {
						cout << " Repiat command " << endl;
						repeatCommand = true;
					}
				} while (repeatCommand);
			} while (useTask);
			break;
			
		case '2':
			do {
				system("cls");

				// Task description
				cout << "\n     Task 2:\t"
					<< "Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу:" << "\n\t\t"
					<< "пользователь вводит число, первый элемент массива принимает значение этого числа," << "\n\t\t"
					<< "последующий элемент массива принимает значение этого числа + 1," << "\n\t\t"
					<< "третий элемент массива предыдущий элемент + 1 и т.д." << "\n\t\t"
					<< "Созданный массив вывести на экран." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Variables
				uint64_t n;
				const auto ch = ' '; // symbol fill
				const auto arrSize = 10;
				uint64_t arrN[arrSize][arrSize] = {};

				// Body
				cout << " Enter number: ";
				cin >> n;


				
				// cell width calculation
				auto tmp = n;
				auto digitSize = 1;
				
				do {
					tmp /= 10;
					digitSize++;
				} while (tmp > 10);
				
				if (digitSize % 2 == 0) {
					digitSize++;
				}

				
				
				cout << "\n     " << setfill('-') << setw((3 + digitSize) * arrSize + 1) << "" << "\n    "; // header column line ---

				for (int i = 0; i < arrSize; i++) {
					cout << " | " << setw(digitSize / 2) << setfill(' ') << "" << i << setw(digitSize / 2) << ""; // output #column
					if (i == arrSize - 1) cout << " |";
				}

				cout << "\n " << setfill('-') << setw((3 + digitSize) * arrSize + 5) << "" << endl; // header row line ---

				for (int i = 0; i < arrSize; i++) {
					cout << " | " << i; // output #row

					for (int j = 0; j < arrSize; j++) {

						arrN[i][j] = n;
						n ++;

						cout << " | " << setfill(ch) << setw(digitSize) << arrN[i][j]; // output number
						if (j == arrSize - 1) cout << " |";
					}
					cout << "\n " << setfill('-') << setw((3 + digitSize) * arrSize + 5) << "" << endl; // line ---
				}

				// Return?
				do {
					cout << "\n Try again? y/n" << endl;
					cout << " Enter: ";
					cin >> taskAgain;
					if (taskAgain == 'y' || taskAgain == 'Y') {
						repeatCommand = false;
					}
					else if (taskAgain == 'n' || taskAgain == 'N') {
						useTask = false;
						repeatCommand = false;
					}
					else {
						cout << " Repiat command " << endl;
						repeatCommand = true;
					}
				} while (repeatCommand);
			} while (useTask);
			break;
			
		case '1':
			do {
				system("cls");

				// Task description
				cout << "\n     Task 1:\t"
					<< "Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу:" << "\n\t\t"
					<< "пользователь вводит число, первый элемент массива принимает значение этого числа," << "\n\t\t"
					<< "последующий элемент массива принимает значение этого числа умноженного на 2," << "\n\t\t"
					<< "третий элемент массива предыдущий элемент умноженный на 2 и т.д." << "\n\t\t"
					<< "Созданный массив вывести на экран." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Variables
				uint64_t n;
				const auto ch = ' '; // symbol fill
				const auto arrSize = 7;
				uint64_t arrN[arrSize][arrSize] = {};

				// Body
				cout << " Enter number: ";
				cin >> n;


				
				// cell width calculation
				auto tmp = n;
				auto digitSize = 1;
				
				for (int i = 0; i < arrSize * arrSize; i++) {
					tmp *= 2;
				}
				
				do {
					tmp /= 10;
					digitSize++;
				} while (tmp > 10);

				if (digitSize % 2 == 0) {
					digitSize++;
				}

				

				cout << "\n     " << setfill('-') << setw((3 + digitSize) * arrSize + 1) << "" << "\n    "; // header column line ---

				for (int i = 0; i < arrSize; i++) {
					cout << " | " << setw(digitSize / 2) << setfill(' ') << "" << i << setw(digitSize / 2) << ""; // output #column
					if (i == arrSize - 1) cout << " |";
				}

				cout << "\n " << setfill('-') << setw((3 + digitSize) * arrSize + 5) << "" << endl; // header row line ---

				for (int i = 0; i < arrSize; i++) {
					cout << " | " << i; // output #row

					for (int j = 0; j < arrSize; j++) {

						arrN[i][j] = n;
						n *= 2;

						cout << " | " << setfill(ch) << setw(digitSize) << arrN[i][j]; // output number
						if (j == arrSize - 1) cout << " |";
					}
					cout << "\n " << setfill('-') << setw((3 + digitSize) * arrSize + 5) << "" << endl; // line ---
				}

				// Return?
				do {
					cout << "\n Try again? y/n" << endl;
					cout << " Enter: ";
					cin >> taskAgain;
					if (taskAgain == 'y' || taskAgain == 'Y') {
						repeatCommand = false;
					}
					else if (taskAgain == 'n' || taskAgain == 'N') {
						useTask = false;
						repeatCommand = false;
					}
					else {
						cout << " Repiat command " << endl;
						repeatCommand = true;
					}
				} while (repeatCommand);
			} while (useTask);
			break;

		case 'q':
		case 'Q':
		case '0':
			useMenu = false;
			break;

		default:
			cout << " Repeat command " << endl;
			break;
		}
	} while (useMenu);

	system("pause");
	return;
}
