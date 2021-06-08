/**
 * Week 8
 *
 * Theme:
 *   Циклы && Массивы одномерные.
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
		cout << "|    Tasks of week 8\t" << "|" << endl;
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
				cout << "\n     Task 5:\tВ одномерном массиве, состоящем из N вещественных чисел вычислить:\n\t\t  - Сумму отрицательных элементов.\n\t\t  - Произведение элементов, находящихся между min и max элементами. (кроме 0)\n\t\t  - Произведение элементов с четными номерами. (кроме 0)\n\t\t  - Сумму элементов, находящихся между первым и последним отрицательными элементами.\n\n";

				//Variables
				int arrSize, arrMin, arrMax, valMin, valMax, posMin, posMax, tmp, userRangeMin, userRangeMax, sumNegative, sumNegativeFirstLast;
				long long int multRange = 1, multEven = 1;
				bool trigerMin;

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

				cout << "\n----------------------------------------------------------\n";

				// Создаем массив, выдиляем память под arrSize ячеек
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

				// Клонируем массив
				int* arrClone = new int[arrSize];
				for (int i = 0; i < arrSize; i++) {
					arrClone[i] = arrRand[i];
				}

				// Вывод массива на экран
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array[";
					}
					cout << arrRand[i];
					if (i == arrSize - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}

				// Сортировка массива Пузырьком
				for (int a = 0; a < arrSize; a++) {
					for (int i = 1; i < arrSize - a; i++) {
						if (arrRand[i - 1] > arrRand[i]) {
							tmp = arrRand[i];
							arrRand[i] = arrRand[i - 1];
							arrRand[i - 1] = tmp;
						}
					}
				}

				// Вывод массива на экран
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

				// Суммируем  отрицательные числа, если такие есть
				if (arrRand[0] < 0) {
					sumNegative = 0;
					for (int i = 0; arrRand[i] < 0; i++) {
						sumNegative += arrRand[i];
					}
					cout << "\n----------------------------------------------------------\n";
					cout << "\n Sum of negative numbers = " << sumNegative << endl;
				}
				else {
					cout << "\n----------------------------------------------------------\n";
					cout << "\n Negative numbers not finde..";
				}

				// Ввод диапазона умножения
				cout << "\n----------------------------------------------------------\n";
				cout << "\n Range for multiplication";
				do {
					cout << "\n Enter min: ";
					cin >> userRangeMin;
					cout << " Enter max: ";
					cin >> userRangeMax;
				} while (userRangeMin > userRangeMax || arrSize < userRangeMax - userRangeMin || userRangeMin < 0);

				// Перемножаем все числа в диапазоне
				for (int i = userRangeMin; i <= userRangeMax; i++) {
					if (arrClone[i] == 0) {
					}
					else {
						multRange *= arrClone[i];
					}
				}
				cout << "\n Range multiplication = " << multRange << endl;

				// Перемножаем четные числа
				for (int i = 0; i < arrSize; i++) {
					if (arrRand[i] % 2 == 0) {
						if (arrRand[i] == 0) {
						}
						else {
							multEven *= arrRand[i];
						}
					}
				}
				cout << "\n----------------------------------------------------------\n";
				cout << "\n Even multiplication = " << multEven << endl;

				// Ищем диапазон от первого до последнего отрицательного числа
				trigerMin = true;
				for (int i = 0; i < arrSize; i++) {
					if (arrClone[i] < 0 && trigerMin) {
						trigerMin = false;
						posMin = i;
					}
					else if (arrClone[i] < 0) {
						posMax = i;
					}
				}
				sumNegativeFirstLast = 0;
				// И суммируем числа диапазона
				for (int i = posMin; i <= posMax; i++) {
					sumNegativeFirstLast += arrClone[i];
				}
				cout << "\n----------------------------------------------------------\n";
				cout << "\n Sum between the first and last negative number = " << sumNegativeFirstLast << endl;
				cout << "\n----------------------------------------------------------\n";

				// Очищаем выдиленную память массива
				delete[] arrRand;
				delete[] arrClone;

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

		case '4':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 4:\tПользователь вводит прибыль фирмы за год (12 месяцев).\n\t\tЗатем пользователь вводит диапазон (например, 3 и 6 — поиск между 3-м и 6-м месяцем).\n\t\tНеобходимо определить месяц, в котором прибыль была максимальна и месяц,\n\t\tв котором прибыль была минимальна с учетом выбранного диапазона.\n\n";

				//Variables
				int rangeMin, rangeMax, valMin, valMax, posMin, posMax;
				int const arrSize = 12;

				//Body
				cout << " Enter profit for each month starting in January, etc.\n\n";
				double arrProfit[arrSize];
				for (int i = 0; i < arrSize; i++) {
					cout << " ";
					cin >> arrProfit[i];
				}

				cout << "\n Enter search range (1 - 12).\n With: ";
				cin >> rangeMin;
				if (rangeMin < 1) {
					rangeMin = 0;
				}
				else {
					rangeMin--;
				}
				cout << " By: ";
				cin >> rangeMax;
				if (rangeMax > 12) {
					rangeMax = 11;
				}
				else {
					rangeMax--;
				}

				for (int i = rangeMin; i <= rangeMax; i++) {
					if (i == rangeMin) {
						valMin = arrProfit[i];
						posMin = i;
						valMax = arrProfit[i];
						posMax = i;
					}
					else if (valMin > arrProfit[i]) {
						valMin = arrProfit[i];
						posMin = i;
					}
					else if (valMax < arrProfit[i]) {
						valMax = arrProfit[i];
						posMax = i;
					}
				}

				cout << "\n Minimum in " << ++posMin << " month = " << valMin << endl;
				cout << " Maximum in " << ++posMax << " month = " << valMax << endl;

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

		case '3':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 3:\tВ одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы.\n\n";

				//Variables
				int arrSize, min, max, valMin, valMax, posMin, posMax;

				//Body

				// Вводим размер массива
				cout << " Enter array size: ";
				cin >> arrSize;

				// Вводим диапазон массива
				do {
					cout << " Enter min: ";
					cin >> min;
					cout << " Enter max: ";
					cin >> max;
				} while (min > max || arrSize > max - min || min < 0);

				// Создаем массив, выдиляем память под arrSize ячеек
				int* arrRand = new int[arrSize];

				// Заполняем массив рандомными числами в min - max диапазоне
				for (int i = 0; i < arrSize; i++) {
					arrRand[i] = rand() % (max - min) + min;
					for (int k = 0; k < i; k++) {
						if (arrRand[i] == arrRand[k]) {
							arrRand[i] = rand() % (max - min) + min;
							k = -1;
						}
					}
				}

				// Вывод массива на экран
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						cout << "\n Array[";
					}
					cout << arrRand[i];
					if (i == arrSize - 1) {
						cout << "]" << endl;
					}
					else {
						cout << ", ";
					}
				}

				// Поиск мин и мах значений
				for (int i = 0; i < arrSize; i++) {
					if (i == 0) {
						valMin = arrRand[i];
						posMin = i;
						valMax = arrRand[i];
						posMax = i;
					}
					else if (valMin > arrRand[i]) {
						valMin = arrRand[i];
						posMin = i;
					}
					else if (valMax < arrRand[i]) {
						valMax = arrRand[i];
						posMax = i;
					}
				}

				// Вывод мин мах на экран
				cout << "\n Min: Array[" << posMin << "]" << " = " << valMin << endl;
				cout << " Max: Array[" << posMax << "]" << " = " << valMax << endl;

				// Очищаем выдиленную память массива
				delete[] arrRand;
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

		case '2':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 2:\tНаписать игру «Кубики». Пользователь и ком-пьютер по очереди бросают 2 кубика.\n\t\tПобедитель — тот, у кого по результатам 3х бросков сумма больше. Предусмотреть красивый интерфейс игры.\n\n";

				//Variables
				int userSum, compSum, randTmp;
				int speed = 123;
				//Body

				string arrLine[6];

				arrLine[0] = "  ------- \n";
				arrLine[1] = " | *   * |\n";
				arrLine[2] = " | *     |\n";
				arrLine[3] = " |     * |\n";
				arrLine[4] = " |   *   |\n";
				arrLine[5] = " |       |\n";

				userSum = 0;
				compSum = 0;

				for (int i = 1; i <= 3; i++) {

					Sleep(speed);	cout << endl << " Game " << i; Sleep(speed * 10); cout << "."; Sleep(speed * 10); cout << "."; Sleep(speed * 10); cout << "."; Sleep(speed * 10); cout << "." << endl;

					for (int k = 0; k < 4; k++) {

						randTmp = (rand() % 6) + 1;

						if (k <= 1) {
							userSum += randTmp;
							if (k == 0) {
								Sleep(speed * 5); cout << "\n   User\n";
							}
						}
						else {
							compSum += randTmp;
							if (k == 2) {
								Sleep(speed * 5); cout << "\n   Comp\n";
							}
						}

						Sleep(speed * 10); cout << arrLine[0];

						if (randTmp == 1) {
							Sleep(speed); cout << arrLine[5]; Sleep(speed); cout << arrLine[4]; Sleep(speed); cout << arrLine[5];
						}
						else if (randTmp == 2) {
							Sleep(speed); cout << arrLine[5]; Sleep(speed); cout << arrLine[1]; Sleep(speed); cout << arrLine[5];
						}
						else if (randTmp == 3) {
							Sleep(speed); cout << arrLine[2]; Sleep(speed); cout << arrLine[4]; Sleep(speed); cout << arrLine[3];
						}
						else if (randTmp == 4) {
							Sleep(speed); cout << arrLine[1]; Sleep(speed); cout << arrLine[5]; Sleep(speed); cout << arrLine[1];
						}
						else if (randTmp == 5) {
							Sleep(speed); cout << arrLine[1]; Sleep(speed); cout << arrLine[4]; Sleep(speed); cout << arrLine[1];
						}
						else {
							Sleep(speed); cout << arrLine[1]; Sleep(speed); cout << arrLine[1]; Sleep(speed); cout << arrLine[1];
						}

						Sleep(speed); cout << arrLine[0];
					}
				}

				Sleep(speed * 5); cout << "__________________________________________\n Total:\t\tUser - " << userSum << "\tComp - " << compSum << endl;
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

		case '1':
			do {
				system("cls");

				//Task description
				cout << "\n     Task 1:\tНаписать программу, которая выводит на экран линию заданным символом,\n\t\tвертикальную или горизонтальную, причем линия может выводиться быстро, нормально и медленно.\n";

				//Variables
				char symbol;
				int speed, pos, len;

				//Body

				do {
					cout << "\n Line length | Enter: ";
					cin >> len;
				} while (len < 1);

				cout << "\n Line symbol | Enter: ";
				cin >> symbol;

				do {
					cout << "\n Line position [1|Vertical; 2|Horizontal] | Enter: ";
					cin >> pos;
				} while (pos > 2 || pos < 1);

				do {
					cout << "\n Line output speed [1|Fast; 2|Normar; 3|Slow] | Enter: ";
					cin >> speed;
				} while (speed > 3 || speed < 1);

				for (int i = 0; i < len; i++) {
					if (i == 0 && pos == 2) { cout << "\n ["; }
					else if (i == 0 && pos == 1) { cout << "\n___\n\n"; }
					if (pos == 1) { cout << " "; }

					cout << symbol; // output
					Sleep(speed * 100);   // wait

					if (pos == 1) { cout << "\n"; }
					if (i == len - 1 && pos == 2) { cout << "]\n"; }
					else if (i == len - 1 && pos == 1) { cout << "___\n"; }
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