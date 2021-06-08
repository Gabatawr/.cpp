#pragma once

char*  str_cin                ();                                           // ввод строки (с пробелами и табуляцией)
void   str_cin                (char*& str);                                  // ввод нового значения

int    str_len                (char* str);                                  // длинна строки (без учета '\0')
void   str_echo               (char* str);                                  // печать строки

void   str_reverse            (char* str);                                  // реверс строки
void   str_uppercase          (char* str);                                  // буквы в верхний регистр
void   str_lowercase          (char* str);                                  // буквы в нижний регистр
void   str_up_begin           (char* str);                                  // каждое новое предложение с большой буквы

void   str_replace_symbol     (char* str, char symbol_1, char symbol_2);    // заменить символ
void   str_replace_word       (char*& str, char* old_word, char* new_word); // заменить слово

int    str_compare_length     (char* str_1, char* str_2);                   // сравнить строки по длинне
bool   str_compare_content    (char* str_1, char* str_2);                   // сравнить строки по содержанию

void   str_cut                (char*& str);                                 // обрезать мусор после '\0'
void   str_put                (char*& str, char symbol, int index = -1);    // добавить ячейку по индексу (по умолчанию в конец)
void   str_put_range          (char*& str, int start_index, int add_size);  // добавить несколько ячеек по индексу
void   str_get                (char*& str, int index);                      // удалить ячейку по индексу
void   str_get_range          (char*& str, int start_index, int del_size);  // удалить несколько ячеек начиная с индекса

int    str_to_int             (char* str, int number_in_row = 1);           // взять целочислинное число по номеру вхождения (по умолчанию первое)
double str_to_double          (char* str, int number_in_row = 1);           // взять дробное число по номеру вхождения (по умолчанию первое)
char*  str_from_int           (int number);                                 // преобразовать целочислинное число в строку
char*  str_from_double        (double number, int accuracy = 2);            // преобразовать дробное число в строку с заданой точностью

int    str_count_symbol       (char* str, char symbol);                     // подсчитать кол-во заданого символа
int    str_count_digits       (char* str);                                  // подсчитать кол-во цифр
int    str_count_letters      (char* str);                                  // подсчитать кол-во букв
int    str_count_word         (char* str, char* word);                      // подсчитать кол-во заданого слова

int    str_pos_word_first     (char* str, char* word);                      // вернуть индекс начала слова по его первому входжению
int    str_pos_word_last      (char* str, char* word);                      // вернуть индекс начала слова по его последнему входжению

void   str_delete_symbol      (char*& str, char symbol);                    // удалить из строки заданый символ
void   str_delete_word        (char*& str, char* word);                     // удалить из строки заданое слово
void   str_delete             (char* str_1,                                 // удалить строки (за один раз не более 5)
	                           char* str_2 = nullptr,
	                           char* str_3 = nullptr,
	                           char* str_4 = nullptr,
	                           char* str_5 = nullptr);

int    str_split              (char* str, char**& arr_words, char = ' ');   // попилить строку на массив строк по разделителю (по умолчанию пробел)

int    str_count_copy_digits  (char* str, int**& arr_digits);               // подсчитать кол-во повторений каждой встречающейся цифры в сроке
int    str_count_copy_letters (char* str, int**& arr_letter);               // подсчитать кол-во повторений каждой встречающейся буквы в сроке
