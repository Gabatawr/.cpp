#include "header.h"

int int_count(string& str)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
	{
		bool flag = false;

		int digits = i;
		while (str[i] >= 48 && str[i] <= 57) {
			flag = true;
			i++;
		}
		digits = i - digits;

		if (digits > 0) count++;
		if (flag) i--;
	}
	return count;
}
int int_pos(string& str, unsigned number_in_row = 1)
{
	if (int_count(str) == 0) return -1;
	
	double number = 0;
	for (unsigned i = 0, count = 0; i < str.length(); i++)
	{
		bool flag = false;

		unsigned digits = i;
		while (str[i] >= 48 && str[i] <= 57) {
			flag = true;
			i++;
		}
		digits = i - digits;

		if (digits > 0) count++;

		if (count == number_in_row)
		{
			i -= digits;
			for (unsigned j = 0; j < digits; j++, i++)
			{
				number += static_cast<double>(str[i] - 48) / 10;
				number *= 10;
			}
			return static_cast<int>(number);
		}
		if (flag) i--;
	}
	return -1;
}
string between_quotes(string& str, char symbol = '\"')
{
	int start = -1, end = -1;

	for (auto i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (str[i] == symbol)
		{
			if (start == -1) start = i;
			else { end = i; break; }
		}
	}

	string ret;
	if (start == -1 || end == -1) return ret;

	char* tmp = new char[end - start];
	for (auto i = start + 1; i < end; i++) tmp[i - (start + 1)] = str[i];
	tmp[end - start - 1] = '\0';

	ret += tmp;
	delete[] tmp;

	return ret;
}

Directory::Directory(const char* file) // load
{	
	ifstream f_in(file, std::ios::binary);
	if (not f_in.is_open()) { cout << " File not open.."; return; }

	int t_int = 0; char t_char;

	f_in.read(reinterpret_cast<char*>(&t_int), sizeof(int)); list.reserve(t_int);
	for (auto i = 0, s = -1; i < static_cast<int>(list.capacity()); ++i, s = -1)
	{
		list.push_back(new Contact);
		
		while (++s < 5)
		{
			f_in.read(reinterpret_cast<char*>(&t_int), sizeof(int));
			
			list[i]->at(s).clear();
			list[i]->at(s).resize(t_int);
			
			for (auto j = 0; j < static_cast<int>(list[i]->at(s).size()); ++j)
				if (f_in.read(&t_char, sizeof(char))) 
					list[i]->at(s)[j] = t_char;
		}
	}
	f_in.close();
	cout << " List loaded..";
}

Directory::~Directory()
{
	for (auto& i : list) delete i;
	list.clear();
}

void Directory::print(string& commands)
{
	if (list.empty()) { cout << " List is empty.."; return; }

	int size = int_count(commands);
	if (size == 0 && commands.find("all") == string::npos) { cout << " print what..?"; return; }
	
	if (commands.find("all") != string::npos)
	{
		for (auto i = 0; i < static_cast<int>(list.size()); i++)
			cout << "\n #" << setw(3) << std::left << i + 1 << std::right << "\n" << *(list[i]);
	}
	else if (commands.find('>')  != string::npos && size == 2)
	{
		int arr[2] { int_pos(commands, 1) - 1, int_pos(commands, 2) - 1 };          // init
		
		if (arr[0] < 0 || arr[1] > static_cast<int>(list.size() - 1)) { cout << " Invalid index.."; return; } // check error
		
		if (arr[0] < arr[1])                                                                                  // min > max
			for (int i = arr[0]; i <= arr[1]; i++)                             
				cout << "\n #" << setw(3) << std::left << i + 1 << std::right << "\n" << *(list[i]);	
		else                                                                                                  // max > min
			for (int i = arr[0]; i >= arr[1]; i--)
				cout << "\n #" << setw(3) << std::left << i + 1 << std::right << "\n" << *(list[i]);
	}
	else
	{
		for (int i = 0, index; i < size; i++)
		{
			index = int_pos(commands, i + 1) - 1;
			if (index == -1 && size == 1) cout << " Invalid index..";
			if (index > -1 && index < static_cast<int>(list.size())) 
				cout << "\n #" << setw(3) << std::left << index + 1 << std::right << "\n" << *(list[index]);
		}
	}
}

void Directory::search(string& commands)
{
	string k = between_quotes(commands);
	if (k.length() < 3) { cout << " Please enter at least 3 characters.."; return; }
	
	if (key->all) key->c = key->b = key->o = key->p = key->a = true;
	else key->all = true;
	
	auto p = [&](int& i, char char_k) { cout << "\n #" << setw(3) << std::left << i + 1 << std::right << " key: -" << char_k << "\n" << *(list[i]); };
	
	for(auto i = 0; i < static_cast<int>(list.size()); ++i)
	{
		if (key->c && list[i]->company.find(k)  != string::npos)  p(i, 'c');
		if (key->b && list[i]->busyness.find(k) != string::npos)  p(i, 'b');
		if (key->o && list[i]->owner.find(k)    != string::npos)  p(i, 'o');
		if (key->p && list[i]->phone.find(k)    != string::npos)  p(i, 'p');
		if (key->a && list[i]->address.find(k)  != string::npos)  p(i, 'a');
	}	
}

void Directory::edit(string& commands)
{
	list[int_pos(commands) - 1]->edit();
}

void Directory::add(string& commands)
{
	int index = int_pos(commands) - 1;
	if (index == -2) index = static_cast<int>(list.size());
	
	if (index < 0 || index > static_cast<int>(list.size())) cout << " Invalid index.."; // if error
	else if (index == static_cast<int>(list.size())) list.push_back(new Contact);       // to back
	else list.insert(list.begin() + index, new Contact); // to index
}

void Directory::del(string& commands)
{
	int size = int_count(commands);
	int index = int_pos(commands) - 1;

	if (index < 0 || index > static_cast<int>(list.size() - 1)) cout << " Invalid index..";                   // error
	else if (index == static_cast<int>(list.size() - 1))                                                      // del last
	{
		delete list[index]; list.pop_back();
		cout << " #" << index + 1 << " deleted..";
	}
	else if (commands.find('>') != string::npos && size == 2)                                              // del range
	{
		int arr[2]{ int_pos(commands, 1) - 1, int_pos(commands, 2) - 1 };
		
		if (arr[0] > arr[1]) std::swap(arr[0], arr[1]);
		if (arr[0] < 0 || arr[1] > static_cast<int>(list.size() - 1)) { cout << " Invalid index.."; return; } // error

		for (int i = arr[0]; i <= arr[1]; i++) delete list[i];
		list.erase(list.begin() + arr[0], list.begin() + arr[1] + 1);

		cout << " range " << arr[0] + 1 << " > " << arr[1] + 1 << " deleted..";
	}
	else                                                                                                       // del[index]
	{
		delete list[index]; list.erase(list.begin() + index);
		cout << " #" << index + 1 << " deleted..";
	}
}

void Directory::save(const char* file)
{
	ofstream f_out(file, std::ios::binary);
	if (not f_out.is_open()) { cout << " File not open.."; return; }
	
	int t_int; char t_char;
	
	f_out.write(reinterpret_cast<char*>(&(t_int = list.size())), sizeof(int));
	for (auto i = 0, j = -1; i < static_cast<int>(list.size()); ++i, j = -1)
	{
		while (++j < 5)
		{
			f_out.write(reinterpret_cast<char*>(&(t_int = list[i]->at(j).length())), sizeof(int));
			
			for (auto c = 0; c < static_cast<int>(list[i]->at(j).length()); ++c)
				f_out.write(&(t_char = list[i]->at(j).at(c)), sizeof(char));
		}
	}
	
	f_out.close();
	cout << " List saved..";
}
