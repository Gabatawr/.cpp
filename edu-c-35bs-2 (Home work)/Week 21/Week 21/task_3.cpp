/**
 * Дан текстовый файл. Зашифровать его, используя шифр Цезаря. Результат записать в другой файл.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "declaration.h"

#pragma execution_character_set( "utf-8" )

void task_3()
{
    do {
        int code = 2;
    	
		const char* file_1 = "task_3_file_1.txt";
		const char* file_2 = "task_3_file_2.txt";

        // read and create array string from file_1;
		int str_count;
		char** arr_str = create_arr_str_from_file(file_1, str_count);

        // encode array string;
    	for (auto i = 0; i < str_count; i++)
    	{
    		for (auto j = 0; arr_str[i][j] != '\0'; j++)
    		{
                for (int k = 0, min = 97, max = 122; k < 2; k++, min -= 32, max -= 32)
                {
                    if (arr_str[i][j] >= min && arr_str[i][j] <= max)
                    {
                        if (arr_str[i][j] + code > max) arr_str[i][j] = (char)code - (max - (int)arr_str[i][j]) + min;
                        else arr_str[i][j] += (char)code;
                    }
                }
    		}
    	}

        // write array string of file_2;
        FILE* file_2_ptr = fopen(file_2, "w");
        if (file_2_ptr == NULL) { perror("Error: File not found!"); exit(0); }
	        for (auto i = 0; i < str_count; i++)
	        {
                for (auto j = 0; arr_str[i][j] != '\0'; j++)
                    putc(arr_str[i][j], file_2_ptr);
                if (i < str_count - 1) putc('\n', file_2_ptr);
	        }  
        fclose(file_2_ptr);

        for (auto i = 0; i < str_count; i++)
            delete[] arr_str[i];
        delete[] arr_str;

        std::cout << "\n Done\n";
    } while (task_restart());
}