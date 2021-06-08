#include "String_libMY.h"
#include <iostream>


void str_echo(char*& str)
{
	for (auto i = 0; str[i] != '\0'; i++) std::cout << str[i];
}

int str_len(char*& str, int str_size)
{
	for (auto i = 0; i < str_size; i++)
		if (str[i] == '\0') return i;
	return -1;
}

bool str_equal(char*& str_1, char*& str_2, int str_size)
{
	if (str_1 == str_2) return true;
	if (1 > str_size) return false;
	
	int i = -1;
	while(str_1[++i] != '\0')
		if (str_1[i] != str_2[i]) return false;
		
	return str_2[i] == '\0';
}

int str_symbol_count(char*& str, int str_size, char symbol)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] == symbol) count++;
	
	return count;
}

void str_cut_trash(char*& str, int& str_size)
{
	str_size = str_len(str, str_size) + 1;
	char* str_new = new char[str_size];

	for (auto i = 0; i < str_size; i++) str_new[i] = str[i];

	char* tmp = str; str = str_new; str_new = tmp;
	delete[] str_new;
}

void str_get(char*& str, int& str_size, int index)
{
	char* str_new = new char[--str_size];

	for (auto i = 0; i < str_size; i++) {
		if (i < index) str_new[i] = str[i];
		else str_new[i] = str[i + 1];
	}

	char* tmp = str; str = str_new; str_new = tmp;
	delete[] str_new;
}

void str_put(char*& str, int& str_size, char symbol, int index)
{
	if (index == -1) index = str_size - 1;
	char* str_new = new char[++str_size];

	for (auto i = 0; i < str_size; i++) {
		if (i < index) str_new[i] = str[i];
		if (i == index) str_new[i] = symbol;
		if (i > index) str_new[i] = str[i - 1];
	}

	char* tmp = str; str = str_new; str_new = tmp;
	delete[] str_new;
}

void str_symbol_delete(char*& str, int& str_size, char symbol)
{
	str_size -= str_symbol_count(str, str_size, symbol);
	char* str_new = new char[str_size];

	for (auto i = 0, j = 0; j < str_size; i++) 
		if (str[i] != symbol) str_new[j++] = str[i];
	
	char* tmp = str; str = str_new; str_new = tmp;
	delete[] str_new;
}

void str_symbol_replace(char*& str, char symbol_1, char symbol_2)
{
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] == symbol_1) str[i] = symbol_2;
}

int str_count_digits(char*& str)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] >= 48 && str[i] <= 57) count++;
	return count;
}

int str_count_letters(char*& str)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) count++;
	return count;
}