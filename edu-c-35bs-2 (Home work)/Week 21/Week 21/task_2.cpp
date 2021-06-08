/**
 * Дан текстовый файл. Необходимо создать новый файл и записать в него следующую статистику по исходному файлу:
 * - Количество символов;
 * - Количество строк;
 * - Количество гласных букв;
 * - Количество согласных букв;
 * - Количество цифр.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

void putc_one_line (FILE* file, const char* description, int value)
{
    for (auto i = 0; i < (int)strlen(description); i++)
        putc(description[i], file);

    int count = 0, tmp = value;
    do {
        tmp /= 10;
        count++;
    } while (tmp > 0);

    char* str_count_symbols = new char[count + 1];
    for (auto i = count - 1; i > -1; i--)
    {
        str_count_symbols[i] = char(value % 10 + 48);
        value /= 10;
    }
    str_count_symbols[count] = '\0';
	
    for (auto i = 0; i < (int)strlen(str_count_symbols); i++)
        putc(str_count_symbols[i], file);

    delete[] str_count_symbols;
    putc('\n', file);
}

void task_2()
{
    do {
        const char* file_1 = "task_2_file_1.txt";
        const char* file_2 = "task_2_file_2.txt";
    	
		char tmp_byte;
        int count_characters = 0, count_lines = 1, count_vowels = 0, count_consonants = 0, count_digits = 0;
    	
		FILE* file_1_ptr = fopen(file_1, "r");
		if (file_1_ptr == NULL) { perror("Error: File not found!"); exit(0); }

			while ((tmp_byte = (char)getc(file_1_ptr)) != EOF)
			{
                count_characters++;
				if (tmp_byte == '\n') count_lines++;
				for (int i = 0, min = 97, max = 122; i < 2; i++, min -= 32, max -= 32)
				{
					if (tmp_byte >= min && tmp_byte <= max)
					{
						if (tmp_byte == min || tmp_byte == min + 4 || tmp_byte == min + 8 || tmp_byte == min + 14 || tmp_byte == min + 20) count_vowels++;
                        else if (tmp_byte == min + 24)
                        {
                            count_vowels++;
                            count_consonants++;
                        }
						else count_consonants++;
					}
				}
				if (tmp_byte >= 48 && tmp_byte <= 57) count_digits++;
			}
    	
        fclose(file_1_ptr);
    	
        FILE* file_2_ptr = fopen(file_2, "w");
        if (file_2_ptr == NULL) { perror("Error: File not found!"); exit(0); }

	        putc_one_line(file_2_ptr, "The number of characters: ", count_characters);
	        putc_one_line(file_2_ptr, "The number of lines: "     , count_lines);
	        putc_one_line(file_2_ptr, "The number of vowels: "    , count_vowels);
	        putc_one_line(file_2_ptr, "The number of consonants: ", count_consonants);
	        putc_one_line(file_2_ptr, "The number of digits: "    , count_digits);
    	
        fclose(file_2_ptr);

        std::cout << "\n Done\n";
    	
    } while (task_restart());
}
