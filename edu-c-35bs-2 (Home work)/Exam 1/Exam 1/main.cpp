#include "Header.h"

int main()
{
	#pragma region Presettings
		srand(time(0));
	#pragma endregion
		
	char* file = new char[14]{ "data_list.txt" };
	group list(file);
	
	do {
		int uE; // userEnter
		
		std::cout << "\n\n 01 - add people"
					<< "\n 02 - edit people"
					<< "\n 03 - remove people"
					<< "\n 04 - show by #/all"
					<< "\n 05 - sort and show"
					<< "\n 06 - search by name"
					<< "\n 07 - search by phone"
					<< "\n 08 - search by age"
					<< "\n 09 - show birthmonth"
					<< "\n 10 - randomizer list"
					<< "\n 0 -- save and exit"
					<< "\n -------------------"
					<< "\n Enter : _\b"; std::cin >> uE;

		if (uE == 0) { list.save(file); break; }
		if (uE == 1)
		{
			std::cout << "\n Enter the number of the add member : #"; std::cin >> uE;
			list.add(uE - 1);
			continue;
		}
		if (uE == 2)
		{
			std::cout << "\n Enter the member number to edit : #"; std::cin >> uE;
			list.member[uE - 1].edit(); std::cout << "\n";
			list.print_by_number(uE - 1);
			continue;
		}
		if (uE == 3)
		{
			std::cout << "\n Enter the number of the remove member : #"; std::cin >> uE;
			list.remove(uE - 1);
			continue;
		}
		if (uE == 4)
		{
			std::cout << "\n Enter the member number or 0 show all : #"; std::cin >> uE;
			if (uE >= 1 && uE <= list.size) list.print_by_number(uE - 1);
			else list.print_all();
			continue;
		}
		if (uE == 5)
		{
			std::cout << "\n Sorting by (first_name.1 / last_name.2 / phone.3) : #"; std::cin >> uE;
			alph_qsort(list.member, uE - 1, 0, list.size - 1, str_compare);
			list.print_all();
			continue;
		}
		if (uE == 6)
		{
			std::cout << "\n Enter search name : "; char* key = str_cin();
			list.search_by_name(key);
			delete[] key;
			continue;
		}
		if (uE == 7)
		{
			std::cout << "\n Enter search phone : "; char* key = str_cin();
			list.search_by_phone(key);
			delete[] key;
			continue;
		}
		if (uE == 8)
		{
			std::cout << "\n Enter search age : "; int age; std::cin >> age;
			list.print_by_age(age);
			continue;
		}
		if (uE == 9)
		{
			std::cout << "\n Enter month of birth: "; std::cin >> uE;
			if (uE < 01) uE = 01; if (uE > 12) uE = 12;
			list.print_by_birthmonth(uE);
			continue;
		}
		if (uE == 10)
		{
			for (auto i = 0; i < list.size; i++)
			{
				list.member[i].randomizer(1970);
				for (auto j = 0; j < i; j++)
					while (str_compare_content(list.member[i].phone, list.member[j].phone)) { list.member[i].randomizer_phone(); j = -1; }
			}
			std::cout << " Done.\n";
		}
		
	} while (true);
	
	return 0;
}