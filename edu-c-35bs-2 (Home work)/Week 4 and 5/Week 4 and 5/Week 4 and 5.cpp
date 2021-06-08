/**
 * Week 4 - 5
 *
 * Theme:
 *   Логические операторы и операторы ветвлений.
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
		cout << "| Week 4\t\t" << "|" << endl;
		cout << "| Week 5\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| 0 or q - exit\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "\nEnter Week: #";
		cin >> userChoice;

		switch (userChoice) {

		case '5': // Week 5
			while (useMenuTask) {
				cout << "\n\n|-----------------------" << "|" << endl;
				cout << "|    Tasks of week 5\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| Task 1\t\t" << "|" << endl;
				cout << "| Task 2\t\t" << "|" << endl;
				cout << "| Task 3\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\nEnter Task: #";
				cin >> userChoice;

				switch (userChoice) {

				case '3': // Task 3
					cout << "\nВася работает программистом и получает 50$ за каждые 100 строк кода.\nЗа каждое третье опоздание Васю штрафуют на 20$.\n";

					do {
						int lines, delays, k = 0;
						double income;

						cout << "\n[1] I want to know the number of lines of code, I can enter the desired income and the number of delays.";
						cout << "\n[2] I want to know the number of possible delays, I can enter the desired income and the number of lines of code.";
						cout << "\n[3] I want to know the income, I can enter the number of lines of code and the number of delays.";
						cout << "\n Enter: ";
						cin >> userChoice;

						switch (userChoice) {
						case '1':
							cout << "\n Enter desired income: ";
							cin >> income;
							cout << " Enter number of delays: ";
							cin >> delays;

							if (delays >= 3) {
								k = delays / 3;
							}

							lines = (income * 2) + (k * 20 * 2);

							cout << "\n You need " << lines << " lines of code.\n";
							break;

						case '2':
							cout << "\n Enter desired income: ";
							cin >> income;
							cout << " Enter number lines of code: ";
							cin >> lines;

							delays = ((lines / 2) - income) / 20;

							if (delays <= 0) {
								cout << "\n You can't delays. Go work!\n";
							}
							else {
								cout << "\n You can " << delays << " delays.\n";
							}
							break;

						case '3':
							cout << "\n Enter number lines of code: ";
							cin >> lines;
							cout << " Enter number of delays: ";
							cin >> delays;

							if (delays >= 3) {
								k = delays / 3;
							}

							income = (lines / 2) - (k * 20);

							cout << "\n You income is " << income << "$\n";
							break;

						default:
							cout << " Repiat command " << endl;
							break;
						}

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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
					cout << "\nНаписать программу подсчета стоимости разговора для разных мобильных операторов.\nПользователь вводит стоимость разговора и выбирает с какого на какой оператор он звонит.\n";

					do {
						double costCall;
						int op_1, op_2;

						cout << "\nEnter cost of the call: ";
						cin >> costCall;

						for (int i = 1; i <= 2; i++) {
							if (i == 1) {
								cout << "\nEnter you call operator: \n";
							}
							else {
								cout << "\nEnter friend call operator: \n";
							}

							cout << " 1 - Vodafon\n";
							cout << " 2 - Kyivstar\n";
							cout << " 3 - Lifecell\n";
							cout << "Enter: ";
							cin >> userChoice;

							if (i == 1) {
								op_1 = userChoice;
							}
							else {
								op_2 = userChoice;
							}
						}

						cout << "Cost of the call " << costCall << "$";

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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
					cout << "\nПользователь вводит с клавиатуры символ.\nОпределить, какой это символ: Буква, цифра, знак препинания или другое.\n";

					do {
						char userSymbol;

						cout << "\nEnter symbol: ";
						cin >> userSymbol;

						if (userSymbol == 33 || userSymbol == 34 || userSymbol == 39 || userSymbol == 40 || userSymbol == 41 || userSymbol == 44 || userSymbol == 45 || userSymbol == 46 || userSymbol == 47 || userSymbol == 58 || userSymbol == 59 || userSymbol == 63 || userSymbol == 91 || userSymbol == 93) {
							cout << " U enter punctuation mark\n";
						}
						else if (userSymbol >= 48 && userSymbol <= 57) {
							cout << " U enter numeral\n";
						}
						else if ((userSymbol >= 65 && userSymbol <= 90) || (userSymbol >= 97 && userSymbol <= 122)) {
							cout << " U enter letter\n";
						}
						else {
							cout << " U enter other symbol\n";
						}

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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

		case '4': // Week 4
			while (useMenuTask) {
				cout << "\n\n|-----------------------" << "|" << endl;
				cout << "|    Tasks of week 4\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| Task 1\t\t" << "|" << endl;
				cout << "| Task 2\t\t" << "|" << endl;
				cout << "| Task 3\t\t" << "|" << endl;
				cout << "| Task 4\t\t" << "|" << endl;
				cout << "| Task 5\t\t" << "|" << endl;
				cout << "| Task 6\t\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "| 0 or b - back to menu\t" << "|" << endl;
				cout << "|-----------------------" << "|" << endl;
				cout << "\nEnter Task: #";
				cin >> userChoice;

				switch (userChoice) {
				case '6': // Task 6
					cout << "\nПользователь вводит с клавиатуры уровень продаж для трех менеджеров.\nОпределить их зарплату, определить лучшего менеджера, начислить ему премию 200$.\n";

					do {
						int s1, s2, s3, s1_tmp, s2_tmp, s3_tmp, s1_pay = 0, s2_pay = 0, s3_pay = 0, pay;

						cout << "\n Enter the sales of the first second and third manager: \n";
						cin >> s1 >> s2 >> s3;

						if (s1 > s2&& s1 > s3) {
							s1_tmp = s1;
							if (s2 > s3) {
								s2_tmp = s2;
								s3_tmp = s3;
							}
							else {
								s2_tmp = s3;
								s3_tmp = s2;
							}
						}
						else if (s2 > s1&& s2 > s3) {
							s1_tmp = s2;
							if (s1 > s3) {
								s2_tmp = s1;
								s3_tmp = s3;
							}
							else {
								s2_tmp = s3;
								s3_tmp = s1;
							}
						}
						else {
							s1_tmp = s3;
							if (s1 > s2) {
								s2_tmp = s1;
								s3_tmp = s2;
							}
							else {
								s2_tmp = s2;
								s3_tmp = s1;
							}
						}
						for (int i = 1; i <= 3; i++) {
							if (i == 1) {
								pay = s1_tmp;
							}
							else if (i == 2) {
								pay = s2_tmp;
							}
							else {
								pay = s3_tmp;
							}
							if (pay < 500) {
								pay = pay + ((pay / 100) * 3);
							}
							else if (pay >= 500 && pay < 1000) {
								pay = pay + ((pay / 100) * 5);
							}
							else {
								pay = pay + ((pay / 100) * 8);
							}
							if (i == 1) {
								s1_pay = s1_pay + pay;
							}
							else if (i == 2) {
								s2_pay = s2_pay + pay;
							}
							else {
								s3_pay = s3_pay + pay;
							}
						}

						if (s1 > s2&& s1 > s3) {
							cout << "\nFirst manager with " << s1 << "$ sales, gets paid " << s1_pay << "$ and a bonus of 200$, total paid " << (s1_pay + 200) << "$" << endl;
							if (s2 > s3) {
								cout << "Second manager with " << s2 << "$ sales, gets paid " << s2_pay << "$" << endl;
								cout << "And third manager with " << s3 << "$ sales, gets paid " << s3_pay << "$" << endl;
							}
							else {
								cout << "Third manager with " << s3 << "$ sales, gets paid " << s2_pay << "$" << endl;
								cout << "And second manager with " << s2 << "$ sales, gets paid " << s3_pay << "$" << endl;
							}
						}
						else if (s2 > s1&& s2 > s3) {
							cout << "\nSecond manager with " << s2 << "$ sales, gets paid " << s1_pay << "$ and a bonus of 200$, total paid " << (s1_pay + 200) << "$" << endl;
							if (s1 > s3) {
								cout << "First manager with " << s1 << "$ sales, gets paid " << s2_pay << "$" << endl;
								cout << "And third manager with " << s3 << "$ sales, gets paid " << s3_pay << "$" << endl;
							}
							else {
								cout << "Third manager with " << s3 << "$ sales, gets paid " << s2_pay << "$" << endl;
								cout << "And first manager with " << s1 << "$ sales, gets paid " << s3_pay << "$" << endl;
							}
						}
						else {
							cout << "\nThird manager with " << s3 << "$ sales, gets paid " << s1_pay << "$ and a bonus of 200$, total paid " << (s1_pay + 200) << "$" << endl;
							if (s1 > s2) {
								cout << "First manager with " << s1 << "$ sales, gets paid " << s2_pay << "$" << endl;
								cout << "And second manager with " << s2 << "$ sales, gets paid " << s3_pay << "$" << endl;
							}
							else {
								cout << "Second manager with " << s2 << "$ sales, gets paid " << s2_pay << "$" << endl;
								cout << "And first manager with " << s1 << "$ sales, gets paid " << s3_pay << "$" << endl;
							}
						}

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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

				case '5': // Task 5
					cout << "\nПользователь вводит две даты (день, месяц, год в виде целых чисел).\nНеобходимо определить и вывести количество дней между этими двумя датами.\n";

					do {
						int date_day, date_month, date_year, date1_day, date1_month, date1_year, date2_day, date2_month, date2_year, days = 0, days_tmp = 0, days1_tmp = 0, days2_tmp = 0;
						bool repairEnter, year_366, date1_year_366, date2_year_366;

						for (int i = 1; i <= 2; i++) {
							if (i == 1) {
								cout << "\nEnter first date\n";
							}
							else {
								cout << "\nEnter second date\n";
							}

							do {
								cout << " Enter year: ";
								cin >> date_year;
								if ((1 > date_year) || (date_year > 2020)) {
									cout << "\n Error, enter corect year (1 - 2020)";
									repairEnter = true;
								}
								else {
									if (date_year % 4 != 0 || date_year % 100 == 0 && date_year % 400 != 0) {
										year_366 = false;
										repairEnter = false;
									}
									else {
										year_366 = true;
										repairEnter = false;
									}
								}
							} while (repairEnter);

							do {
								cout << " Enter month: ";
								cin >> date_month;
								if ((1 > date_month) || (date_month > 12)) {
									cout << "\n Error, enter corect month";
									repairEnter = true;
								}
								else {
									repairEnter = false;
								}
							} while (repairEnter);

							do {
								cout << " Enter day: ";
								cin >> date_day;

								if (1 > date_day || date_day > 31) {
									cout << "\n Error, enter corect days";
									repairEnter = true;
								}
								else if ((date_month != 1 && date_month != 2 && date_month != 3 && date_month != 5 && date_month != 7 && date_month != 8 && date_month != 10 && date_month != 12) && (date_day == 31)) {
									cout << "\n Error in " << date_month << " month 30 days";
									repairEnter = true;
								}
								else if (date_month == 2 && !year_366 && date_day > 28) {
									cout << "\n Error in february " << date_year << " year 28 days";
									repairEnter = true;
								}
								else if (date_month == 2 && year_366 && date_day > 29) {
									cout << "\n Error in february " << date_year << " year 29 days";
									repairEnter = true;
								}
								else {
									repairEnter = false;
								}
							} while (repairEnter);

							if (i == 1) {
								date1_year = date_year;
								date1_year_366 = year_366;
								date1_month = date_month;
								date1_day = date_day;
							}
							else {
								if (date1_year > date_year) {
									date2_year = date1_year;
									date2_year_366 = date1_year_366;
									date2_month = date1_month;
									date2_day = date1_day;
									date1_year = date_year;
									date1_year_366 = year_366;
									date1_month = date_month;
									date1_day = date_day;
								}
								else {
									date2_year = date_year;
									date2_year_366 = year_366;
									date2_month = date_month;
									date2_day = date_day;
								}
							}
						}

						for (int i = 1; i <= 2; i++) {
							date_day = 0;

							if (i == 1) {
								date_month = date1_month - 1;
							}
							else {
								date_month = date2_month - 1;
							}

							for (date_month; date_month >= 1; date_month--) {
								if (date_month == 1 || date_month == 3 || date_month == 5 || date_month == 7 || date_month == 8 || date_month == 10 || date_month == 12) {
									date_day = date_day + 31;
								}
								else if (date_month == 2) {
									if (date1_year_366) {
										date_day = date_day + 29;
									}
									else {
										date_day = date_day + 28;
									}
								}
								else {
									date_day = date_day + 30;
								}
								if (i == 1) {
									days1_tmp = date_day + date1_day;
								}
								else {
									days2_tmp = date_day + date2_day;
								}
							}
						}

						if (date2_year_366) {
							days2_tmp = 366 - days2_tmp;
						}
						else {
							days2_tmp = 365 - days2_tmp;
						}

						for (date1_year; date1_year <= date2_year; date1_year++) {
							if (date1_year % 4 != 0 || date1_year % 100 == 0 && date1_year % 400 != 0) {
								days = days + 365;
							}
							else {
								days = days + 366;
							}
						}

						days = days - days1_tmp - days2_tmp;
						cout << "\nDays between dates: " << days << endl;

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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
					cout << "\nПрограмма должна рассчитать какое минимальное количество топлива необходимо\nдля дозаправки самолету в пункте В, чтобы долететь из пункта А в пункт С.\n";

					do {
						int ab_km, bc_km, weight_kg, l_km, oilFull_l, oilBalance_l, oilNeed_l, max_km;
						bool canFly_ab, canFly_bc;

						oilFull_l = 300;

						cout << "\nEnter distance between A-B (km): ";
						cin >> ab_km;
						cout << "Enter distance between B-C (km): ";
						cin >> bc_km;
						cout << "Enter cargo weight (kg): ";
						cin >> weight_kg;

						if (weight_kg < 500) {
							l_km = 1;
						}
						else if ((weight_kg >= 500) && (weight_kg < 1000)) {
							l_km = 4;
						}
						else if ((weight_kg >= 1000) && (weight_kg < 1500)) {
							l_km = 7;
						}
						else if ((weight_kg >= 1500) && (weight_kg < 2000)) {
							l_km = 9;
						}
						else {
							cout << "\nСargo weight is more than permissible (2000kg) or not correct\n";
							repiatCommand = true;
						}

						if (!repiatCommand) {
							max_km = oilFull_l / l_km;
							canFly_ab = (max_km - ab_km) > 0;
							canFly_bc = (max_km - bc_km) > 0;
							if (canFly_ab && canFly_bc) {
								oilBalance_l = ((max_km - ab_km) * l_km);
								oilNeed_l = oilFull_l - oilBalance_l;
								cout << "\nNeed refueling in B on: " << oilNeed_l << "l" << endl;
							}
							else {
								if (!canFly_ab) {
									cout << "\nLong distance between A-B (" << ab_km << "km) with this weight (" << weight_kg << "kg)" << endl;
								}
								else if (!canFly_bc) {
									cout << "\nLong distance between B-C (" << bc_km << "km) with this weight (" << weight_kg << "kg)" << endl;
								}
							}
						}

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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
					cout << "\nПользователь вводит с клавиатуры 7 целых чисел.\nНапишите программу, которая определяет максимальное из этих 7 чисел (Подсказка — решение должно быть простым).\n";

					do {
						int numLargest;

						cout << "\nEnter seven number\n\n";
						cin >> numLargest;

						for (int i = 1; i <= 6; i++) {
							cin >> userEnter;
							if (userEnter > numLargest) {
								numLargest = userEnter;
							}
						}

						cout << "\nThe largest number: " << numLargest << endl;

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
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
					cout << "\nПользователь вводит четырехзначное число.\nНеобходимо поменять в этом числе 1 и 2 цифры, а также 3 и 4 цифры.\nЕсли пользователь вводит не четырехзначное число — вывести сообщение об ошибке.\n";

					do {
						cout << "\nEnter four digit number: ";
						cin >> userEnter;

						bool fourDigit = ((999 < userEnter) && (userEnter <= 9999));
						if (!fourDigit) {
							cin.clear();
							cin.ignore(4, '\n');
							cout << "Error input (need four digit number)\n";
							repiatCommand = true;
						}

						if (!repiatCommand) {
							int a1, a2, a3, a4, b1, b2, n;

							a4 = userEnter % 10;
							a3 = (userEnter % 100) / 10;
							a2 = (userEnter % 1000) / 100;
							a1 = (userEnter % 10000) / 1000;

							b1 = (a2 * 10) + a1;
							b2 = (a4 * 10) + a3;

							n = (b1 * 100) + b2;

							cout << "Total number: " << n << endl;
						}

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
							char taskAgain;
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
					cout << "\nПользователь вводит с клавиатуры целое шестизначное число.\nНаписать программу, которая определяет, является ли введенное число — счастливым.\n(Счастливым считается шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр).\nЕсли пользователь ввел не шестизначное число — сообщение об ошибке.\n";

					do {
						cout << "\nEnter six digit number: ";
						cin >> userEnter;

						bool sixDigit = ((99999 < userEnter) && (userEnter <= 999999));
						if (!sixDigit) {
							cin.clear();
							cin.ignore(6, '\n');
							cout << "Error input (need six digit number)\n";
							repiatCommand = true;
						}

						if (!repiatCommand) {
							int a1, a2, b1, b2;

							a1 = userEnter / 1000;
							a2 = (((userEnter / 1000.0) + 0.0001) - a1) * 1000;

							b1 = (a1 / 100) + ((a1 / 10) - ((a1 / 100) * 10)) + (a1 - ((a1 / 10) * 10));
							b2 = (a2 / 100) + ((a2 / 10) - ((a2 / 100) * 10)) + (a2 - ((a2 / 10) * 10));

							if (b1 == b2) {
								cout << "U number is lucky" << endl;;
							}
							else {
								cout << "U number is not lucky" << endl;
							}
						}

						do {
							cout << "\n Try again? y/n" << endl;
							cout << "\nEnter: ";
							char taskAgain;
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