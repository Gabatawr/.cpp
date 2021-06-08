#include "Header.h"

void rand_region_and_series(char*&, char*&);

struct num_car
{
	char* region;
	int number;
	char* series;
	
	num_car ()
	{
		number = rand() % 10000;
		region = nullptr; series = nullptr;
		rand_region_and_series(region, series);
	}

	~num_car()
	{
		delete[] region;
		delete[] series;
	}

	void print () const
	{
		str_echo(this->region); cout << " ";
		int tmp = this->number, c = 0;
		while (tmp > 0) { tmp /= 10; c++; }
		for (auto i = 0; i < 4 - c; i++) cout << "0";
		cout << this->number; cout << " ";
		str_echo(this->series);
	}
	
	void* operator [] (int index)
	{
		if (index == 0) return & *this->region;
		if (index == 1) return & this->number;
		if (index == 2) return & *this->series;
		return nullptr;
	}

};

void rand_color(char*& color);
void rand_model(char*& model);

struct car
{
	char* color;
	char* model;
	num_car number;
	
	car()
	{
		color = nullptr; rand_color(color);
		model = nullptr; rand_model(model);
	}

	~car()
	{
		delete[] color;
		delete[] model;
	}

	void print() const
	{
		cout << "\n Model: ";  str_echo(this->model);
		cout << "\n Number:[ "; this->number.print();
		cout << " ]\n Color: "; str_echo(this->color);
	}

	void edit()
	{
		cout << "\n Model: "; str_cin(this->model);
		
		cout << " Number:[ AA 0000 AA ]\b\b\b\b\b\b\b\b\b\b\b\b";
		char* new_number = str_cin();
		this->number.region[0] = new_number[0];
		this->number.region[1] = new_number[1];
		this->number.number = str_to_int(new_number);
		this->number.series[0] = new_number[8];
		this->number.series[1] = new_number[9];

		cout << " Color: "; str_cin(this->color);
	}
	
	friend num_car;
};


void do_task_2()
{
	do {
#pragma region Description
		system("cls");
		cout << "\n     Task 2:\t"
			<< "Реализовать структуру «Машина» (цвет, модель, номер)." << "\n\t\t"
			<< "Номер машины может представлять из себя или пятизначный номер или слово до 8 символов." << "\n\t\t"
			<< "*Рекомендации: номер реализовать как объединение" << "\n\n\t\t"
		
			<< "Создать экземпляр структуры «Машина» и реализовать для него следующие функции:" << "\n\t\t"
			<< " - Заполнение машины;" << "\n\t\t"
			<< " - Печать машины." << "\n\n\t\t"
			<< "Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие функции:" << "\n\t\t"
			<< " - Редактировать машину;" << "\n\t\t"
			<< " - Печать всех машин;" << "\n\t\t"
			<< " - Поиск машины по номеру." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
#pragma endregion

		int const count = 10;
		car* carlist = new car[count];
		
		int choice = 0;
		do
		{
			choice = -1;
			while (choice < 0 || choice > 2)
			{
				cout << "\n 1. Печать\n 2. Поиск по номеру\n 0. Выход\n Enter: _\b";
				cin >> choice;
			}
			if (choice == 0) continue;

			switch (choice)
			{
			case 1:
				for (auto i = 0; i < count; i++)
				{
					cout << "\n #" << i + 1;
					carlist[i].print();
					cout << "\n----------------------------------";
				}

			caredit:
				cout << "\n Меню #0; Редактировать #"; cin >> choice;
				if (choice > 0 && choice <= count) carlist[choice - 1].edit();
				if (choice == 0) choice = -1;
				break;

			case 2:
				choice = -1;
				while (choice < 0 || choice > 2)
				{
					cout << "\n 1. По региону или серии\n 2. По цифровому номеру\n 0. Назад\n Enter: _\b";
					cin >> choice;
				}
				if (choice == 0) { choice = -1; continue; }

				int index = choice - 1;

				if (choice == 1)
				{
					char* key = nullptr;
					do {
						cout << "\n Enter: __\b\b"; str_cin(key);
						str_uppercase(key);
					} while (str_len(key) > 2);
					
					bool trigger = false;
					for (auto j = 0; j < 2; j++)
					{
						for (auto i = 0; i < count; i++)
						{
							int c = str_count_word(static_cast<char*>(carlist[i].number[index]), key);
							if (c > 0)
							{
								cout << "\n #" << i + 1;
								carlist[i].print();
								cout << "\n----------------------------------";
								if (!trigger) trigger = true;
							}
						}
						index = 2;
					}
					delete[] key;
					if (trigger) goto caredit;
					cout << " Not found.\n";
				}
				
				if (choice == 2)
				{
					int key = 0;
					do {
						cout << "\n Enter: "; cin >> key;
					} while (key < 0 || key > 9999);
					
					bool trigger = false;
					for (auto i = 0; i < count; i++)
					{
						if (*static_cast<int*>(carlist[i].number[index]) == key)
						{
							cout << "\n #" << i + 1;
							carlist[i].print();
							cout << "\n----------------------------";
							if (!trigger) trigger = true;
						}
					}
					if (trigger) goto caredit;
					cout << " Not found.\n";
				}
				
				if (choice == 0) choice = -1;
				break;
			}
		} while (choice != 0);
		
		delete[] carlist;

	} while (task_restart());
}

void rand_region_and_series(char*& region, char*& series)
{
	const int count = 12;
	const int len_limit = 3;

	// Массив
	char data[count] = { 'A', 'B', 'E', 'I', 'K', 'M', 'H', 'O', 'P', 'C', 'T', 'X' };

	// Копируем в строку
	region = new char[len_limit];
	series = new char[len_limit];
	
	for (auto i = 0; i < len_limit; i++)
	{
		region[i] = data[rand() % 12];
		series[i] = data[rand() % 12];
		if (i == 2) region[i] = series[i] = '\0';
	}
}

void rand_color(char*& color)
{
	// Общее количество строк в массиве
	const int count = 10;
	const int len_limit = 7;

	// Массив
	const char* data[count] = {
 "Yellow"
,"Green"
,"Blue"
,"Brown"
,"White"
,"Red"
,"Orange"
,"Pink"
,"Gray"
,"Black"
	};

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	color = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') color[i] = data[n][i++];
	color[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(color);
}
void rand_model(char*& model)
{
	// Общее количество строк в массиве
	const int count = 13;
	const int len_limit = 27;

	// Массив
	const char* data[count] = {
  "Tesla Model 3 Standard"
, "Tesla Model 3 Long Range"
, "Tesla Model 3 Performance"
, "Tesla Model X P100D"
, "Tesla Model S P100D"
, "Tesla Model X 100D"
, "Tesla Model S 100D"
, "Tesla Model X 75D"
, "Tesla Model S 75D"
, "Tesla Model S 75"
, "Tesla Model Y"
, "Tesla Cybertruck"
, "Tesla Semi"
	};

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	model = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') model[i] = data[n][i++];
	model[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(model);
}
