#include "Header.h"

enum tetrapods { unknown, human , bird, cattle };

char* rand_human_skin()
{
	// Общее количество строк в массиве
	const int count = 6;
	const int len_limit = 18;

	// Массив
	const char* data[count] = { "Celtic", "Nordic", "Dark European", "Mediterranean", "Indonesian", "African American" };

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	char* str = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') str[i] = data[n][i++];
	str[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(str);
	
	return str;
}
char* rand_bird_color()
{
	// Общее количество строк в массиве
	const int count = 19;
	const int len_limit = 13;

	// Массив
	const char* data[count] = { "Black", "Yellow", "Brown", "Olive", "Buff",
								"Green", "Tan", "Blue", "Rufous", "Rust",
								"Purple", "Violet", "Red", "Gray", "Pink",
								"White", "Orange", "Sheen", "Iridescence" };

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	char* str = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') str[i] = data[n][i++];
	str[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(str);

	return str;
}

struct organism
{
	tetrapods group;
	double walking_speed;
	char* color;
	void* feature;
	char* feature_description;

	organism()
	{
		group = unknown;
		walking_speed = 0;
		color = nullptr;
		feature = nullptr;
		feature_description = nullptr;
	}

	~organism ()
	{
		delete[] color;
		delete[] feature_description;
		
		if      (group == human)  delete[] static_cast<int*>(feature);
		else if (group == bird)   delete[] static_cast<double*>(feature);
		else if (group == cattle) delete[] static_cast<bool*>(feature);
	}

	void randomized (tetrapods group = unknown)
	{
		if (group == unknown) this->group = tetrapods(rand() % 3 + 1);

		if (this->group == human)
		{
			this->walking_speed = static_cast<double>(rand() % 3 + 3 + static_cast<double>(rand() % 10) / 10);
			
			delete[] this->color;
			this->color = rand_human_skin();
			
			delete[] static_cast<int*>(this->feature);
			this->feature = new int[1]{ rand() % (130 - 70) + 70 };
			
			delete[] this->feature_description;
			this->feature_description = new char[03]{ "IQ" };
		}
		else if (this->group == bird)
		{
			this->walking_speed = static_cast<double>(rand() % 3 + static_cast<double>(rand() % 10) / 10);

			delete[] this->color;
			this->color = rand_bird_color();

			delete[] static_cast<double*>(this->feature);
			this->feature = new double[1]{ static_cast<double>(rand() % (100 - 40) + 40 + static_cast<double>(rand() % 100) / 100) };
			
			delete[] this->feature_description;
			this->feature_description = new char[13]{ "Flight speed" };
		}
		else if(this->group == cattle)
		{
			this->walking_speed = static_cast<double>(rand() % 10 + static_cast<double>(rand() % 10) / 10);
			
			delete[] this->color;
			this->color = rand_bird_color();
			
			delete[] static_cast<bool*>(this->feature);
			this->feature = new bool[1]{ static_cast<bool>(rand() % 2) };

			delete[] this->feature_description;
			this->feature_description = new char[14]{ "Artiodactyla?" };
		}
	}

	void edit()
	{
		cout << " Organism:";

		bool error; char* u_group = nullptr;
		do {
			error = false;
			delete[] u_group; u_group = nullptr;
			cout << "\n - Group: "; str_cin(u_group); str_lowercase(u_group);
			if      (str_compare_content(u_group, (char*)"human"))  this->group = human;
			else if (str_compare_content(u_group, (char*)"bird"))   this->group = bird;
			else if (str_compare_content(u_group, (char*)"cattle")) this->group = cattle;
			else { cout << " Error! Group:[human, bird, cattle]"; error = true; }
		} while (error);
		delete[] u_group;
		
		cout << " - Walking speed: "; cin >> this->walking_speed;

		this->group == human  ? cout << " - Skin type: " :
		this->group == bird   ? cout << " - Feather color: " :
		this->group == cattle ? cout << " - Skin color: " : cout << "\n - Error!: ";
		this->color = str_cin(); str_lowercase(this->color); str_up_begin(this->color);

		delete[] this->feature_description;
		this->group == human  ? this->feature_description = new char[03]{ "IQ" } :
		this->group == bird   ? this->feature_description = new char[13]{ "Flight speed" } :
		this->group == cattle ? this->feature_description = new char[14]{ "Artiodactyla?" } : this->feature_description = nullptr;
		cout << " - "; str_echo(this->feature_description); cout << ": ";

		if (group == human)
		{
			int* tmp = new int[1]{}; cin >> *tmp;
			delete[] static_cast<int*>(feature);
			this->feature = tmp;
		}
		else if (group == bird)
		{
			double* tmp = new double[1]{}; cin >> *tmp;
			delete[] static_cast<double*>(feature);
			this->feature = tmp;
		}
		else if (group == cattle)
		{
			delete[] static_cast<bool*>(feature);
			char* str_tmp = str_cin(); str_lowercase(str_tmp);
			if (str_compare_content(str_tmp, (char*)"1") || str_compare_content(str_tmp, (char*)"yes"))
			{
				bool* tmp = new bool[1]{ true };
				this->feature = tmp;
			}
			else if (str_compare_content(str_tmp, (char*)"0") || str_compare_content(str_tmp, (char*)"no"))
			{
				bool* tmp = new bool[1]{ false };
				this->feature = tmp;
			}
		}
	}
	
	void print () const
	{
		cout << " Organism:";
		
		cout << "\n - Group: ";
		this->group == human  ? cout << "Human"  :
		this->group == bird   ? cout << "Bird"   :
		this->group == cattle ? cout << "Cattle" : cout << " Error!\n";
		
		cout << "\n - Walking speed: " << this->walking_speed;
		
		this->group == human  ? cout << "\n - Skin type: "     :
		this->group == bird   ? cout << "\n - Feather color: " :
		this->group == cattle ? cout << "\n - Skin color: "      : cout << "\n - Error!: ";
		str_echo(this->color);

		cout << "\n - "; str_echo(this->feature_description); cout << ": ";
		if      (this->group == human)  cout << *static_cast<int*>   (this->feature);
		else if (this->group == bird)   cout << *static_cast<double*>(this->feature);
		else if (this->group == cattle)
		{
			if (*static_cast<bool*> (this->feature)) 
				 cout << "yes";
			else cout << "no";
		}
		else cout << " Error!\n";
	}
};

void do_task_3()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 3:\t"
				<< "Разработать структуру «Живая сущность»" << "\n\t\t"
				<< " - скорость передвижения; тип (птица, скот, человек); цвет;" << "\n\t\t"
				<< " - характеристика:(для птицы - скорость полета, для скота - парнокопытное?, для человека - уровень IQ)" << "\n\n\t\t"
		
				<< "Создать экземпляр структуры «Живая сущность» и реализовать для него следующие функции:" << "\n\t\t"
				<< " - Ввод информации;" << "\n\t\t"
				<< " - Печать информации." << "\n\n\t\t"
				<< "Создать массив из 10 экземпляров структуры «Живая сущность» и реализовать для него следующие функции:" << "\n\t\t"
				<< " - Редактировать данные;" << "\n\t\t"
				<< " - Печать всего списка;" << "\n\t\t"
				<< " - Поиск по характеристике." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		int count;
		cout << " Number of organisms: ";
		cin >> count;

		if (count == 1)
		{
			organism alone;
			bool rand_create = false;
			cout << "\n Randomized? (1 / 0): _\b"; cin >> rand_create;
			cout << "\n"; not rand_create ? alone.edit() : alone.randomized();
			cout << " Done:"; alone.print();
		}
		else
		{
			organism* list = new organism[count];
			
			bool is_rand = false;
			cout << "\n Randomized all? (1 / 0): _\b"; cin >> is_rand;
			
			for (auto i = 0; i < count; i++) 
			{
				list[i].randomized();
				if (not is_rand)
				{
					bool next = false;
					cout << "\n #" << i + 1;
					list[i].print();
					cout << "\n --------------------------------\n";
					do {
						cout << " [edit - 0][next - 1]: _\b"; cin >> next;
						if (not next)
						{
							cout << "\n #" << i + 1;
							list[i].edit();
							cout << " --------------------------------\n";
						}
					} while (not next);
				}
			}

			int u_choice;
			do
			{
				cout << "\n [Exit - 0][Print - 1][Search - 2]: _\b"; cin >> u_choice;
				
				switch (u_choice)
				{
				case 1:
					for (auto i = 0; i < count; i++)
					{
						cout << "\n #" << i + 1;
						list[i].print();
						cout << "\n --------------------------------\n";
					}
				edit:
					cout << "\n [Back - 0][Edit - #]: _\b"; cin >> u_choice;
					if (u_choice > 0 && u_choice <= count)
					{
						cout << "\n #" << u_choice;
						list[u_choice - 1].edit();
						cout << " --------------------------------\n";
					}
					if (u_choice == 0) u_choice = -1;
					break;

				case 2:
					bool found_something = false;

					char* key = nullptr;
					cout << "\n Enter a word or number to search: "; str_cin(key);

					int num_i = str_to_int(key);
					double num_d = str_to_double(key);

					str_lowercase(key); str_up_begin(key);

					for (auto i = 0; i < count; i++)
					{
						// ищем по IQ
						if (num_i != 0 && *static_cast<int*>(list[i].feature) == num_i)
							goto print_search;
						
						// ищем по скорости
						if (num_d != 0 && (*static_cast<double*>(list[i].feature) == num_d || list[i].walking_speed == num_d)) 
							goto print_search;

						// ищем людей
						if (str_compare_content(key, (char*)"Human") && list[i].group == human)
							goto print_search;

						// ищем птиц
						if (str_compare_content(key, (char*)"Bird") && list[i].group == bird)
							goto print_search;

						// ищем животных
						if (str_compare_content(key, (char*)"Cattle") && list[i].group == cattle)
							goto print_search;
						
						// ищем парнокопытное животное
						if (str_compare_content(key, (char*)"Yes") && list[i].group == cattle && *static_cast<bool*>(list[i].feature) == true)
							goto print_search;

						// ищем не парнокопытное животное
						if (str_compare_content(key, (char*)"No") && list[i].group == cattle && *static_cast<bool*>(list[i].feature) == false)
							goto print_search;

						// ищем по цвету
						if (str_count_word(list[i].color, key) != 0)
							goto print_search;

						if (false)
						{
						print_search:
							cout << "\n #" << i + 1;
							list[i].print(); found_something = true;
							cout << "\n --------------------------------\n";
						}
					}
					delete[] key;
					if (found_something) goto edit;
					cout << " Not found.\n";
					break;
				}
			} while (u_choice != 0);
		}	
		cout << "\n";
	} while (task_restart());
}