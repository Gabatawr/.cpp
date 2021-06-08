#pragma once
const int str_limit = 128;


void str_echo(char*& str);

int str_len(char*& str, int str_size = str_limit);

bool str_equal(char*& str_1, char*& str_2, int str_size = str_limit);

int str_symbol_count(char*& str, int str_size, char symbol);

void str_cut_trash(char*& str, int& str_size);

void str_get(char*& str, int& str_size, int index);

void str_put(char*& str, int& str_size, char symbol, int index = -1);

void str_symbol_delete(char*& str, int& str_size, char symbol);

void str_symbol_replace(char*& str, char symbol_1, char symbol_2);

int str_count_digits(char*& str);

int str_count_letters(char*& str);