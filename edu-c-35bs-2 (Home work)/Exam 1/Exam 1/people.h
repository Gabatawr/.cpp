#pragma once

void rand_name(char*& first, char*& last);
void rand_phone(char*& phone);

struct people
{
	char* first_name;
	char* last_name;
	date birthday;
	int age;
	char* phone;

	people()
	{
		first_name = new char[6]{ "Artem" };
		last_name = new char[9]{ "Kashyrin" };
		age = birthday.full_years();
		phone = new char[14] {"+380666395706"};
	}
	
	void techFun_copying(char*& this_tmp, char* other_tmp)
	{
		if (other_tmp != nullptr)
		{
			int tmp_size = str_len(other_tmp) + 1;
			this_tmp = new char[tmp_size];
			for (auto i = 0; i < tmp_size; i++) this_tmp[i] = other_tmp[i];
		}
		else this_tmp = nullptr;
	}
	people(const people& other)
	{
		techFun_copying(this->first_name, other.first_name);
		techFun_copying(this->last_name, other.last_name);

		this->age = other.age;
		this->birthday = other.birthday;

		techFun_copying(this->phone, other.phone);
	}
	
	~people()
	{
		delete[] first_name;
		delete[] last_name;
		delete[] phone;
	}
	
	void randomizer(unsigned short int min_year = 1900, unsigned short int max_year = 2000)
	{
		rand_name(this->first_name, this->last_name);
		this->birthday.randomizer(min_year, max_year);
		this->age = birthday.full_years();
		rand_phone(this->phone);
	}
	void randomizer_phone ()
	{
		rand_phone(this->phone);
	}
	
	void edit()
	{
		std::cout << "\n First name:\t[old] " << (const char*)this->first_name << "\t\t[new] ";
		str_cin(this->first_name);

		std::cout << " Last name:\t[old] " << (const char*)this->last_name << "\t\t[new] ";
		str_cin(this->last_name);

		std::cout << " Birthday:\t[old] " << this->birthday << "\t[new] ";
		char* tmp = str_cin(); this->birthday.replace(tmp); delete[] tmp;

		std::cout << " Age:\t\t[old] " << this->age << "\t\t[new] ";
		this->age = this->birthday.full_years(); std::cout << this->age;

		std::cout << "\n Phone:\t\t[old] " << (const char*)this->phone << "\t[new] ";
		str_cin(this->phone);
	}

	char* operator [] (int index) const
	{
		if (index == 0) return &*this->first_name;
		if (index == 1) return &*this->last_name;
		if (index == 2) return &*this->phone;
		return nullptr;
	}

	void techFun_assignment(char*& this_tmp, char* other_tmp)
	{
		if (other_tmp != nullptr)
		{
			int tmp_size = str_len(other_tmp) + 1;
			delete[] this_tmp; this_tmp = new char[tmp_size];
			for (auto i = 0; i < tmp_size; i++) this_tmp[i] = other_tmp[i];
		}
		else
		{
			if (this_tmp != nullptr)
			{
				delete[] this_tmp;
				this_tmp = nullptr;
			}
		}
	}
	people& operator = (const people& other)
	{
		techFun_assignment(this->first_name, other.first_name);
		techFun_assignment(this->last_name, other.last_name);
		
		this->age = other.age;
		this->birthday = other.birthday;

		techFun_assignment(this->phone, other.phone);
		
		return *this;
	}
	
};

std::ostream& operator << (std::ostream& out, const people& people)
{
	out << (const char*)people.first_name << " " << (const char*)people.last_name;

	if (str_len(people.first_name) + str_len(people.last_name) > 14) out << "\t";
	else if (str_len(people.first_name) + str_len(people.last_name) < 7)  out << "\t\t\t";
	else out << "\t\t";

	out << people.birthday << " : " << people.age;

	out << "\t\t" << (const char*)people.phone;

	return out;
}
