/**
 * Дан текстовый файл. Найти и заменить в нем заданное слово. Что искать и на что заменять определяется пользователем.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

void put_range(char*& str, int start_index, int add_size)
{
	int new_size = strlen(str) + add_size + 1;
	char* str_new = new char[new_size];

	for (int i = 0; i < start_index; i++)                        str_new[i] = str[i];
	for (int i = new_size - 1; i >= start_index + add_size; i--) str_new[i] = str[i - add_size];
	for (int i = start_index; i < start_index + add_size; i++)   str_new[i] = ' ';

	delete[] str; str = str_new;
}

void str_replace(char*& str, char* old_word, char* new_word)
{
	int old_word_size = strlen(old_word);
	int new_word_size = strlen(new_word);

	for (auto i = 0, j = 0; str[i] != '\0'; i++, j = 0)
	{
		if (str[i] == '\0') break;
		while (str[i] == old_word[j] && j < old_word_size)
		{
			bool flag = false;
			if (j == old_word_size - 1)
			{
				if (old_word_size != new_word_size)
					put_range(str, i + 1, new_word_size - old_word_size);

				i = i - old_word_size + 1;
				for (auto k = 0; k < new_word_size; k++, i++) str[i] = new_word[k];
				flag = true;
			}
			if (flag) j = 0;
			else { i++; j++; }
		}
	}
}

char* str_enter()
{
	char* str = new char[128]; auto i = 0;
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


void task_7()
{
	do {

		std::cout << "\n Replace: "; char* replace = str_enter();
		std::cout << " Replacement: "; char* replacement = str_enter();
		
		char tmp_byte;
		
		const char* file_1 = "task_7_file.txt";
		FILE* file_1_ptr = fopen(file_1, "r"); if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }

			fseek(file_1_ptr, 0, SEEK_END);
			int buffer_size = ftell(file_1_ptr) + 1;
			fseek(file_1_ptr, 0, SEEK_SET);

			char* buffer = new char[buffer_size];
			
			int str_count = 1;
			for (int data_size = 0; (tmp_byte = (char)getc(file_1_ptr)) != EOF; data_size++)
			{
				if (tmp_byte == '\n') str_count++;
				buffer[data_size] = tmp_byte;
			}
			buffer[buffer_size - str_count] = '\0';
		
		fclose(file_1_ptr);
		
		str_replace(buffer, replace, replacement);

		file_1_ptr = fopen(file_1, "w"); if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }

			for (auto i = 0; buffer[i] != '\0'; i++) putc(buffer[i], file_1_ptr);

		fclose(file_1_ptr);
		
		delete[] buffer;
	} while (task_restart());
}