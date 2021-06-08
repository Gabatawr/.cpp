/**
 * Week 7
 *
 * Theme:
 *   Циклы.
 *
 * @author Artem Kashyrin
 *
*/

#include <iostream>
#include <windows.h>

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;



void main() {

	// Initialize random number generator. (1-100) r = (rand() % 100) + 1;
	srand(time(0));
	int randFix = rand();

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
		cout << "| 1 - Homework\t\t" << "|" << endl;
		cout << "| 2 - Bonus task\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| 0 or q - exit\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "\n Enter: ";
		cin >> userChoice;

		switch (userChoice) {

		case '2': // Bonus tasks
			while (useMenuTask) {
				cout << "\n\n|-----------------------" << "|" << endl;
				cout << "|    Bonus tasks\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 1 - Paradox Monty Hall" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\n Enter Task: #";
				cin >> userChoice;

				switch (userChoice) {

				case '1': //Paradox Monty Hall
					//Task description
					cout << "\n \n\n";

					do {
						//Variables
						int countGames, numberGames, countIteration, numberIteration, cases, countCases, x, prizeBox, openBox, userBox, userBox_2, toChange_won, toChange_loss, noChange_won, noChange_loss;
						double toChange_won_ave, toChange_loss_ave, noChange_won_ave, noChange_loss_ave, toChange_won_aveProcent, toChange_loss_aveProcent, noChange_won_aveProcent, noChange_loss_aveProcent;
						bool isWas, isLast, isEveryChance, isLastСhance = false;

						//Body
						cout << "\n Введите количество игр: ";
						cin >> numberGames;

						cout << " Введите количество итераций: ";
						cin >> numberIteration;

						cout << " Введите количество кейсов: ";
						cin >> cases;
						int* arrCases = new int[cases];

						cout << " Менять выбор: [1] при каждой возможности; [0] только при последней; Введите 1 или 0: ";
						cin >> x;
						if (x == 1) {
							isEveryChance = true;
							isLast = false;
						}
						else {
							isEveryChance = false;
							isLast = true;
						}

						countIteration = 1;

						do {
							toChange_won = 0;
							toChange_loss = 0;

							countGames = 1;

							do {
								for (int i = 0; i < cases + 1; i++) {
									arrCases[i] = i;
								}

								countCases = cases;

								prizeBox = (rand() % cases) + 1;
								userBox = (rand() % cases) + 1;

								while (countCases != 2) {
									do {
										arrCases[prizeBox] = 0;
										arrCases[userBox] = 0;

										openBox = (rand() % cases) + 1;

										if (arrCases[openBox] != 0) {
											isWas = false;

											arrCases[openBox] = 0;
											countCases--;

										}
										else {
											isWas = true;
										}
									} while (isWas);

									if (isLast) {
										isLastСhance = countCases == 2;
									}

									if (isEveryChance || isLastСhance) {

										arrCases[prizeBox] = prizeBox;

										do {
											userBox_2 = (rand() % cases) + 1;

											if (arrCases[userBox_2] != 0 && userBox_2 != userBox) {
												isWas = false;

												arrCases[userBox] = userBox;
												userBox = userBox_2;
												arrCases[userBox] = 0;
											}
											else {
												isWas = true;
											}
										} while (isWas);
									}
								}

								if (userBox == prizeBox) {
									toChange_won++;
								}
								else {
									toChange_loss++;
								}

								countGames++;
							} while (countGames != numberGames + 1);

							if (countIteration == 1) {
								toChange_won_ave = toChange_won;
								toChange_loss_ave = toChange_loss;
							}
							else {
								toChange_won_ave = (toChange_won_ave + toChange_won) / 2;
								toChange_loss_ave = (toChange_loss_ave + toChange_loss) / 2;
							}

							cout << "\n Итерация: " << countIteration << " из " << numberIteration << endl << endl;
							cout << " С измемением выбора:" << "\n Побед: " << toChange_won << "\t Поражений: " << toChange_loss << endl << endl;

							noChange_won = 0;
							noChange_loss = 0;
							countGames = 0;

							do {
								prizeBox = (rand() % cases) + 1;
								userBox = (rand() % cases) + 1;

								if (userBox == prizeBox) {
									noChange_won++;
								}
								else {
									noChange_loss++;
								}

								countGames++;
							} while (countGames != numberGames);


							if (countIteration == 1) {
								noChange_won_ave = noChange_won;
								noChange_loss_ave = noChange_loss;
							}
							else {
								noChange_won_ave = (noChange_won_ave + noChange_won) / 2;
								noChange_loss_ave = (noChange_loss_ave + noChange_loss) / 2;
							}

							cout << " Без измемения выбора:" << "\n Побед: " << noChange_won << "\t Поражений: " << noChange_loss << endl << "---------------------------------------------";

							countIteration++;
						} while (countIteration <= numberIteration);

						toChange_won_aveProcent = (toChange_won_ave / numberGames) * 100;
						toChange_loss_aveProcent = (toChange_loss_ave / numberGames) * 100;
						noChange_won_aveProcent = (noChange_won_ave / numberGames) * 100;
						noChange_loss_aveProcent = (noChange_loss_ave / numberGames) * 100;

						cout << "\n\n\n\n\n Итого в среднем за все игры: \n\n С изменением выбора:\n Побед: " << toChange_won_aveProcent << "% \t Поражений: " << toChange_loss_aveProcent << "%\n\n Без изменения выбора:\n Побед: " << noChange_won_aveProcent << "% \t Поражений: " << noChange_loss_aveProcent << "%\n\n\n\n";

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
						system("cls");
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
				cout << "|      Homework\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| Task 1\t\t" << "|" << endl;
				cout << "| Task 2\t\t" << "|" << endl;
				cout << "| Task 3\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\n Enter Task: #";
				cin >> userChoice;

				switch (userChoice) {

				case '3': // Task 3
					//Task description
					cout << "\n \n";

					do {
						//Variables
						int s;

						//Body
						cout << "\n Enter rows: ";
						cin >> s;

						for (int r = 1; r <= 8; r++) {
							for (int k = 1; k <= 4; k++) {
								for (int b = s; b > 0; b--) {
									if (r % 2 != 0) {
										cout << "*";
									}
									else {
										cout << "_";
									}
								}
								for (int w = s; w > 0; w--) {
									if (r % 2 != 0) {
										cout << "_";
									}
									else {
										cout << "*";
									}
								}
							}
							for (int n = 0; n < s / 2 + 0.5; n++) {
								cout << "\n";
							}
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

				case '2': // Task 2
					//Task description
					cout << "\n Пользователь вводит число. Определить количество цифр в этом числе, посчитать их сумму и среднее арифметическое.\nОпределить количество нулей в этом числе. Общение с пользователем организовать через меню.\n";

					do {
						//Variables
						int n, tmp, nDef, countZero, count;
						double ave;

						//Body
						tmp = 0;
						countZero = 0;
						count = 0;

						cout << "\n Enter number: ";
						cin >> n;

						nDef = n;

						while (n > 0) {
							tmp += n % 10;
							if (n % 10 == 0) {
								countZero++;
							}
							count++;
							n = n / 10;
						}

						ave = (double)tmp / count;

						cout << " The number " << nDef << " has " << countZero << " zeros and the average = " << ave << endl;

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
					cout << "\n Вывести на экран фигуры заполненные звездочками. Диалог с пользователем реализовать при помощи меню.\n";

					do {
						//Variables
						int rows;

						//Body
						cout << "\n Enter rows: ";
						cin >> rows;

						if (rows % 2 == 0) {
							cout << " Error, need an odd number (rows = " << rows + 1 << ").";
							rows++;
						}

						if (rows < 5) {
							cout << " At least 5 rows for correct display (rows = 5).";
							rows = 5;
						}

						cout << "\n+-----------+-----------+-----------+-----------+-----------+";
						cout << "\n| * * * * * | *         | * * * * * |           | * * * * * |";
						cout << "\n|   * * * * | * *       |   * * *   |           |   * * *   |";
						cout << "\n|     0 * * | * * 1     |     2     |     3     |     4     |";
						cout << "\n|       * * | * * * *   |           |   * * *   |   * * *   |";
						cout << "\n|         * | * * * * * |           | * * * * * | * * * * * |";
						cout << "\n|-----------+-----------+-----------+-----------+-----------|";
						cout << "\n| *       * | *         |         * | * * * * * |         * |";
						cout << "\n| * *   * * | * *       |       * * | * * * *   |       * * |";
						cout << "\n| * * 5 * * | * * 6     |     7 * * | * * 8     |     9 * * |";
						cout << "\n| * *   * * | * *       |       * * | * *       |   * * * * |";
						cout << "\n| *       * | *         |         * | *         | * * * * * |";
						cout << "\n+-----------+-----------+-----------+-----------+-----------+";

						cout << "\n Figure: #";
						cin >> userChoice;

						cout << endl;
						switch (userChoice) {

						case '9':
							for (int r = 1; r <= rows; r++) {
								for (int sp = rows - 1; sp >= r; sp--) {
									cout << "  ";
								}
								for (int st = 1; st <= r; st++) {
									cout << " *";
								}
								cout << "\n";
							}
							break;

						case '8':
							for (int r = 1; r <= rows; r++) {
								for (int st = rows; st > r; st--) {
									cout << " *";
								}
								cout << "\n";
							}
							break;

						case '7':
							for (int r = 1; r <= rows - (rows / 2 - 0.5); r++) {
								for (int st = 1; st <= r; st++) {
									if (st == rows - (rows / 2)) {
									}
									else {
										cout << "  ";
									}
								}
								for (int sp = rows - 2 * r; sp > 0; sp--) {
									cout << "  ";
								}
								for (int st = 1; st <= r; st++) {
									cout << " *";
								}
								cout << endl;
							}
							for (int r = 1; r <= rows - (rows / 2 + 0.5); r++) {
								for (int st = rows / 2; st >= r; st--) {
									cout << "  ";
								}
								for (int sp = 1; sp <= r * 2 - 0.5; sp++) {
									cout << "  ";
								}
								for (int st = rows / 2; st >= r; st--) {
									cout << " *";
								}
								cout << endl;
							}
							break;

						case '6':
							for (int r = 1; r <= rows - (rows / 2 - 0.5); r++) {
								for (int st = 1; st <= r; st++) {
									cout << " *";
								}
								cout << endl;
							}
							for (int r = 1; r <= rows - (rows / 2 + 0.5); r++) {
								for (int st = rows / 2; st >= r; st--) {
									cout << " *";
								}
								cout << endl;
							}
							break;

						case '5':
							for (int r = 1; r <= rows - (rows / 2 - 0.5); r++) {
								for (int st = 1; st <= r; st++) {
									cout << " *";
								}
								for (int sp = rows - 2 * r; sp > 0; sp--) {
									cout << "  ";
								}
								for (int st = 1; st <= r && st < rows / 2 + 0.5; st++) {
									cout << " *";
								}
								cout << endl;
							}
							for (int r = 1; r <= rows - (rows / 2 + 0.5); r++) {
								for (int st = rows / 2; st >= r; st--) {
									cout << " *";
								}
								for (int sp = 1; sp <= r * 2 - 0.5; sp++) {
									cout << "  ";
								}
								for (int st = rows / 2; st >= r; st--) {
									cout << " *";
								}
								cout << endl;
							}
							break;

						case '4':
							for (int r = 1; r <= rows - (rows / 2 - 0.5); r++) {
								for (int st = 2; st <= r; st++) {
									cout << "  ";
								}
								for (int sp = rows - 2 * r; sp > -2; sp--) {
									cout << " *";
								}
								for (int st = 1; st <= r && st < rows / 2 + 0.5; st++) {
									cout << "  ";
								}
								cout << endl;
							}
							for (int r = 1; r <= rows - (rows / 2 + 0.5); r++) {
								for (int st = rows / 2; st >= r + 1; st--) {
									cout << "  ";
								}
								for (int sp = -1; sp <= r * 2 - 0.5; sp++) {
									cout << " *";
								}
								for (int st = rows / 2; st >= r; st--) {
									cout << "  ";
								}
								cout << endl;
							}
							break;

						case '3':
							for (int n = 1; n < rows / 2 - 0.5; n++) {
								cout << "\n";
							}
							for (int r = 1; r <= rows - (rows / 2 - 0.5); r++) {
								for (int sp = rows - (rows / 2 + 0.5); sp >= r; sp--) {
									cout << "  ";
								}
								for (int st = r; st < r * 3 - 1; st++) {
									cout << " *";
								}
								cout << "\n";
							}
							break;

						case '2':
							for (int r = 1; r <= rows - (rows / 2 - 0.5); r++) {
								for (int sp = 1; sp < r; sp++) {
									cout << "  ";
								}
								for (int st = rows; st > r * 2 - 2; st--) {
									cout << " *";
								}
								cout << "\n";
							}
							for (int n = 1; n < rows / 2 - 0.5; n++) {
								cout << "\n";
							}
							break;

						case '1':
							for (int r = 1; r <= rows; r++) {
								for (int st = 1; st <= r; st++) {
									cout << " *";
								}
								cout << "\n";
							}
							break;

						case '0':
							for (int r = 1; r <= rows; r++) {
								for (int sp = 0; sp < r; sp++) {
									cout << "  ";
								}
								for (int st = rows; st >= r; st--) {
									cout << " *";
								}
								cout << "\n";
							}
							break;

						default:
							cout << " Repiat command " << endl;
							break;
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