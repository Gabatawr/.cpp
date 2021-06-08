#include "Header.h"
#include "date.h"
#include "Alph_qsort.h"

struct person
{
	char* first_name;
	char* last_name;
	date birthday;
	int age;

	person ()
	{
		first_name = new char[6]{ "Artem" };
		last_name  = new char[9]{ "Kashyrin" };
		age = birthday.full_years();
	}
	person (const person& other)
	{
		if (other.first_name != nullptr)
		{
			int tmp_size = str_len(other.first_name) + 1;
			this->first_name = new char[tmp_size];
			for (auto i = 0; i < tmp_size; i++) this->first_name[i] = other.first_name[i];
		}
		else this->first_name = nullptr;

		if (other.last_name != nullptr)
		{
			int tmp_size = str_len(other.last_name) + 1;
			this->last_name = new char[tmp_size];
			for (auto i = 0; i < tmp_size; i++) this->last_name[i] = other.last_name[i];
		}
		else this->last_name = nullptr;

		this->age = other.age;
		this->birthday = other.birthday;
	}

	~person()
	{
		delete[] first_name;
		delete[] last_name;
	}
	
	void randomizer (unsigned short int min_year = 1900, unsigned short int max_year = 2000)
	{
		rand_name(this->first_name, this->last_name);
		this->birthday.randomizer(min_year, max_year);
		this->age = birthday.full_years();
	}

	void edit()
	{
		cout << "\n First name:\t[old] " << (const char*)this->first_name << "\t\t[new] ";
		str_cin(this->first_name);
		
		cout << " Last name:\t[old] " << (const char*)this->last_name   << "\t\t[new] ";
		str_cin(this->last_name);
		
		cout << " Birthday:\t[old] " << this->birthday << "\t[new] ";
		char* tmp = str_cin(); this->birthday.replace(tmp); delete[] tmp;
		
		cout << " Age:\t\t[old] " << this->age << "\t\t[new] ";
		this->age = this->birthday.full_years(); cout << this->age;
	}
	
	char* operator [] (int index) const;
	person& operator = (const person& other);
};
std::ostream& operator << (std::ostream& out, const person& person)
{
	out << (const char*)person.first_name << " " << (const char*)person.last_name;

	if      (str_len(person.first_name) + str_len(person.last_name) > 14) out << "\t";
	else if (str_len(person.first_name) + str_len(person.last_name) < 7)  out << "\t\t\t";
	else out << "\t\t";

	out << person.birthday << " : " << person.age;
	return out;
}
char* person::operator [] (int index) const
{
	if (index == 0) return &*this->first_name;
	if (index == 1) return &*this->last_name;
	return nullptr;
}
person& person::operator = (const person& other)
{
	if (other.first_name != nullptr)
	{
		int tmp_size = str_len(other.first_name) + 1;
		delete[] this->first_name; this->first_name = new char[tmp_size];
		for (auto i = 0; i < tmp_size; i++) this->first_name[i] = other.first_name[i];
	}
	else
	{
		if (this->first_name != nullptr)
		{
			delete[] this->first_name;
			this->first_name = nullptr;
		}
	}

	if (other.last_name != nullptr)
	{
		int tmp_size = str_len(other.last_name) + 1;
		delete[] this->last_name; this->last_name = new char[tmp_size];
		for (auto i = 0; i < tmp_size; i++) this->last_name[i] = other.last_name[i];
	}
	else
	{
		if (this->last_name != nullptr)
		{
			delete[] this->last_name;
			this->last_name = nullptr;
		}
	}

	this->age = other.age;
	this->birthday = other.birthday;

	return *this;
}

struct party
{
	int size;
	person* member;

	party()
	{
		size = 1;
		member = new person[size];
	}
	party(int size)
	{
		this->size = size;
		this->member = new person[size];
	}

	~party()
	{
		delete[] member;
	}

	void print_by_number(int number) const
	{
		cout << "\n #" << number + 1 << "\t" << this->member[number];
	}
	void print_all () const
	{
		for (auto i = 0; i < this->size; i++) this->print_by_number(i);
	}
	void print_by_birthmonth (int month) const
	{
		for (auto i = 0; i < this->size; i++)
			if (this->member[i].birthday.month == month) this->print_by_number(i);
	}

	void add (int number = 0)
	{
		if (number < 0)	         number = 0;
		if (number > this->size) number = this->size;
		
		person* old_list = this->member;
		member = new person[this->size + 1];
		
		for (auto i = 0; i < this->size + 1; i++)
		{
			if (i < number)  this->member[i] = old_list[i];
			if (i == number) this->member[i].randomizer();
			if (i > number)  this->member[i] = old_list[i - 1];
		}
		delete[] old_list;
		print_by_number(number);
		this->size++;
	}
	void remove (int number = 0)
	{
		if (number < 0)	         number = 0;
		if (number > this->size) number = this->size - 1;

		person* old_list = this->member;
		member = new person[this->size - 1];

		for (auto i = 0; i < this->size; i++)
		{
			if (i < number)  this->member[i] = old_list[i];
			if (i > number)  this->member[i - 1] = old_list[i];
		}
		delete[] old_list;

		this->size--;
	}

	void search_by_name (char* key) const
	{
		for (auto i = 0; i < this->size; i++)
			if (str_count_word(this->member[i].first_name, key) > 0 || str_count_word(this->member[i].last_name, key) > 0) this->print_by_number(i);
	}
};

void do_task_2()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 2:\t"
				<< "Описать структуру Man(Person) (Фамилия, Имя, Возраст, Дата рождения)." << "\n\t\t"
				<< "Создать массив, предусмотреть:" << "\n\t\t"
				<< " - Вывод информации с сортировкой по фамилии или имени;" << "\n\t\t"
				<< " - Вывод списка именинников месяца с указанием даты рождения;" << "\n\t\t"
				<< " - Изменение размеров массива при добавлении и удалении записей;" << "\n\t\t"
				<< " - Поиск по фамилии и имени;" << "\n\t\t"
				<< " - Редактирование записи." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion
		
		cout << " Enter group size: "; int party_size; cin >> party_size;

		int min_year = 1970; //cout << " Enter min year of birth: "; int min_year; cin >> min_year;
		
		party noise (party_size);
		
		for (auto i = 0; i < noise.size; i++) noise.member[i].randomizer(min_year);

		do {
			int uE; // userEnter
			
			cout << "\n\n 1 add person\n 2 edit person\n 3 remove person\n 4 show by #/all\n 5 sort and show\n 6 search by name\n 7 show birthmonth\n 0 exit"
				 << "\n -----------------\n Enter : _\b"; cin >> uE;
			
			if (uE == 0) break;
			if (uE == 1)
			{
				cout << "\n Enter the number of the add member : #"; cin >> uE;
				noise.add(uE - 1);
				continue;
			}
			if (uE == 2)
			{
				cout << "\n Enter the member number to edit : #"; cin >> uE;
				noise.member[uE - 1].edit(); cout << "\n";
				noise.print_by_number(uE - 1);
				continue;
			}
			if (uE == 3)
			{
				cout << "\n Enter the number of the remove member : #"; cin >> uE;
				noise.remove(uE - 1);
				continue;
			}
			if (uE == 4)
			{
				cout << "\n Enter the member number to show (0 show all) : #"; cin >> uE;
				if (uE >= 1 && uE <= noise.size) noise.print_by_number(uE - 1);
				else noise.print_all();
				continue;
			}
			if (uE == 5)
			{
				cout << "\n Sorting by (first.1 / last.2) name : #"; cin >> uE;
				alph_qsort(noise.member, uE - 1, 0, noise.size - 1, str_compare);
				continue;
			}
			if (uE == 6)
			{
				cout << "\n Enter search name : "; char* key = str_cin();
				noise.search_by_name(key);
				delete[] key;
				continue;
			}
			if (uE == 7)
			{
				cout << "\n Enter month of birth: "; cin >> uE;
				if (uE < 01) uE = 01; if (uE > 12) uE = 12;
				noise.print_by_birthmonth(uE);
			}
			
		} while (true);
	} while (task_restart());
}