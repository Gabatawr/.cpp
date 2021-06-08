#pragma once
#include <iostream>

char* str_in             ();                   // ввод новой строки
int   str_count_word     (char*, char*);       // подсчет кол-ва слов в строке
bool  str_has_word       (char*, char*);       // есть ли слово в строке
int   str_to_int         (char*, int = 1);     // вернуть число из строки по номеру его вхождения
int   str_count_int      (char*);              // подсчет кол-ва целочисленных чисел в строке
char* str_between_quotes (char*, char = '\"'); // вернуть часть строки между кавычками ("" - по умолчанию)
int   str_compare        (char*, char*);       // сравнить строки посимвольно в алфавитном порядке