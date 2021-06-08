/**
 * Дан текстовый файл. Найти длину самой длинной строки.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

void task_5()
{
	do {

		const char* file_1 = "task_5_file.txt";

		FILE* file_1_ptr = fopen(file_1, "r"); if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }

		char tmp_byte;
		int str_max = 1;
		int str_count = 1;
		int count_max = 0;
		int counter = 0;
		
		while ((tmp_byte = (char)getc(file_1_ptr)) != EOF)
		{
			counter++;
			if (tmp_byte == '\n')
			{
				if (counter - 1 > count_max)
				{
					count_max = counter - 1;
					str_max = str_count;
				}
				str_count++;
				counter = 0;
			}
		}
		fclose(file_1_ptr);

		std::cout << "\n Largest line number " << str_max << "[" << count_max << "]\n";
		
	} while (task_restart());
}