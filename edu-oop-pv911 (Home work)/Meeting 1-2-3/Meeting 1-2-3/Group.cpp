#include "Group.h"

Group::Group()
{
	size = 1;
	list = new Contact* [size]; list[0] = new Contact;
}

Group::Group(int size)
{
	this->size = size;
	list = new Contact* [size];
	for (auto i = 0; i < size; i++) list[i] = new Contact;
}

Group::Group(char* file_name) // load
{
	std::ifstream file;
	file.open("group.txt");
	if (!file.is_open()) { std::cout << " File not found..\n\n"; system("pause"); exit(0); }

	size = str_to_int(techFun_load(file, 13));
	file.seekg(55, std::ios::cur);
	
	list = new Contact * [size];
	for (auto i = 0; i < size; i++) list[i] = new Contact;

	for (auto j = 0; j < size; j++)
	{
		file.seekg(36, std::ios::cur);

		list[j]->name         = techFun_load(file, 15);
		list[j]->home_phone   = techFun_load(file, 15);
		list[j]->work_phone   = techFun_load(file, 15);
		list[j]->mobile_phone = techFun_load(file, 15);
		list[j]->info         = techFun_load(file, 15);
	}
	
	file.close();
}

char* Group::techFun_load (std::ifstream& file, int shift)
{
	int sz = 0; char ch;
	
	file.seekg(shift, std::ios::cur);
	
	for (file.get(ch); ch != '\n'; sz++, file.get(ch));
	char* str = new char[++sz];
	
	file.seekg(-(sz + 1), std::ios::cur); file.get(ch);
	
	for (int i = 0; ch != '\n'; i++, file.get(ch)) str[i] = ch; str[sz - 1] = '\0';

	return str;
}

Group::~Group()
{
	for (auto i = 0; i < size; i++) delete list[i];
	delete[] list;
}

void Group::print(char* options) const
{
	
	int* int_array = nullptr;
	int int_size = str_count_int(options);
	bool is_range = false, is_all = str_has_word(options, (char*)"all");
	
	if (not is_all && int_size > 0)
	{
		int_array = new int[int_size] {};
		for (auto i = 0; i < int_size; i++)
			int_array[i] = str_to_int(options, i + 1);
		
		if (int_size == 2 && str_has_word(options, (char*)".."))
		{
			is_range = true;
			if (int_array[0] < 1) int_array[0] = 1;
			if (int_array[1] > size) int_array[1] = size;
			
			if (int_array[0] > int_array[1])
			{
				int tmp = int_array[0];
				int_array[0] = int_array[1];
				int_array[1] = tmp;
			}
		}
		else for (auto i = 0; i < int_size; i++) if (int_array[i] < 1 || int_array[i] > size) int_array[i] = 0;
	}

	if (is_all)
	{
		for (auto i = 0; i < size; i++)
		{
			std::cout << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮\n";
			list[i]->print(options);
		}
	}
	else if (is_range)
	{
		for (auto i = int_array[0] - 1; i <= int_array[1] - 1; i++)
		{
			std::cout << " #" << ( i < 9 ? "0" : "" ) << i + 1 << " ────────╮\n";
			list[i]->print(options);
		}
	}		
	else if (int_size > 0)
	{
		for (auto i = 0; i < int_size; i++) 
		{
			if (int_array[i] != 0)
			{
				std::cout << " #" << (int_array[i] - 1 < 9 ? "0" : "") << int_array[i] << " ────────╮\n";
				list[int_array[i] - 1]->print(options);
			}
		}
	}
	else std::cout << " Invalid command..";

	delete[] int_array;
}

void Group::search(char* options) const
{
	char* what_find = str_between_quotes(options);
	if (what_find == nullptr) what_find = str_between_quotes(options, '\'');
	if (what_find == nullptr) { std::cout << " Invalid command.."; return; }

	bool is_n = str_has_word(options, (char*)"-n");
	bool is_h = str_has_word(options, (char*)"-h");
	bool is_w = str_has_word(options, (char*)"-w");
	bool is_m = str_has_word(options, (char*)"-m");
	bool is_i = str_has_word(options, (char*)"-i");

	bool is_all = not is_n && not is_h && not is_w && not is_m && not is_i;

	bool found_something = false;
	for (auto i = 0; i < size; i++)
	{
		if ((is_all || is_n) && str_has_word(list[i]->operator[](0), what_find))
		{
			std::cout << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮\n";
			list[i]->print((char*)"-n"); found_something = true;
		}
		if ((is_all || is_h) && str_has_word(list[i]->operator[](1), what_find))
		{
			std::cout << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮";
			list[i]->print((char*)"-h"); found_something = true;
		}
		if ((is_all || is_w) && str_has_word(list[i]->operator[](2), what_find))
		{
			std::cout << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮";
			list[i]->print((char*)"-w"); found_something = true;
		}
		if ((is_all || is_m) && str_has_word(list[i]->operator[](3), what_find))
		{
			std::cout << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮";
			list[i]->print((char*)"-m"); found_something = true;
		}
		if ((is_all || is_i) && str_has_word(list[i]->operator[](4), what_find))
		{
			std::cout << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮";
			list[i]->print((char*)"-i"); found_something = true;
		}
	}
	if (not found_something) std::cout << " Nothing found..";
}

void Group::edit(char* options)
{
	int number = str_to_int(options);

	if (number == 0) { std::cout << " Invalid command.."; return; }
	
	if (number < 1) number = 1;
	if (number > size) number = size;
	
	list[number - 1]->edit(options);
}

void Group::sort(char* options)
{
	if      (str_has_word(options, (char*)"-n")) { alph_qsort(list, 0, 0, size - 1, str_compare); std::cout << " Sorting completed"; }
	else if (str_has_word(options, (char*)"-h")) { alph_qsort(list, 1, 0, size - 1, str_compare); std::cout << " Sorting completed"; }
	else if (str_has_word(options, (char*)"-w")) { alph_qsort(list, 2, 0, size - 1, str_compare); std::cout << " Sorting completed"; }
	else if (str_has_word(options, (char*)"-m")) { alph_qsort(list, 3, 0, size - 1, str_compare); std::cout << " Sorting completed"; }
	else if (str_has_word(options, (char*)"-i")) { alph_qsort(list, 4, 0, size - 1, str_compare); std::cout << " Sorting completed"; }
	
	else std::cout << " Invalid command..";
}

void Group::add(char* options)
{
	int pos = str_to_int(options);
	if (pos < 1) pos = 1;
	if (pos > size + 1) pos = size + 1;
	
	Contact** old_list = list;
	list = new Contact * [++size];
	
	for (auto i = 0; i < size; i++)
	{
		if (i <  pos - 1) list[i] = old_list[i];
		if (i == pos - 1) list[i] = new Contact;
		if (i >  pos - 1) list[i] = old_list[i - 1];
	}

	list[pos - 1]->edit(options);

	delete[] old_list;
}

void Group::remove(char* options)
{
	int pos = str_to_int(options);
	if (pos < 1 || pos > size) { std::cout << " Invalid position.."; return; }

	Contact** old_list = list;
	list = new Contact * [--size];

	for (auto i = 0; i < size; i++)
	{
		if (i <  pos - 1) list[i] = old_list[i];
		if (i == pos - 1) delete old_list[i];
		if (i >= pos - 1) list[i] = old_list[i + 1];
	}

	delete[] old_list;

	std::cout << " Position "<< pos << " removed..";
}

void Group::save()
{
	std::ofstream file;
	file.open("group.txt");

	file << " Group size: " << size << std::endl;
	
	for (auto i = 0; i < 55; i++) file.put('-'); file << std::endl;
	
	for (auto i = 0; i < size; i++)
	{
		file << " #" << (i < 9 ? "0" : "") << i + 1 << " ────────╮\n";
		
		file << " Contact name: ";
		for (auto j = 0; list[i]->name[j] != '\0'; j++) file.put(list[i]->name[j]);
		file << std::endl;

		file << " Home phone  : ";
		for (auto j = 0; list[i]->home_phone[j] != '\0'; j++) file.put(list[i]->home_phone[j]);
		file << std::endl;

		file << " Work phone  : ";
		for (auto j = 0; list[i]->work_phone[j] != '\0'; j++) file.put(list[i]->work_phone[j]);
		file << std::endl;

		file << " Mobile phone: ";
		for (auto j = 0; list[i]->mobile_phone[j] != '\0'; j++) file.put(list[i]->mobile_phone[j]);
		file << std::endl;

		file << " Information : ";
		for (auto j = 0; list[i]->info[j] != '\0'; j++) file.put(list[i]->info[j]);
		file << std::endl << std::endl;
	}
	
	file.close();

	std::cout << " List saved to file..";
}	