/**
* @author Artem Kashyrin
*
*/

#include "stdafx.h"

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

	char taskAgain;
	bool useTask = true;
	bool repiatCommand = false;

	do {

		//Variables
		int countGames, numberGames, countIteration, numberIteration, cases, countCases, x, prizeBox, openBox, userBox, userBox_2, toChange_won, toChange_loss, noChange_won, noChange_loss;
		double toChange_won_ave, toChange_loss_ave, noChange_won_ave, noChange_loss_ave, toChange_won_aveProcent, toChange_loss_aveProcent, noChange_won_aveProcent, noChange_loss_aveProcent;
		bool isWas, isLast, isEveryChance, isLast�hance = false;

		//Body
		cout << "\n ������� ���������� ���: ";
		cin >> numberGames;

		cout << " ������� ���������� ��������: ";
		cin >> numberIteration;

		cout << " ������� ���������� ������: ";
		cin >> cases;
		int* arrCases = new int[cases];

		cout << " ������ �����: [1] ��� ������ �����������; [0] ������ ��� ���������; ������� 1 ��� 0: ";
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
						isLast�hance = countCases == 2;
					}

					if (isEveryChance || isLast�hance) {

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

			cout << "\n ��������: " << countIteration << " �� " << numberIteration << endl << endl;
			cout << " � ���������� ������:" << "\n �����: " << toChange_won << "\t ���������: " << toChange_loss << endl << endl;

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

			cout << " ��� ��������� ������:" << "\n �����: " << noChange_won << "\t ���������: " << noChange_loss << endl << "---------------------------------------------";

			countIteration++;
		} while (countIteration <= numberIteration);

		toChange_won_aveProcent = (toChange_won_ave / numberGames) * 100;
		toChange_loss_aveProcent = (toChange_loss_ave / numberGames) * 100;
		noChange_won_aveProcent = (noChange_won_ave / numberGames) * 100;
		noChange_loss_aveProcent = (noChange_loss_ave / numberGames) * 100;

		cout << "\n\n\n\n\n ����� � ������� �� ��� ����: \n\n � ���������� ������:\n �����: " << toChange_won_aveProcent << "% \t ���������: " << toChange_loss_aveProcent << "%\n\n ��� ��������� ������:\n �����: " << noChange_won_aveProcent << "% \t ���������: " << noChange_loss_aveProcent << "%\n\n\n\n";

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
		delete[] arrCases;
	} while (useTask);

	system("pause");
	return;
}