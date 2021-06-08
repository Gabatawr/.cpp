#include "Header.h"

#include <cstdlib>
#include <random>


// Возвращает рандомное имя из базы (315 английских имен)
char* rand_name();


void do_task_5()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 5:\t"
				<< "Создайте динамический массив, хранящий в первой строке имя, а во второй — телефон." << "\n\t\t"
				<< "Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		#pragma region Create list
			// Инициализировать генератор случайных чисел Mersenne Twister, определяем диапазон
			std::random_device rd;
			std::uniform_int_distribution<> randMT(100000000, 999999999);
			
			// Создаем список
			int row = 500, col = 2;
			char*** list = new char**[row];
			for (auto i = 0; i < row; i++) list[i] = new char*[col];
			
			// Заполняем Phone(list[x][0]) уникальными рандомными девятизначными числами, добавляем "+380" вначало
			for (auto i = 0; i < row; i++) 
			{
				int phone = randMT(rd);
				
				int tmp = phone / 10000000;
				if (tmp != 39 && tmp != 50 && tmp != 63 && tmp != 66 && tmp != 67 && tmp != 68 && tmp != 92 && tmp != 93 && tmp != 94 && tmp != 95 && tmp != 96 && tmp != 97 && tmp != 98 && tmp != 99) 
					{ i--; continue; }

				list[i][0] = str_from_int(phone);
				str_put_range(list[i][0], 0, 4);
				list[i][0][0] = '+'; list[i][0][1] = '3'; list[i][0][2] = '8'; list[i][0][3] = '0';
				
				for (int j = 0; j < i; j++) if (str_compare_content(list[i][0], list[j][0])) { i--; }
			}

			// Заполняем Name(list[x][1]) рандомными иминами
			for (auto i = 0; i < row; i++) list[i][1] = rand_name();

			cout << " New list created: "; system("pause");
		#pragma endregion

		// Выставить значения по умолчанию
		char* tmp_search = nullptr;
		int* arr_pos_tmp_row = nullptr;
		
		do {
			// Очищаем страницу, выводим меню поиска
			system("cls");
			cout << "\n     Menu:\t"
				<< "1. Search by phone" << "\n\t\t"
				<< "2. Search by name" << "\n\n\t\t"
			
				<< "0. exit" << "\n"
				<< "___________________________________________________________________________________________________________________" << "\n\n";

			// Выставить значения по умолчанию
			int u_choice = 0, count_tmp_row = 0;
			
			// Очистить память если задействована
			delete[] tmp_search; tmp_search = nullptr;
			delete[] arr_pos_tmp_row; arr_pos_tmp_row = nullptr;

			// Вводим выбор пункта меню
			cout << " Enter: _\b"; cin >> u_choice; cin.ignore();

			// Выход если 0
			if (u_choice == 0) break;
			
			// Повторить если ошибка выбора
			if (u_choice != 1 && u_choice != 2)
			{
				cout << "\n Enter error: "; system("pause");
				continue;
			}

			// Вводим фразу поиска
			if (u_choice == 1) cout << "\n Enter search phone: ";
			else cout << "\n Enter search name: ";
			str_cin(tmp_search);

			// Повторить если фраза короче 3 символов
			if (str_len(tmp_search) < 3)
			{
				cout << "\n Min 3 symbol: "; system("pause");
				continue;
			}

			// Вывод списка совпадений
			cout << "\n --------------------------------------------------\n [#]\tPhone\t\tName\n --------------------------------------------------";
			for (auto i = 0; i < row; i++)
			{
				if (str_count_word(list[i][u_choice - 1], tmp_search) != 0)
				{
					cout << "\n [" << count_tmp_row + 1 << "]\t"; str_echo(list[i][0]); cout << "\t"; str_echo(list[i][1]); count_tmp_row++;
				}
			}

			// Повторить если совпадения не найдены
			if (count_tmp_row == 0)
			{
				cout << "\n Not found. "; system("pause");
				continue;
			}
			
			// Запомнить индексы совпадений
			arr_pos_tmp_row = new int[count_tmp_row];
			for (auto i = 0, tmp = 0; i < row; i++)
			{
				if (str_count_word(list[i][u_choice - 1], tmp_search) != 0) arr_pos_tmp_row[tmp++] = i;
			}

			// Цикл редактирования
			while (true)
			{
				// Редактировать значение по индексу
				int edit_choice = 0;
				cout << "\n --------------------------------------------------\n\n [index - #][back - 0]: _\b"; cin >> edit_choice;

				// Выход если индекс 0 или больше диапазона
				if (edit_choice <= 0 || edit_choice > count_tmp_row) break;

				// Вводим что изменить
				cout << " [phone - 1][name - 2]: _\b"; cin >> u_choice;
				
				// Заменить строку
				cout << "\n --------------------------------------------------\n\n Old: "; str_echo(list[arr_pos_tmp_row[edit_choice - 1]][u_choice - 1]);
				cout << "\tNew: "; delete[] list[arr_pos_tmp_row[edit_choice - 1]][u_choice - 1]; cin.ignore(); str_cin(list[arr_pos_tmp_row[edit_choice - 1]][u_choice - 1]);

				// Вывести список совпадений
				cout << "\n --------------------------------------------------\n [#]\tPhone\tName\n --------------------------------------------------";
				for (auto j = 0; j < count_tmp_row; j++)
				{
					cout << "\n [" << j + 1 << "]\t"; str_echo(list[arr_pos_tmp_row[j]][0]); cout << "\t"; str_echo(list[arr_pos_tmp_row[j]][1]);
				}
			}
		} while (true);

		// Очистить память
		for (auto i = 0; i < row; i++) for (auto j = 0; j < col; j++) delete[] list[i][j];
		for (auto i = 0; i < row; i++) delete[] list[i];
		delete[] arr_pos_tmp_row;
		delete[] tmp_search;
		delete[] list;
		
	} while (task_restart());
}

char* rand_name()
{
	// Общее количество имен в массиве
	const int count = 315;
	const int name_limit = 12;

	// Массив имен
	const char* names[count] = {
 "Aaliyah"
,"Aaron"
,"Abigail"
,"Abraham"
,"Ada"
,"Adam"
,"Adelina"
,"Adrian"
,"Agatha"
,"Aidan"
,"Alan"
,"Albert"
,"Alejandro"
,"Alex"
,"Alexa"
,"Alexander"
,"Alexandra"
,"Alexis"
,"Alfred"
,"Alise"
,"Allison"
,"Alyssa"
,"Amanda"
,"Amber"
,"Amelia"
,"Andrew"
,"Angel"
,"Angelina"
,"Anita"
,"Ann"
,"Anthony"
,"Antonio"
,"Ariana"
,"Arianna"
,"Ashley"
,"Ashton"
,"Audrey"
,"Austin"
,"Autumn"
,"Ava"
,"Avery"
,"Bailey"
,"Barbara"
,"Beatrice"
,"Belinda"
,"Benjamin"
,"Bernard"
,"Blake"
,"Brandon"
,"Brian"
,"Brianna"
,"Bridjet"
,"Brooke"
,"Bruce"
,"Bryan"
,"Caleb"
,"Cameron"
,"Carl"
,"Carlos"
,"Caroline"
,"Carter"
,"Catherine"
,"Cecilia"
,"Celia"
,"Charles"
,"Chase"
,"Chloe"
,"Christian"
,"Christine"
,"Christopher"
,"Claire"
,"Clifford"
,"Cody"
,"Cole"
,"Colin"
,"Connor"
,"Curtis"
,"Cyrus"
,"Daisy"
,"Daniel"
,"Danielle"
,"David"
,"Deborah"
,"Delia"
,"Dennis"
,"Destiny"
,"Devin"
,"Diana"
,"Diego"
,"Dominic"
,"Donald"
,"Dorothy"
,"Douglas"
,"Dylan"
,"Edward"
,"Eleanor"
,"Elijah"
,"Elizabeth"
,"Ella"
,"Emily"
,"Emma"
,"Eric"
,"Erin"
,"Ethan"
,"Evan"
,"Evelyn"
,"Faith"
,"Fiona"
,"Florence"
,"Francis"
,"Fred"
,"Freda"
,"Gabriel"
,"Gabriella"
,"Gabrielle"
,"Gavin"
,"Geoffrey"
,"George"
,"Gerld"
,"Gilbert"
,"Gladys"
,"Gloria"
,"Gordon"
,"Grace"
,"Graham"
,"Gregory"
,"Hailey"
,"Haley"
,"Hannah"
,"Harold"
,"Harry"
,"Hayden"
,"Helen"
,"Henry"
,"Herbert"
,"Horace"
,"Howard"
,"Hugh"
,"Hunter"
,"Ian"
,"Isaac"
,"Isabel"
,"Isabella"
,"Isaiah"
,"Jack"
,"Jackson"
,"Jacob"
,"Jacqueline"
,"Jada"
,"Jaden"
,"Jake"
,"James"
,"Jane"
,"Jasmine"
,"Jason"
,"Jayden"
,"Jeffery"
,"Jenna"
,"Jennifer"
,"Jeremiah"
,"Jesse"
,"Jessica"
,"Jesus"
,"Jocelyn"
,"John"
,"Jonathan"
,"Jordan"
,"Jordan"
,"Jose"
,"Joseph"
,"Josephine"
,"Joshua"
,"Joyce"
,"Juan"
,"Julia"
,"Julian"
,"Justin"
,"Kaitlyn"
,"Katelyn"
,"Katherine"
,"Kathryn"
,"Kayla"
,"Kaylee"
,"Keith"
,"Kevin"
,"Kimberly"
,"Kyle"
,"Kylie"
,"Landon"
,"Laura"
,"Lauren"
,"Lawrence"
,"Leah"
,"Leonars"
,"Leonora"
,"Leslie"
,"Lewis"
,"Lillian"
,"Lily"
,"Linda"
,"Logan"
,"Lorna"
,"Louis"
,"Lucas"
,"Luccile"
,"Lucy"
,"Luke"
,"Lynn"
,"Mabel"
,"Mackenzie"
,"Madeline"
,"Madison"
,"Makayla"
,"Malcolm"
,"Margaret"
,"Maria"
,"Marisa"
,"Marjorie"
,"Martin"
,"Mary"
,"Mason"
,"Matthew"
,"Maya"
,"Megan"
,"Melanie"
,"Melissa"
,"Mia"
,"Michael"
,"Michelle"
,"Miguel"
,"Mildred"
,"Miles"
,"Molly"
,"Monica"
,"Morgan"
,"Nancy"
,"Natalie"
,"Nathan"
,"Nathaniel"
,"Neil"
,"Nicholas"
,"Nicole"
,"Noah"
,"Nora"
,"Norman"
,"Oliver"
,"Olivia"
,"Oscar"
,"Oswald"
,"Owen"
,"Paige"
,"Pamela"
,"Patricia"
,"Patrick"
,"Pauline"
,"Penelope"
,"Peter"
,"Philip"
,"Priscilla"
,"Rachel"
,"Ralph"
,"Raymond"
,"Rebecca"
,"Reginald"
,"Richard"
,"Riley"
,"Rita"
,"Robert"
,"Rodrigo"
,"Roger"
,"Ronald"
,"Rosalind"
,"Rose"
,"Ryan"
,"Samantha"
,"Samuel"
,"Sandra"
,"Sara"
,"Sarah"
,"Savannah"
,"Sean"
,"Sebastian"
,"Seth"
,"Sharon"
,"Sheila"
,"Shirley"
,"Sierra"
,"Simon"
,"Sofia"
,"Sophia"
,"Stanley"
,"Stephanie"
,"Steven"
,"Susan"
,"Sybil"
,"Sydney"
,"Sylvia"
,"Taylor"
,"Thomas"
,"Timothy"
,"Trinity"
,"Tyler"
,"Vanessa"
,"Victoria"
,"Violet"
,"Virginia"
,"Wallace"
,"Walter"
,"William"
,"Winifred"
,"Wyatt"
,"Xavier"
,"Yvonne"
,"Zachary"
,"Zoe"
	};

	// Рандомное число в диапазоне имен
	int n = rand() % count;

	// Копируем имя в строку
	char* name = new char[name_limit];
	int i = 0; while (names[n][i] != '\0') name[i] = names[n][i++];
	name[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < name_limit - 1) str_cut(name);

	// Возвращаем рандомное имя
	return name;
}