/**
 * Дан текстовый файл. Посчитать сколько раз в нем встречается заданное пользователем слово.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

void task_6()
{
	do {

		if (std::cin.peek() == '\n') std::cin.ignore();
		std::cout << " Enter word: "; char key[32]; gets_s(key);

		const char* file_1 = "task_6_file.txt";
		FILE* file_1_ptr = fopen(file_1, "r"); if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }

		auto i = 0;
		char tmp_byte;
		int key_count = 0;
		
		while ((tmp_byte = (char)getc(file_1_ptr)) != EOF)
		{
			if (tmp_byte == key[i]) i++;
			else i = 0;
			if (key[i] == '\0') { key_count++; i = 0; }
		}
		fclose(file_1_ptr);

		std::cout << "\n The number of words \"" << key << "\" in the text: " << key_count << "\n";
		
	} while (task_restart());
}