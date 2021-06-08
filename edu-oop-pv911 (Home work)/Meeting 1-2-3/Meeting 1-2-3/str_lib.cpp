#include "str_lib.h"

char* str_in()
{
	char* str = new char[256]; auto i = 0;
	if (std::cin.peek() == '\n') std::cin.ignore();
	while ((str[i++] = static_cast<char>(getchar())) != '\n');
	str[--i] = '\0';

	char* str_old = str;

	int str_size = strlen(str) + 1;
	str = new char[str_size];
	for (auto j = 0; j < str_size; j++) str[j] = str_old[j];

	delete[] str_old;
	return str;
}

int str_count_word(char* str, char* word)
{
	int str_size = strlen(str);
	int word_size = strlen(word);

	int count = 0;
	for (auto i = 0, j = 0; i < str_size; i++, j = 0)
	{
		while (str[i] == word[j] && j < word_size)
		{
			i++; j++;
			if (j == word_size) { count++; i--; }
		}
	}
	return count;
}

bool str_has_word(char* str, char* word)
{
	int str_size = strlen(str);
	int word_size = strlen(word);

	for (auto i = 0, j = 0; i < str_size; i++, j = 0)
	{
		while (str[i] == word[j] && j < word_size)
		{
			i++; j++;
			if (j == word_size) return true;
		}
	}
	return false;
}

int str_to_int(char* str, int number_in_row)
{
	double number = 0;
	for (auto i = 0, count = 0; str[i] != '\0'; i++)
	{
		bool flag = false;

		int digits = i;
		while (str[i] >= 48 && str[i] <= 57) {
			flag = true;
			i++;
		}
		digits = i - digits;

		if (digits > 0) count++;

		if (count == number_in_row)
		{
			i -= digits;
			for (auto j = 0; j < digits; j++, i++)
			{
				number += double(str[i] - 48) / 10;
				number *= 10;
			}
			return int(number);
		}
		if (flag) i--;
	}
	return 0;
}

int str_count_int(char* str)
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

char* str_between_quotes (char* str, char sym_quotes)
{
	int start = -1, end = -1;
	
	for (auto i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == sym_quotes)
		{
			if (start == -1) start = i;
			else { end = i; break; }
		}
	}
	
	if (start == -1 || end == -1) return nullptr;

	char* res = new char[end - start];
	for (auto i = start + 1; i < end; i++) res[i - (start + 1)] = str[i];
	res[end - start - 1] = '\0';
	
	return res;
}

int str_compare(char* left, char* right)
{
	int i = 0;
	while (left[i] != '\0')
	{
		if (right[i] == '\0' || left[i] > right[i]) return 1;
		if (left[i] < right[i]) return -1;
		i++;
	}
	if (right[i] == '\0') return 0;
	return -1;
}