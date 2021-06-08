/**
 * Week 12
 *
 * Theme:
 *   Функции. Передача массивов внутрь функции.
 *
 * @author Artem Kashyrin
 *
*/

#include "my-lib_of_week-12.h"

void main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand(time(0));
	
	while (true) 
	{
		system("cls");

		cout << endl;
		cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		cout << " ┃    Tasks of week 12    ┃" << endl;
		cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout << " ┃ Task 1\t\t  ┃" << endl;
		cout << " ┃ Task 2\t\t  ┃" << endl;
		cout << " ┃ Task 3\t\t  ┃" << endl;
		cout << " ┃ Task 4\t\t  ┃" << endl;
		cout << " ┃ Task 5\t\t  ┃" << endl;
		cout << " ┃ Task 6\t\t  ┃" << endl;
		cout << " ┣━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
		cout << " ┃ 0 - exit\t\t  ┃" << endl;
		cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

		cout << "\n Enter Task: #_\b";
		char u_enter;
		cin >> u_enter;

		switch (u_enter) {

		case '6':
			do {
				system("cls");
				// description
				cout << "\n     Task 5:\t"
					<< "Написать игру «Быки и коровы»." << "\n\t\t"
					<< "Программа «загадывает» четырёхзначное число и играющий должен угадать его." << "\n\t\t"
					<< "После ввода пользователем числа программа сообщает:" << "\n\t\t"
					<< "> Cколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы)." << "\n\t\t"
					<< "После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток." << "\n\t\t"
					<< "В программе необходимо использовать рекурсию." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body

				cout << " Go play =)";
				cout << " Enter number: ****\b\b\b\b";
				int u_num;
				cin >> u_num;
				game_task6_start(u_num);
				
			} while (restart_task());
			break;
		case '5':
			do {
				system("cls");
				// description
				cout << "\n     Task 5:\t"
					<< "Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				int n1, n2;
				cout << " Enter number one: ";
				cin >> n1;
				cout << " Enter number two: ";
				cin >> n2;

				cout << "\n Largest common divisor of numbers " << n1 << " and " << n2 << " = " << common_factor_2num(n1, n2) << endl;

			} while (restart_task());
			break;

		case '4':
			do {
				system("cls");
				// description
				cout << "\n     Task 4:\t"
					<< "Написать шаблонные функции (int, double, char) для выполнения следующих задач:" << "\n\t\t"
					<< " - Инициализация квадратной матрицы;" << "\n\t\t"
					<< " - Вывод матрицы на экран;" << "\n\t\t"
					<< " - Определение максимального и минимального элемента на главной диагонали матрицы;" << "\n\t\t"
					<< " - Сортировка элементов по возрастанию отдельно для каждой строки матрицы." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				char u_type;
				cout << " Enter used type [i - int; d - double; c - char] : _\b";
				cin >> u_type;
				if (u_type != 'i' && u_type != 'd' && u_type != 'c') {
					cout << " Invalid command.." << endl;
					continue;
				}
				
				bool use_def_set;
				cout << " Use defaults setting? (0 / 1): _\b";
				cin >> use_def_set;

				int mx_type = 0;
				if (u_type == 'c') fun_task_4(char(mx_type), use_def_set); 
				else if (u_type == 'i') fun_task_4(mx_type, use_def_set);
				else if (u_type == 'd') fun_task_4(double(mx_type), use_def_set);
				
			} while (restart_task());
			break;

		case '3':
			do {
				system("cls");
				// description
				cout << "\n     Task 3:\t"
					<< "Написать функцию, определяющую количество:" << "\n\t\t"
					<< "положительных, отрицательных и нулевых элементов передаваемого ей массива." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				bool using_floating;
				double d = 0.0;
				int i = 0;

				cout << " Use a floating number? (0 / 1): _\b";
				cin >> using_floating;

				if (using_floating) {
					int accuracy;
					cout << " Enter fractional accuracy: ";
					cin >> accuracy;
					fun_task_3(d, accuracy);
				}
				else fun_task_3(i);
				
			} while (restart_task());
			break;
			
		case '2':
			do {
				system("cls");
				// description
				cout << "\n     Task 2:\t"
					<< "Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				bool using_floating;
				double d = 0.0;
				int i = 0;
				
				cout << " Use a floating number? (0 / 1): _\b";
				cin >> using_floating;
				
				if (using_floating) {
					int accuracy;
					cout << " Enter fractional accuracy: ";
					cin >> accuracy;
					fun_task_2(d, accuracy);
				}
				else fun_task_2(i);
				
			} while (restart_task());
			break;
			
		case '1':
			do {
				system("cls");
				// description
				cout << "\n     Task 1:\t"
					<< "Написать функцию, которая принимает две даты и вычисляет разность в днях между этими датами." << "\n\t\t"
					<< "Для решения этой задачи необходимотакже написать функцию, определяющую, является ли год високосным." << "\n"
					<< "___________________________________________________________________________________________________________________" << "\n\n";
				// body
				char slash;
				int d1_d, d1_m, d1_y, d2_d, d2_m, d2_y;

				do {
					cout << "\n Enter first date: dd/mm/yyyy\b\b\b\b\b\b\b\b\b\b";
					cin >> d1_d >> slash >> d1_m >> slash >> d1_y;
				} while (check_date_for_errors(d1_d, d1_m, d1_y));
				
				do {
					cout << "\n Enter second date: dd/mm/yyyy\b\b\b\b\b\b\b\b\b\b";
					cin >> d2_d >> slash >> d2_m >> slash >> d2_y;
				} while (check_date_for_errors(d2_d, d2_m, d2_y));
				
				cout << "\n___________________________________________________________________________________________________________________\n"
					 << "\n Between first and second date " << days_between_dates(d1_d, d1_m, d1_y, d2_d, d2_m, d2_y) << " days\n\n";
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
