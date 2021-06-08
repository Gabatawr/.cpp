#include "Header.h"

void rand_name(char*& first, char*& last);

struct student
{
	char* first_name = nullptr;
	char* last_name = nullptr;
	int* progress;

	int size = 5;

	student ()
	{
		rand_name(first_name, last_name);
		progress = new int[size]{ rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1 };
	}

	~student()
	{
		delete[] first_name;
		delete[] last_name;
		delete[] progress;
	}

	void new_grade (int grade)
	{
		if (grade < 1) grade = 1;
		if (grade > 5) grade = 5;
		
		if (this->size < 6)
		{
			for (auto i = 0; i < this->size; i++)
				if (this->progress[i] == 0) { this->progress[i] = grade; return; }
		}
		
		int* old_array = this->progress;
		this->progress = new int[this->size + 1];
		for (auto i = 0; i < this->size; i++) this->progress[i] = old_array[i];
		this->progress[this->size++] = grade;
		delete[] old_array;
	}
	
	student& operator = (const student& other);
};
student& student::operator = (const student& other)
{
	if (this->size != other.size)
	{
		this->size = other.size;
		delete[] this->progress;
		this->progress = new int[this->size];
	}
	for (auto i = 0; i < this->size; i++) this->progress[i] = other.progress[i];

	if (other.first_name != nullptr)
	{
		int tmp_size = str_len(other.first_name) + 1;
		delete[] this->first_name;
		this->first_name = new char[tmp_size];
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
		delete[] this->last_name;
		this->last_name = new char[tmp_size];
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

	return *this;
}

struct group
{
	int list_size;
	student* list;
	
	group ()
	{
		list_size = 1;
		list = new student[list_size];
	}

	group (int list_size)
	{
		this->list_size = list_size;
		this->list = new student[list_size];
	}

	~group()
	{
		delete[] list;
	}

	void print (int number_student) const
	{
		cout << " #" << number_student + 1 << "\t";
		str_echo(this->list[number_student].first_name); cout << " "; str_echo(this->list[number_student].last_name);

		if (str_len(this->list[number_student].first_name) + str_len(this->list[number_student].last_name) > 14) cout << "\t[";
		else if (str_len(this->list[number_student].first_name) + str_len(this->list[number_student].last_name) < 7) cout << "\t\t\t[";
		else cout << "\t\t[";
		
		for (auto j = 0; j < this->list[number_student].size; j++)
		{
			cout << this->list[number_student].progress[j];
			if (j < this->list[number_student].size - 1) cout << ", ";
		}
		cout << "]\n";
	}
	
	void show_by_grade(char* key) // A, B, C, D, E, F, comb[ADF], [ALL]; "ECTSystem by National University of Pharmacy, Kharkiv" 
	{
		bool ALL = str_compare_content(key, (char*)"ALL"), A = false, B = false, C = false, D = false, E = false, F = false;
		
		if (not ALL)
		{
			A = str_count_symbol(key, 'A') > 0;
			B = str_count_symbol(key, 'B') > 0;
			C = str_count_symbol(key, 'C') > 0;
			D = str_count_symbol(key, 'D') > 0;
			E = str_count_symbol(key, 'E') > 0;
			F = str_count_symbol(key, 'F') > 0;
			
			if (A && B && C && D && E && F) ALL = true;
		}
		
		for (auto i = 0; i < this->list_size; i++)
		{
			if (ALL) { this->print(i); continue; }
			
			int sum_grade = 0;
			for (auto j = 0; j < this->list[i].size; j++)
				sum_grade += this->list[i].progress[j];
			double avg_grade = double(sum_grade) / this->list[i].size;
			 
			if (A && avg_grade >= 4.5)                     { this->print(i); continue; } // 90-100%
			if (B && avg_grade <  4.5 && avg_grade >= 4.1) { this->print(i); continue; } // 82-89%
			if (C && avg_grade <  4.1 && avg_grade >= 3.7) { this->print(i); continue; } // 74-81%
			if (D && avg_grade <  3.7 && avg_grade >= 3.2) { this->print(i); continue; } // 64-73%
			if (E && avg_grade <  3.2 && avg_grade >= 3.0) { this->print(i); continue; } // 60-63%
			if (F && avg_grade <  3.0)                       this->print(i);             // 0-59%
		}
	}
	
};

void do_task_1()
{
	do {
	#pragma region Description
		system("cls");
		cout << "\n     Task 1:\t"
			<< "Описать структуру Student (фамилия, группа, успеваемость[массив из 5 int])." << "\n\t\t"
			<< "Создать массив студентов и написать программу, позволяющую:" << "\n\t\t"
			<< " - Динамически изменять размер массива;" << "\n\t\t"
			<< " - Выводить список отличников (>75% отличных оценок);" << "\n\t\t"
			<< " - Выводить список двоечников (>50% оценок 2 и 3)." << "\n\n\t\t"
		
			<< " ! Вывод сделан по системе ECTS" << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
	#pragma endregion

		int group_size;
		cout << " Enter group size: ";
		cin >> group_size;
		group Alpha (group_size);
		
		do {
			int uE; // userEnter
			cout << "\n [exit/0][show by grade/1][new grade/2]: _\b"; cin >> uE;
			if (uE == 0) break;

			if (uE == 1) 
			{
				cout << "\n Enter grade [A][B][C][D][E][F][any combs][ALL]: ";
				char* key = str_cin(); cout << "\n"; str_uppercase(key);
				Alpha.show_by_grade(key);
				delete[] key;
				continue;
			}
			
			if (uE == 2) 
			{
				int num_stud, new_grade;
				cout << "\n Enter #Student: "; cin >> num_stud;
				cout << " Enter grade (1-5): "; cin >> new_grade;

				Alpha.list[num_stud - 1].new_grade(new_grade);
				cout << "\n"; Alpha.print(num_stud - 1);
			}
			
		} while (true);
		
	} while (task_restart());
}