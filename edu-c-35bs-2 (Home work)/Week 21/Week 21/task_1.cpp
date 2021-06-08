/**
 * Дано два текстовых файла. Выяснить, совпадают ли их строки.
 * Если нет, то вывести несовпадающую строку из каждого файла.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

/**
* _opt вариант предлагает использование буфера в качестве массива строк.
* Экономит память и время, но существенно ограничивает дальнейшую гибкость работы с массивом в плане отдельных строк.
* Рекомендуется к использованию если массив не предполагает редактирование.
*/
char** create_arr_str_from_file_opt(const char* file_name, int& str_count)
{
	FILE* file_ptr = fopen(file_name, "r");
	if (file_ptr == NULL) { perror("Error: File not found!"); exit(0); }

	fseek(file_ptr, 0, SEEK_END);
	int buffer_size = ftell(file_ptr) + 1;
	fseek(file_ptr, 0, SEEK_SET);

	char* buffer = new char[buffer_size];

	char tmp_byte; str_count = 1;
	for (int data_size = 0; (tmp_byte = (char)getc(file_ptr)) != EOF; data_size++)
	{
		if (tmp_byte == '\n') { tmp_byte = '\0'; str_count++; }
		buffer[data_size] = tmp_byte;
	}
	buffer[buffer_size - str_count] = '\0';

	fclose(file_ptr);

	char** arr_str = new char* [str_count];

	arr_str[0] = (char*)buffer;
	for (int i = 1, str_ptr = 1; str_ptr < str_count; i++)
		if (buffer[i] == '\0') arr_str[str_ptr++] = (char*)buffer + i + 1;

	return arr_str;
}
char** create_arr_str_from_file    (const char* file_name, int& str_count)
{
	FILE* file_ptr = fopen(file_name, "r");
	if (file_ptr == NULL) { perror("Error: File not found!"); exit(0); }

		fseek(file_ptr, 0, SEEK_END);
		int buffer_size = ftell(file_ptr) + 1;
		fseek(file_ptr, 0, SEEK_SET);

		char* buffer = new char[buffer_size];
	
		char tmp_byte; str_count = 1;
		for (int data_size = 0; (tmp_byte = (char)getc(file_ptr)) != EOF; data_size++)
		{
			if (tmp_byte == '\n') str_count++;
			buffer[data_size] = tmp_byte;
		}
		buffer[buffer_size - str_count] = '\n';
	
	fclose(file_ptr);

	char** arr_str = new char* [str_count];
	for (auto i = 0, c = 0, str_len = 0; c < str_count; i++, str_len++)
	{
		if (buffer[i] == '\n')
		{
			arr_str[c] = new char[str_len + 1];
			for (auto j = 0; j < str_len; j++) arr_str[c][j] = buffer[i - str_len + j];
			arr_str[c][str_len] = '\0';

			str_len = -1;
			c++;
		}
	}

	delete[] buffer;
	return arr_str;
}

void task_1()
{
	do {
		const char* file_1 = "task_1_file_1.txt";
		const char* file_2 = "task_1_file_2.txt";

		int str_count_1;
		char** arr_str_1 = create_arr_str_from_file(file_1, str_count_1);

		int str_count_2;
		char** arr_str_2 = create_arr_str_from_file(file_2, str_count_2);

		for (auto i = 0; i < str_count_1 && i < str_count_2; i++)
		{
			if (strcmp(arr_str_1[i], arr_str_2[i]) == 0) continue;

			std::cout << "\n #" << i + 1 << " (" << file_1 << "): \"" << (const char*)arr_str_1[i]
			<< "\" NOT EQUAL #" << i + 1 << " (" << file_2 << "): \"" << (const char*)arr_str_2[i] << "\"";
		}

		if (str_count_1 != str_count_2)
		{
			if (str_count_1 > str_count_2)
			{
				int difference = str_count_1 - str_count_2;
				for (auto i = difference; i > 0; i--)
				{
					std::cout << "\n #" << str_count_1 - i + 1 << " (" << file_1 << "): \"" << (const char*)arr_str_1[str_count_1 - i]
					<< "\" NOT IN (" << file_2 << ")";
				}	
			}
			else
			{
				int difference = str_count_2 - str_count_1;
				for (auto i = difference; i > 0; i--)
				{
					std::cout << "\n #" << str_count_2 - i + 1 << " (" << file_2 << "): \"" << (const char*)arr_str_2[str_count_2 - i]
					<< "\" NOT IN (" << file_1 << ")";
				}
			}
		}

		for (auto i = 0; i < str_count_1; i++)
			delete[] arr_str_1[i];
		delete[] arr_str_1;

		for (auto i = 0; i < str_count_2; i++)
			delete[] arr_str_2[i];
		delete[] arr_str_2;

		// if use opt
		//delete[] arr_str_1[0]; delete[] arr_str_1;
		//delete[] arr_str_2[0]; delete[] arr_str_2;
		
		std::cout << "\n\n";
	} while (task_restart());
}
	
