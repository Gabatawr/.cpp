#include "Contact.h"


Contact::Contact()
{
	name         = new char[18]{ "Contact name" };
	home_phone   = new char[11]{ "Home phone" };
	work_phone   = new char[11]{ "Work phone" };
	mobile_phone = new char[17]{ "Mobile phone" };
	info         = new char[23]{ "Information" };
}

Contact::Contact(char* options) : Contact()
{
	this->edit(options);
}

Contact::~Contact()
{
	delete[] name;
	delete[] home_phone;
	delete[] work_phone;
	delete[] mobile_phone;
	delete[] info;
}

void Contact::replace_field(char*& field)
{
	std::cout << " [old] ";
	for (auto i = 0; field[i] != '\0'; i++) std::cout << field[i];
	std::cout << "\t[new] ";

	delete[] field; field = str_in();
}

void Contact::print(char* options)
{
	bool is_n = str_has_word(options, (char*)"-n");
	bool is_h = str_has_word(options, (char*)"-h");
	bool is_w = str_has_word(options, (char*)"-w");
	bool is_m = str_has_word(options, (char*)"-m");
	bool is_i = str_has_word(options, (char*)"-i");
	
	bool is_all = not is_n && not is_h && not is_w && not is_m && not is_i;
	
	if (is_n || is_all)
	{
		std::cout << " Contact name:\t";
		for (auto i = 0; name[i] != '\0'; i++) std::cout << name[i];
		std::cout << std::endl;
	}
	if (is_h || is_all)
	{
		std::cout << " Home phone  :\t";
		for (auto i = 0; home_phone[i] != '\0'; i++) std::cout << home_phone[i];
		std::cout << std::endl;
	}
	if (is_w || is_all)
	{
		std::cout << " Work phone  :\t";
		for (auto i = 0; work_phone[i] != '\0'; i++) std::cout << work_phone[i];
		std::cout << std::endl;
	}
	if (is_m || is_all)
	{
		std::cout << " Mobile phone:\t";
		for (auto i = 0; mobile_phone[i] != '\0'; i++) std::cout << mobile_phone[i];
		std::cout << std::endl;
	}
	if (is_i || is_all)
	{
		std::cout << " Information :\t";
		for (auto i = 0; info[i] != '\0'; i++) std::cout << info[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Contact::edit(char* options)
{
	bool is_n = str_has_word(options, (char*)"-n");
	bool is_h = str_has_word(options, (char*)"-h");
	bool is_w = str_has_word(options, (char*)"-w");
	bool is_m = str_has_word(options, (char*)"-m");
	bool is_i = str_has_word(options, (char*)"-i");

	bool is_all = not is_n && not is_h && not is_w && not is_m && not is_i;
	
	if (is_n || is_all) replace_field(name);
	if (is_h || is_all) replace_field(home_phone);
	if (is_w || is_all) replace_field(work_phone);
	if (is_m || is_all) replace_field(mobile_phone);
	if (is_i || is_all) replace_field(info);
}

//             operator[]
char* Contact::operator[](int field) const
{
	if (field == 0) return name;
	if (field == 1) return home_phone;
	if (field == 2) return work_phone;
	if (field == 3) return mobile_phone;
	if (field == 4) return info;
	return nullptr;
}

