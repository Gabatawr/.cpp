/**
 * Дан текстовый файл. Удалить из него последнюю строку. Результат записать в другой файл.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

void task_4()
{
	do {
		
		const char* file_1 = "task_4_file_1.txt";
		const char* file_2 = "task_4_file_2.txt";

		char tmp_byte;
		int str_count = 1;
		
		/**
		 * Вариант от начала в конец, считаем количество строк, останавливаем запись если достигли последней строки
		 * 
		FILE* file_1_ptr = fopen(file_1, "r"); if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }
		while ((tmp_byte = (char)getc(file_1_ptr)) != EOF) if (tmp_byte == '\n') str_count++;
		fseek(file_1_ptr, 0, SEEK_SET);

		int str_count_tmp = 1;
		FILE* file_2_ptr = fopen(file_2, "w"); if (file_2_ptr == NULL) { perror("Error: File not found!"); exit(0); }
		while ((tmp_byte = (char)getc(file_1_ptr)) != EOF)
		{
			if (tmp_byte == '\n') str_count_tmp++;
			if (str_count_tmp == str_count) break;
			putc(tmp_byte, file_2_ptr);
		}
		
		fclose(file_1_ptr);
		fclose(file_2_ptr);
		*/

		// С конца в начало быстрее лучше эффективнее)
		FILE* file_1_ptr = fopen(file_1, "r"); if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }
		fseek(file_1_ptr, -1, SEEK_END);
		
		long end = -1;
		while (ftell(file_1_ptr) != 1)
		{
			tmp_byte = (char)getc(file_1_ptr);
			if (tmp_byte == '\n')
			{
				fseek(file_1_ptr, -2, SEEK_CUR);
				end = ftell(file_1_ptr);
				break;
			}
			fseek(file_1_ptr, -2, SEEK_CUR);
		}
		
		if (end == -1)
		{
			fclose(file_1_ptr);
			break;
		}
		
		fseek(file_1_ptr, 0, SEEK_SET);
		
		FILE* file_2_ptr = fopen(file_2, "w"); if (file_2_ptr == NULL) { perror("Error: File not found!"); exit(0); }
		
		while (end > ftell(file_1_ptr)) putc((char)getc(file_1_ptr), file_2_ptr);
		
		fclose(file_1_ptr);
		fclose(file_2_ptr);
		
		std::cout << "\n Done\n";
	} while (task_restart());
}