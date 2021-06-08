#include "header.h"

String rand_number()
{
	char data[12] = { 'A', 'B', 'E', 'I', 'K', 'M', 'H', 'O', 'P', 'C', 'T', 'X' };
	String res;
	
	for (auto i = 0; i < 2; i++) res += data[rand() % 2]; // 12 def
	
	res += String(' ') + String(rand() % (9999 - 1000) + 1000) + String(' ');
	
	for (auto i = 0; i < 2; i++) res += data[rand() % 2]; // 12 def

	return res;
}

int main()
{
#pragma region Presetting

	srand(time(0));
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

#pragma endregion

#pragma region Description

	/*
	 * Тема.
	 *   Бинарное дерево.
	 *   
	 * Задание.
	 *   Реализовать базу данных ГАИ по штрафным квитанциям с помощью бинарного дерева.
	 *   Ключом будет служить номер автомашины, значением узла — список правонарушений.
	 *   Если квитанция добавляется в первый раз, то в дереве появляется новый узел,
	 *   а в списке данные по правонарушению; если нет, то данные заносятся в существующий список.
	 *   
	 *   Необходимо также реализовать следующие операции:
	 *   • Полная распечатка базы данных (по номерам машин и списку правонарушений, числящихся за ними);
	 *   • Распечатка данных по заданному номеру;
	 *   • Распечатка данных по диапазону номеров.
	 */

#pragma endregion 
	
	do { system("cls");

		BTree<List<String*>*, String> database;
		
		for (auto i = 0; i < 10000; i++)
		{
			String key = rand_number();
			
			if (not database.has(key)) database.add(new List<String*>(new String(String("New violation! ") + String(i))), key);
			else database[key]->push_tail(new String(String("Add violation! ") + String(i)));
		}

		while (true)
		{
			std::cout << "\n Print     |";
			std::cout << "\n-----------+---";
			std::cout << "\n all       | 1";
			std::cout << "\n by number | 2";
			std::cout << "\n range     | 3";
			std::cout << "\n-----------: _\b";

			char change; std::cin >> change;

			if (change == '0') break;
			if (change == '1')
			{
				std::cout << "\n\n";
				database.print();
			}
			else if (change == '2')
			{
				std::cout << "\n Enter number: ";
				String key; std::cin >> key;
				std::cout << "\n\n";
				
				std::cout << *(database[key]);
			}
			else if (change == '3')
			{
				std::cout << "\n Enter first number: ";
				String key_f; std::cin >> key_f;
				std::cout << "\n Enter last number: ";
				String key_l; std::cin >> key_l;
				std::cout << "\n\n";

				database.print(key_f,key_l);
			}
			else 
			{
				std::cout << "\n Invalid command.. ";
				system("pause");
			}
		}
		
	} while (restart());
}