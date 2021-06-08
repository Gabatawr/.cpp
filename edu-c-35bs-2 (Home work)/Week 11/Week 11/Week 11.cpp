/**
 * Week 11
 *
 * Theme:
 *   Функции.
 *
 * @author Artem Kashyrin
 *
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

#pragma execution_character_set( "utf-8" )

using namespace std;

// Task 1
int degree_calc(int num, int exp)
{
	uint32_t num_enter = num;
	for (int i = exp - 1; i > 0; i--) {
		num *= num_enter;
	}
	return num;
}

// Task 2
int range_sum_calc(int num_1, int num_2)
{
	if (num_1 > num_2) swap(num_1, num_2);
	
	int32_t range_sum = 0;
	for (int32_t i = num_1 + 1; i < num_2; i++) {
		range_sum += i;
	}
	return range_sum;
}

// Task 3
int fun_perfect_numbers(int num_1, int num_2)
{
	if (num_1 > num_2) swap(num_1, num_2);
	
	vector<int> arr_n, arr_d;
	for (int i = num_1; i <= num_2; i += 2) {
		if (i % 2 != 0) i++;
		if (i < 10 || i % 10 == 6 || i % 10 == 8) {

			for (int j = 1; j < i; j++)
				if (i % j == 0)
					arr_d.push_back(j);

			int sum = 0;

			for (int j = 0; j < int(arr_d.size()); j++)
				sum += arr_d[j];

			arr_d.clear();

			if (sum != 0 && sum == i)
				arr_n.push_back(i);

			cout << " " << i << "\r";
		}
	}
	
	if (int(arr_n.size()) == 0) cout << " Numbers not found..\n";
	for (int j = 0; j < int(arr_n.size()); j++) {
		if (j == 0) cout << " Numbers found: ";
			cout << arr_n[j];
		if (j != int(arr_n.size() - 1)) {
			cout << ", ";
		} else {
			cout << "." << endl;
		}
	}
	
	arr_n.clear();
	return 0;
}

// Task 4
int display_card(int suit, int card)
{
	string suit_arr[] = { "♠", "♥", "♣", "♦" };

	char card_symbol = ' ';
	bool card_ten = false;
	char card_arr[15] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', 'J', 'Q', 'K', 'A' };
	if (card == 10)
		card_ten = true;
	else {
		for (int i = 2; i <= 15; i++)
			if (card == i)
				card_symbol = card_arr[i];
	}

	cout << "\n ┏━━━━━━━━━┓" << endl;

	if (card_ten) cout << " ┃ " << "10" << suit_arr[suit - 1] << setw(5) << "" << "┃" << endl;
	else   cout << " ┃ " << card_symbol << suit_arr[suit - 1] << setw(6) << "" << "┃" << endl;

	cout << " ┃" << setw(9) << "" << "┃" << endl;
	cout << " ┃" << setw(9) << "" << "┃" << endl;

	cout << " ┃" << setw(4) << "" << suit_arr[suit - 1] << setw(4) << "" << "┃" << endl;

	cout << " ┃" << setw(9) << "" << "┃" << endl;
	cout << " ┃" << setw(9) << "" << "┃" << endl;

	if (card_ten) cout << " ┃" << setw(5) << "" << suit_arr[suit - 1] << "10" << " ┃" << endl;
	else   cout << " ┃" << setw(6) << "" << suit_arr[suit - 1] << card_symbol << " ┃" << endl;

	cout << " ┗━━━━━━━━━┛" << endl;
	return 0;
}

// Task 5
int check_for_luck(int n)
{
	vector<int> arr_n;
	for (int i = 0, tmp; i < 6; i++) {
		tmp = n % 10;
		arr_n.push_back(tmp);
		n /= 10;
	}
	if (arr_n[0] + arr_n[1] + arr_n[2] == arr_n[3] + arr_n[4] + arr_n[5]) {
		cout << " This number is lucky!\n";
	}
	else {
		cout << " This number is not lucky..\n";
	}
	arr_n.clear();
	return 0;
}

// Task a
int linear_search(int *arr_rand, int arr_size, int key)
{
	for (int i = 0; i < arr_size; i++) {
		if (arr_rand[i] == key) return i;
	}
	return -1;
}

// Task b
void quick_sort(int *arr_rand, int first, int last)
{
	int f = first;
	int l = last;
	int mid = arr_rand[(f + l) / 2];

	while (f < l) {
		while (arr_rand[f] < mid) f++;
		while (arr_rand[l] > mid) l--;
		if (f <= l) swap(arr_rand[f++], arr_rand[l--]);
	}

	if (first < l) quick_sort(arr_rand, first, l);
	if (f < last) quick_sort(arr_rand, f, last);
}

int binary_search(int *arr_rand, int first, int last, int key)
{
	while (first <= last) {
		int mid = (first + last) / 2;

		if (arr_rand[mid] == key) return mid;
		if (arr_rand[mid] > key) last = mid - 1;
		else first = mid + 1;
	}
	return -1;
}

// Task c
int converter_bin_to_dec(string str_num)
{
	int dec = 0;
	for (int i = int(str_num.size()) - 1, j = 1; i >= 0; i--, j *= 2) {
		if (str_num[i] == '1') dec += j;
		else if (str_num[i] == '0') dec += 0;
		else return -1;
	}
	return dec;
}

// Repeat
bool fun_use_task()
{
	bool use_task = true;
	bool repeatCommand;
	do {
		cout << "\n Try again? y/n" << endl;
		cout << " Enter: ";
		char taskAgain;
		cin >> taskAgain;
		if (taskAgain == 'y' || taskAgain == 'Y') {
			use_task = true;
			repeatCommand = false;
		}
		else if (taskAgain == 'n' || taskAgain == 'N') {
			use_task = false;
			repeatCommand = false;
		}
		else {
			cout << " Repiat command " << endl;
			repeatCommand = true;
		}
	} while (repeatCommand);
	return use_task;
}

void main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	srand(time(0));

	bool use_menu = true;
	bool use_task;
	
	do {
		system("cls");

		cout << "\n ┏━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		cout   << " ┃    Tasks of week 11    ┃" << endl;
		cout   << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout   << " ┃ Task 1\t\t  ┃" << endl;
		cout   << " ┃ Task 2\t\t  ┃" << endl;
		cout   << " ┃ Task 3\t\t  ┃" << endl;
		cout   << " ┃ Task 4\t\t  ┃" << endl;
		cout   << " ┃ Task 5\t\t  ┃" << endl;
		cout   << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout   << " ┃        Optional        ┃" << endl;
		cout   << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout   << " ┃ Task a\t\t  ┃" << endl;
		cout   << " ┃ Task b\t\t  ┃" << endl;
		cout   << " ┃ Task c\t\t  ┃" << endl;
		cout   << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout   << " ┃ 0 or q - exit\t  ┃" << endl;
		cout   << " ┗━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		
		cout << "\n Enter Task: #";
		char userChoice;
		cin >> userChoice;

		switch (userChoice) {

		case 'c':
			do {
				system("cls");

				// Task description
				cout << "\n     Task c:\t"
					<< "Написать функцию для перевода числа, записанного в двоичном виде, в десятичное представление." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				string str_num;
				cout << " Enter the number in binary form :";
				cin >> str_num;

				int dec = converter_bin_to_dec(str_num);
				
				if (dec > -1) cout << " " << str_num << " = " << dec << endl;
				else cout << " Error, only characters 0 and 1 are allowed";

				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case 'b':
			do {
				system("cls");

				// Task description
				cout << "\n     Task b:\t"
					<< "Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				int arr_size;
				cout << " Enter array size: ";
				cin >> arr_size;
				
				int min, max;
				char line = ' ';
				do {
					cout << " Enter min-max: ";
					cin >> min >> line >> max;
				} while (line != '-' || max < min || arr_size > max - min);

				int key;
				do {
					cout << " Enter search key: ";
					cin >> key;
				} while (key < min || key > max);

				int* arr_rand = new int[arr_size];
				
				for (int i = 0; i < arr_size; i++) {
					arr_rand[i] = (rand() % max - min) + min;
					for (int j = 0; j < i; j++) {
						if (arr_rand[i] == arr_rand[j]) {
							arr_rand[i] = (rand() % max - min) + min;
							j = -1;
						}
					}
				}
				
				int first = 0;
				int last = arr_size - 1;
				
				quick_sort(arr_rand, first, last);
				int pos_key = binary_search(arr_rand, first, last, key);

				if (pos_key == -1) cout << "\n This key was not found in the array\n";
				else cout << "\n The key is at " << pos_key << " positions in the array\n";
				
				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case 'a':
			do {
				system("cls");

				// Task description
				cout << "\n     Task a:\t"
					<< "Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				int arr_size;
				cout << " Enter array size: ";
				cin >> arr_size;

				int min, max;
				char line = ' ';
				do {
					cout << " Enter min-max: ";
					cin >> min >> line >> max;
				} while (line != '-' || max < min || arr_size > max - min);

				int key;
				do {
					cout << " Enter search key: ";
					cin >> key;
				} while (key < min || key > max);
				
				int* arr_rand = new int[arr_size];

				for (int i = 0; i < arr_size; i++) {
					arr_rand[i] = (rand() % max - min) + min;
					for (int j = 0; j < i; j++) {
						if (arr_rand[i] == arr_rand[j]) {
							arr_rand[i] = (rand() % max - min) + min;
							j = -1;
						}
					}
				}
				
				int pos_key = linear_search(arr_rand, arr_size, key);
				
				if (pos_key == -1) cout << "\n This key was not found in the array\n";
				else cout << "\n The key is at " << pos_key << " positions in the array\n";
				
				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case '5':
			do {
				start_task_5:
				system("cls");

				// Task description
				cout << "\n     Task 5:\t"
					<< "Написать функцию, которая определяет, является ли «счастливым» шестизначное число." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				int n;
				cout << "\n Enter six digit number: ";
				cin >> n;
				if (100000 > n || n > 999999) goto start_task_5;

				check_for_luck(n);
				
				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case '4':
			do {
				system("cls");

				// Task description
				cout << "\n     Task 4:\t"
					<< "Написать функцию, выводящую на экран переданную ей игральную карту" << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				bool input_error;
				
				int suit;
				do {
					input_error = false;
					cout << " Enter suit 1(♠), 2(♥), 3(♣), 4(♦) : ";
					cin >> suit;
					if (suit < 1 || suit > 4) {
						cout << "\n\n Input Error!\n";
						input_error = true;
					}
				} while (input_error);
				
				int card;
				do {
					input_error = false;
					cout << " Enter card 2..10 or 11(J), 12(Q), 13(K), 14(A) : ";
					cin >> card;
					if (card < 2 || card > 14) {
						cout << "\n\n Input Error!\n";
						input_error = true;
					}
				} while (input_error);
				
				display_card(suit, card);

				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case '3':
			do {
				system("cls");

				// Task description
				cout << "\n     Task 3:\t"
					<< "Число называется совершенным, если сумма всех его делителей равна ему самому." << "\n\t\t"
					<< "Напишите функцию поиска таких чисел во введенном интервале." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				int num_1, num_2;
				char w = ' ';
				do {
					cout << " Enter range n-n: ";
					cin >> num_1 >> w >> num_2;
				} while (w != '-');

				fun_perfect_numbers(num_1, num_2);

				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case '2':
			do {
				system("cls");

				// Task description
				cout << "\n     Task 2:\t"
					<< "Написать функцию, которая получает в качестве параметров 2 целых числа" << "\n\t\t"
					<< "и возвращает сумму чисел из диапазона между ними." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";

				// Body
				cout << " Enter number one: ";
				int32_t num_1;
				cin >> num_1;

				cout << " Enter number two: ";
				int32_t num_2;
				cin >> num_2;
				
				int32_t sum = range_sum_calc(num_1, num_2);

				cout << " Sum of numbers between " << num_1 << "..." << num_2 << " = " << sum << endl;

				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case '1':
			do {
				system("cls");

				// Task description
				cout << "\n     Task 1:\t"
					<< "Написать функцию, которая принимает два параметра: основание степени и показатель степени," << "\n\t\t"
					<< "и вычисляет степень числа на основе полученных данных." << "\n"
					<< "_____________________________________________________________________________________________________________" << "\n\n";
	
				// Body
				cout << " Enter number: ";
				uint32_t num;
				cin >> num;

				cout << " Enter exponent: ";
				uint32_t exp;
				cin >> exp;
				
				uint32_t num_exp = degree_calc(num, exp);
				
				cout << " " << num << "^" << exp << " = " << num_exp << endl;
				
				// Repeat
				use_task = fun_use_task();
			} while (use_task);
			break;

		case 'q':
		case 'Q':
		case '0':
			use_menu = false;
			break;

		default:
			cout << " Repeat command " << endl;
			break;
		}
	} while (use_menu);

	system("pause");
}
