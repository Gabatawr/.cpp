/**
 * Week 9
 *
 * Theme:
 *   Массивы одномерные.
 *
 * @author Artem Kashyrin
 *
*/

#include <iostream>
#include <windows.h>

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <random>  // For random_device and mt19937

using namespace std;

void main() {

	// Initialize random number generator. (1-100) r = (rand() % 100) + 1;
	srand(time(0));

	// Initialize random number generator the Mersenne Twister
	random_device rd;
	//mt19937 mersenne(rd());

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool useMenu = true;

	do {
		// used in all
		char userChoice;
		char taskAgain;
		bool useTask = true;
		bool repeatCommand = false;

		cout << "\n\n|-----------------------" << "|" << endl;
		cout << "|    Tasks of week 9\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| Task 1\t\t" << "|" << endl;
		cout << "| Task 2\t\t" << "|" << endl;
		cout << "| Task 3\t\t" << "|" << endl;
		cout << "| Task 4\t\t" << "|" << endl;
		cout << "| Task 5\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "| 0 or q - exit\t\t" << "|" << endl;
		cout << "|-----------------------" << "|" << endl;
		cout << "\n Enter Task: #";
		cin >> userChoice;

		switch (userChoice) {

		case '5':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 5:\tЕсть стопка оладий различного радиуса. Единственная операция, проводимая с ними:\n\t\tмежду любыми двумя суем лопатку и меняем порядок оладий над лопаткой на обратный.\n\t\tНеобходимо за минимальное количество операций таких отсортировать снизу вверх по убыванию радиуса.\n\n";

				//Variables
				int arrSize, arrMin, arrMax, tmpF, tmpL, valMax, posMax, step = 0;

				//Body

				// Вводим размер массива
				cout << " Enter array size: ";
				cin >> arrSize;

				// Вводим диапазон массива
				do {
					cout << " Enter min: ";
					cin >> arrMin;
					cout << " Enter max: ";
					cin >> arrMax;
				} while (arrMin > arrMax || arrSize > arrMax - arrMin);

				// Создаем массивы, выдиляем память под arrSize ячеек
				int* arrRand = new int[arrSize];

				// Заполняем массивы рандомными числами в min - max диапазоне
				for (int i = 0; i < arrSize; i++) {
					arrRand[i] = rand() % (arrMax - arrMin) + arrMin;
					for (int k = 0; k < i; k++) {
						if (arrRand[i] == arrRand[k]) {
							arrRand[i] = rand() % (arrMax - arrMin) + arrMin;
							k = -1;
						}
					}
				}

				// Выводим на экран
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array[";
					}
					cout << arrRand[i];
					if (i == arrSize - 1) {
						cout << "] Before sort" << endl;
					}
					else {
						cout << ", ";
					}
				}

				// Сортируем по правилу задания
				for (int a = 0; a < arrSize; a++) {


					// Нашли максимальное
					for (int i = a; i < arrSize; i++) {
						if (i == a) {
							valMax = arrRand[i];
							posMax = i;
						}
						if (valMax < arrRand[i]) {
							valMax = arrRand[i];
							posMax = i;
						}
						step++;
					}


					// Перевернули все начиная с максимального
					for (int i = posMax, b = arrSize - 1; i < b; i++, b--) {
						tmpF = arrRand[i];
						tmpL = arrRand[b];

						arrRand[i] = tmpL;
						arrRand[b] = tmpF;

						step++;
					}

						// Выводим на экран
						for (int i = 0; i < arrSize; i++) {
						if (i == 0) {
							cout << "\n Array[";
						}
						cout << arrRand[i];
						if (i == arrSize - 1) {
							cout << "] MaxUp" << endl;
						}
						else {
							cout << ", ";
						}
					}


					// Перевернули весь массив, максимальное теперь в самом низу
					for (int i = a, b = arrSize - 1; i < b; i++, b--) {
						tmpF = arrRand[i];
						tmpL = arrRand[b];

						arrRand[i] = tmpL;
						arrRand[b] = tmpF;

						step++;
					}

						// Выводим на экран
						for (int i = 0; i < arrSize; i++) {
						if (i == 0) {
							cout << "\n Array[";
						}
						cout << arrRand[i];
						if (i == arrSize - 1) {
							cout << "] MaxDown" << endl;
						}
						else {
							cout << ", ";
						}
					}


					// Максимальное на своем месте, можно его не учитывать a++
				}

				// Выводим на экран
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array[";
					}
					cout << arrRand[i];
					if (i == arrSize - 1) {
						cout << "] After sort" << endl;
					}
					else {
						cout << ", ";
					}
				}
				
				// Выводим кол-во шагов (с учетом шагов на поиск максимального)
				cout << "\n Step = " << step << endl;

				delete[] arrRand;
				//Return?
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

		case '4':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 4:\tРеализовать сортировку массива методом усовершенствованной сортировки пузырьковым методом.\n\t\tУсовершенствование состоит в том, чтобы анализировать количество перестановок на каждом шагу,\n\t\tесли это количество равно нулю, то продолжать сортировку нет смысла — массив отсортирован.\n\n";

				//Variables
				int arrSize, arrMin, arrMax, tmp;

				//Body

				// Вводим размер массива
				cout << " Enter array size: ";
				cin >> arrSize;

				// Вводим диапазон массива
				do {
					cout << " Enter min: ";
					cin >> arrMin;
					cout << " Enter max: ";
					cin >> arrMax;
				} while (arrMin > arrMax || arrSize > arrMax - arrMin);

				// Создаем массивы, выдиляем память под arrSize ячеек
				int* arrRand = new int[arrSize];

				// Заполняем массив рандомными числами в min - max диапазоне
				for (int i = 0; i < arrSize; i++) {
					arrRand[i] = rand() % (arrMax - arrMin) + arrMin;
					for (int k = 0; k < i; k++) {
						if (arrRand[i] == arrRand[k]) {
							arrRand[i] = rand() % (arrMax - arrMin) + arrMin;
							k = -1;
						}
					}
				}

				// Выводим массив на экран
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array[";
					}
					cout << arrRand[i];
					if (i == arrSize - 1) {
						cout << "] Before sort" << endl;
					}
					else {
						cout << ", ";
					}
				}

				int swap;
				// Сортировка массива Пузырьком "усовершенствованным"
				for (int a = 0; a < arrSize; a++) {

					swap = false;

					for (int i = 1; i < arrSize - a; i++) {
						if (arrRand[i - 1] > arrRand[i]) {
							tmp = arrRand[i];
							arrRand[i] = arrRand[i - 1];
							arrRand[i - 1] = tmp;

							swap = true;
						}
					}

					if (!swap) break;
				}

				// Выводим массив на экран и очищаем память
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array[";
					}
					cout << arrRand[i];
					if (i == arrSize - 1) {
						cout << "] After sort" << endl;
					}
					else {
						cout << ", ";
					}
				}
				delete[] arrRand;

				//Return?
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

		case '3':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 3:\tНаписать программу «справочник». Создать два одномерных массива.\n\t\tОдин массив хранит номера ICQ, второй — телефонные номера. Реализовать меню для пользователя.\n\n";

				//Variables
				int arrSize, tmpPhone, tmp, sortChoice;
				bool isSort = false;
				string userOperator;

				//Body

				// Вводим размер массива
				cout << " Enter size of the directory: ";
				cin >> arrSize;

				// Создаем массив, выдиляем память под arrSize ячеек
				int* arrICQ = new int[arrSize];
				int* arrPhone = new int[arrSize];
				int* arrUser = new int[arrSize];

				// Определяем диапазон рандомизации
				uniform_int_distribution<> randMT(100000000, 999999999);

				// Заполняем массив ICQ рандомными девятизначными числами
				for (int i = 0; i < arrSize; i++) {
					arrICQ[i] = randMT(rd);
					for (int k = 0; k < i; k++) {
						if (arrICQ[i] == arrICQ[k]) {
							arrICQ[i] = randMT(rd);
							k = -1;
						}
					}
				}  

				// Заполняем массив Phone рандомными девятизначными числами (не учитывая 380)
				for (int i = 0; i < arrSize; i++) {
					arrPhone[i] = randMT(rd);
					tmpPhone = arrPhone[i] / 10000000;
					if (tmpPhone != 39 && tmpPhone != 50 && tmpPhone != 63 && tmpPhone != 66 && tmpPhone != 67 && tmpPhone != 68 && tmpPhone != 92 && tmpPhone != 93 && tmpPhone != 94 && tmpPhone != 95 && tmpPhone != 96 && tmpPhone != 97 && tmpPhone != 98 && tmpPhone != 99) {
						i--;
						continue;
					}
					for (int k = 0; k < i; k++) {
						if (arrPhone[i] == arrPhone[k]) {
							arrPhone[i] = randMT(rd);
							k = -1;
						}
					}
				}

				// Заполняем номера пользователей
				for (int i = 0; i < arrSize; i++) {
					arrUser[i] = i + 1;
				}

				do {
					system("cls");
					cout << "\t \"Справочник\"\n [1] Отсортировать по номерам ICQ;\n [2] Отсортировать по номерам телефона;\n [3] Вывести список пользователей;\n\t\t   Выход [other number]\n\n";
					cout << " Enter: ";
					cin >> sortChoice;

					if (sortChoice != 1 && sortChoice != 2 && sortChoice != 3) break;

					// Сортировка массива взависимости от выбора пункра меню (Пузырьком)
					for (int a = 0; a < arrSize; a++) {
						for (int i = 1; i < arrSize - a; i++) {
							if		(sortChoice == 1 && arrICQ[i - 1] > arrICQ[i]) isSort = true;		// по ICQ
							else if (sortChoice == 2 && arrPhone[i - 1] > arrPhone[i]) isSort = true;	// по Phone
							else if (sortChoice == 3 && arrUser[i - 1] > arrUser[i]) isSort = true;		// по User
							else isSort = false;
							
							if (isSort) {
								tmp = arrICQ[i];
								arrICQ[i] = arrICQ[i - 1];
								arrICQ[i - 1] = tmp;

								tmp = arrPhone[i];
								arrPhone[i] = arrPhone[i - 1];
								arrPhone[i - 1] = tmp;

								tmp = arrUser[i];
								arrUser[i] = arrUser[i - 1];
								arrUser[i - 1] = tmp;
							}
						}
					}

					cout << "\n User\t| Phone - Operator\t\t| ICQ\n---------------------------------------------------------\n";
					for (int i = 0; i < arrSize; i++) {
							tmpPhone = arrPhone[i] / 10000000;
						if (tmpPhone == 50 || tmpPhone == 66 || tmpPhone == 95 || tmpPhone == 99) {
							userOperator = "Vodafone";
						}
						else if (tmpPhone == 63 || tmpPhone == 93) {
							userOperator = "Lifecell";
						}
						else if (tmpPhone == 91) {
							userOperator = "Utel";
						}
						else if (tmpPhone == 92) {
							userOperator = "PEOPLEnet";
						}
						else if (tmpPhone == 94) {
							userOperator = "Ukrtelecom";
						}
						else {
							userOperator = "Kyivstar";
						}
						cout << " " << arrUser[i] << "\t| +380" << arrPhone[i] << " - " << userOperator << "\t| " << arrICQ[i] << endl;
					}
					cout << endl;
					system("pause");
				} while (true);
				
				delete[] arrICQ;
				delete[] arrPhone;
				delete[] arrUser;
				//Return?
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

		case '2':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 2:\tНапишите программу, которая выполняет поэлементную сумму двух массивов\n\t\tи результат заносит в третий массив.\n\n";

				//Variables
				int arrSize, arrMin, arrMax;

				//Body

				// Вводим размер массива
				cout << " Enter array size: ";
				cin >> arrSize;

				// Вводим диапазон массива
				do {
					cout << " Enter min: ";
					cin >> arrMin;
					cout << " Enter max: ";
					cin >> arrMax;
				} while (arrMin > arrMax || arrSize > arrMax - arrMin);
		
				// Создаем массивы, выдиляем память под arrSize ячеек для каждого
				int* arrRand_1 = new int[arrSize];
				int* arrRand_2 = new int[arrSize];
				int* arrRand_3 = new int[arrSize];

				// Заполняем массивы рандомными числами в min - max диапазоне (
				for (int i = 0; i < arrSize; i++) {
					arrRand_1[i] = rand() % (arrMax - arrMin) + arrMin;
					arrRand_2[i] = rand() % (arrMax - arrMin) + arrMin;
					for (int k = 0; k < i; k++) {
						if (arrRand_1[i] == arrRand_1[k]) {
							arrRand_1[i] = rand() % (arrMax - arrMin) + arrMin;
							k = -1;
						}
						if (arrRand_2[i] == arrRand_2[k]) {
							arrRand_2[i] = rand() % (arrMax - arrMin) + arrMin;
							k = -1;
						}
					}
				}

				// Суммируем масив 1 и 2, результат записываем в 3
				for (int i = 0; i < arrSize; i++) {
					arrRand_3[i] = arrRand_1[i] + arrRand_2[i];
				}

				// Выводим массив 1 на экран и очищаем память
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array1[";
					}
					cout << arrRand_1[i];
					if (i == arrSize - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}
				delete[] arrRand_1;

				// Выводим массив 1 на экран и очищаем память
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array2[";
					}
					cout << arrRand_2[i];
					if (i == arrSize - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}
				delete[] arrRand_2;

				// Выводим массив 3 на экран и очищаем память
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array3[";
					}
					cout << arrRand_3[i];
					if (i == arrSize - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}
				delete[] arrRand_3;

				//Return?
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

				//Task description
				cout << "\n     Task 1:\tНаписать программу, копирующую последовательно элементы одного массива\n\t\tразмером 10 элементов в 2 массива размером 5 элементов каждый.\n\n";

				//Variables
				int const arrSize10 = 10, arrSize5 = 5;
				int array10[arrSize10], array5_1[arrSize5], array5_2[arrSize5];
				//Body

				// Заполняем массив рандомными числами (от 1 до 100)
				for (int i = 0; i < arrSize10; i++) {
					array10[i] = rand() % 100 + 1;
					for (int k = 0; k < i; k++) {
						if (array10[i] == array10[k]) {
							array10[i] = rand() % 100 + 1;
							k = -1;
						}
					}
				}

				// Выводим массив 10 на экран
				for (int i = 0; i < arrSize10; i++) {
					if (i == 0) {
						cout << "\n Array10[";
					}
					cout << array10[i];
					if (i == arrSize10 - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}

				// Последовательно делим массив 10 на два по 5
				for (int i = 0; i < arrSize10; i++) {
					if (i < 5) {
						array5_1[i] = array10[i];
					}
					else {
						array5_2[i - 5] = array10[i];
					}
				}
				
				// Выводим массив 5_1 на экран
				for (int i = 0; i < arrSize5; i++) {
					if (i == 0) {
						cout << "\n Array5.1[";
					}
					cout << array5_1[i];
					if (i == arrSize5 - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}

				// Выводим массив 5_2 на экран
				for (int i = 0; i < arrSize5; i++) {
					if (i == 0) {
						cout << "\n Array5.2[";
					}
					cout << array5_2[i];
					if (i == arrSize5 - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}

				//Return?
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
			cout << " Repiat command " << endl;
			break;
		}
	} while (useMenu);

	system("pause");
	return;
}
