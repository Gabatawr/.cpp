#include <windows.h>

#include <iostream>
#include <iomanip>

#include <fstream>

#include <string>
#include <map>

using namespace std;

string& lowercase(string& str)
{
	for (char& i : str) if (i >= 65 && i <= 90)
		i = static_cast<char>(i + 32);
	return str;
}

int main()
{
#pragma region Presetting

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

#pragma endregion

	ifstream f;
	map<string, int> arr;
	string buff;

	f.open("xxx.txt");
	while(f >> buff)
	{
		lowercase(buff);

		if (buff.back() == '.' || buff.back() == ':' || buff.back() == ',') buff.pop_back();

		if (arr.count(buff) == 0) arr.emplace(buff, 1);
		else arr.find(buff)->second++;
	}
	f.close();

	multimap<int, string> arr_popular;
	for (auto& i : arr) arr_popular.emplace(i.second, i.first);

	arr.clear();

	for (auto it = arr_popular.rbegin(); it != arr_popular.rend(); ++it)
		cout << left << setw(20) << it->second << it->first << '\n';

	system("pause");
	return 0;
}