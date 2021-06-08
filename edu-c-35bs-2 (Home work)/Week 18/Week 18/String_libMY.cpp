#include "String_libMY.h"
#include <iostream>

char*  str_cin                ()
{
	char* str = new char[128]; auto i = 0;
	if (std::cin.peek() == '\n') std::cin.ignore();
	while ((str[i++] = static_cast<char>(getchar())) != '\n');
	str[--i] = '\0'; str_cut(str);
	return str;
}
int    str_len                (char* str)
{
	int count = 0;
	while (str[count] != '\0') count++;
	return count;
}
void   str_echo               (char* str)
{
	for (auto i = 0; str[i] != '\0'; i++) std::cout << str[i];
}

void   str_reverse            (char* str)
{
	int str_size = str_len(str);
	for (auto i = 0; i < str_size / 2; i++)
	{
		char tmp = str[i]; str[i] = str[str_size - 1 - i]; str[str_size - 1 - i] = tmp;
	}
}
void   str_uppercase          (char* str)
{
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] >= 97 && str[i] <= 122) str[i] = char(str[i] - 32);
}
void   str_lowercase          (char* str)
{
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] >= 65 && str[i] <= 90) str[i] = char(str[i] + 32);
}
void   str_up_begin           (char* str)
{
	char arr_end_sym[4] = { '.', '!', '?', ';' };
	for (auto i = 0; str[i] != '\0'; i++)
	{
		bool is_lower = false, is_new = false;
		if (str[i] >= 97 && str[i] <= 122) is_lower = true;
		if (i != 0 && is_lower && str[i - 1] == ' ')
		{
			for (char j : arr_end_sym)
				if (str[i - 2] == j) is_new = true;
		}

		if (is_lower && i == 0 || is_lower && is_new) str[i] = char(str[i] - 32);
	}
}

void   str_replace_symbol     (char* str, char symbol_1, char symbol_2)
{
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] == symbol_1) str[i] = symbol_2;
}
void   str_replace_word       (char*& str, char* old_word, char* new_word)
{
	int old_word_size = str_len(old_word);
	int new_word_size = str_len(new_word);

	for (auto i = 0, j = 0; str[i] != '\0'; i++, j = 0)
	{
		if (str[i] == '\0') break;
		while (str[i] == old_word[j] && j < old_word_size)
		{
			bool flag = false;
			if (j == old_word_size - 1)
			{
				if (old_word_size != new_word_size)
					str_put_range(str, i + 1, new_word_size - old_word_size);
					
				i =  i - old_word_size + 1;
				for (auto k = 0; k < new_word_size; k++, i++) str[i] = new_word[k];
				flag = true;
			}
			if (flag) j = 0;
			else { i++; j++; }
		}
	}
}

int    str_compare_length     (char* str_1, char* str_2)
{
	int str_1_len = str_len(str_1);
	int str_2_len = str_len(str_2);

	if (str_1_len > str_2_len) return  1;
	if (str_1_len < str_2_len) return -1;
	return 0;
}
bool   str_compare_content    (char* str_1, char* str_2)
{
	if (str_1 == str_2) return true;

	int i = -1;
	while (str_1[++i] != '\0')
		if (str_1[i] != str_2[i]) return false;

	return str_2[i] == '\0';
}

void   str_cut                (char*& str)
{
	int str_size = str_len(str) + 1;
	char* str_new = new char[str_size];

	for (auto i = 0; i < str_size; i++) str_new[i] = str[i];

	delete[] str; str = str_new;
}
void   str_put                (char*& str, char symbol, int index)
{
	int str_size = str_len(str) + 1;
	if (index == -1) index = str_size - 1;
	char* str_new = new char[str_size + 1];

	for (auto i = 0; i < str_size + 1; i++) {
		if (i < index) str_new[i] = str[i];
		if (i == index) str_new[i] = symbol;
		if (i > index) str_new[i] = str[i - 1];
	}

	delete[] str; str = str_new;
}
void   str_put_range          (char*& str, int start_index, int add_size)
{
	int new_size = str_len(str) + add_size + 1;
	char* str_new = new char[new_size];

	for (int i = 0; i < start_index; i++)                        str_new[i] = str[i];
	for (int i = new_size - 1; i >= start_index + add_size; i--) str_new[i] = str[i - add_size];
	for (int i = start_index; i < start_index + add_size; i++)   str_new[i] = ' ';

	delete[] str; str = str_new;
}
void   str_get                (char*& str, int index)
{
	int str_size = str_len(str);
	char* str_new = new char[str_size];

	for (auto i = 0; i < str_size; i++) {
		if (i < index) str_new[i] = str[i];
		else str_new[i] = str[i + 1];
	}

	delete[] str; str = str_new;
}
void   str_get_range          (char*& str, int start_index, int del_size)
{
	int new_size = str_len(str) - del_size + 1;
	char* str_new = new char[new_size];

	for (auto i = 0; i < new_size; i++) {
		if (i < start_index) str_new[i] = str[i];
		else str_new[i] = str[i + del_size];
	}

	delete[] str; str = str_new;
}

int    str_to_int             (char* str, int number_in_row)
{
	double number = 0;
	for (auto i = 0, count = 0; str[i] != '\0'; i++)
	{
		bool flag = false;

		int digits = i;
		while (str[i] >= 48 && str[i] <= 57) {
			flag = true;
			i++;
		}
		digits = i - digits;

		if (digits > 0) count++;

		if (count == number_in_row)
		{
			i -= digits;
			for (auto j = 0; j < digits; j++, i++)
			{
				number += double(str[i] - 48) / 10;
				number *= 10;
			}
			return int(number);
		}
		if (flag) i--;
	}
	return 0;
}
double str_to_double          (char* str, int number_in_row)
{
	double number = 0;
	for (auto i = 0, count = 0; str[i] != '\0'; i++)
	{
		bool flag = false;

		int digits = i;
		while (str[i] >= 48 && str[i] <= 57) { flag = true; i++; }
		digits = i - digits;

		int fraction = i;
		if (digits > 0 && (str[i] == 46 || str[i] == 44))
		{
			i++; while (str[i] >= 48 && str[i] <= 57) i++;
		}
		fraction = i - fraction - 1;
		
		if (digits > 0) count++;
		
		if (count == number_in_row)
		{
			i -= digits + 1 + fraction;
			for (auto j = 0; j < digits + 1 + fraction; j++, i++)
			{
				if (j < digits) number = (number + double(str[i] - 48) / 10) * 10;
				if (j > digits) number += double(str[i] - 48) / pow(10, j - digits);
			}
			return number;
		}
		if (flag) i--;
	}
	return 0;
}
char*  str_from_int           (int number)
{
	int count = 0, tmp = number;
	do {
		tmp /= 10;
		count++;
	} while (tmp > 0);

	char* str = new char[count + 1];
	for (auto i = count - 1; i > -1; i--)
	{
		str[i] = char(number % 10 + 48);
		number /= 10;
	}
	str[count] = '\0';

	return str;
}
char*  str_from_double        (double number, int accuracy)
{
	int count = accuracy + 1;

	int digits = int(number);
	do {
		digits /= 10;
		count++;
	} while (digits > 0);

	digits = int(number);
	double tmp_reverse_digits = 0;
	for (auto i = 0; i < count - accuracy - 1; i++)
	{
		tmp_reverse_digits = (tmp_reverse_digits + double(digits % 10) / 10) * 10;
		digits /= 10;
	}
	int reverse_digits = int(tmp_reverse_digits);

	int fraction = int(double(number - int(number) + (1 / pow(100, accuracy))) * pow(10, accuracy));
	double tmp_reverse_fraction = 0;
	for (auto i = 0; i < accuracy; i++)
	{
		tmp_reverse_fraction = (tmp_reverse_fraction + double(fraction % 10) / 10) * 10;
		fraction /= 10;
	}
	int reverse_fraction = int(tmp_reverse_fraction);

	char* str = new char[count + 1];
	for (auto i = 0; i < count; i++)
	{
		if (i < count - accuracy - 1)
		{
			str[i] = char(reverse_digits % 10 + 48);
			reverse_digits /= 10;
		}
		if (i == count - accuracy - 1) str[i] = '.';
		if (i > count - accuracy - 1)
		{
			str[i] = char(reverse_fraction % 10 + 48);
			reverse_fraction /= 10;
		}
	}
	str[count] = '\0';

	return str;
}

int    str_count_symbol       (char* str, char symbol)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] == symbol) count++;

	return count;
}
int    str_count_digits       (char* str)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] >= 48 && str[i] <= 57) count++;
	return count;
}
int    str_count_letters      (char* str)
{
	int count = 0;
	for (auto i = 0; str[i] != '\0'; i++)
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) count++;
	return count;
}
int    str_count_word         (char* str, char* word)
{
	int str_size = str_len(str);
	int word_size = str_len(word);
	
	int count = 0;
	for (auto i = 0, j = 0; i < str_size; i++, j = 0)
	{
		while(str[i] == word[j] && j < word_size)
		{
			i++; j++;
			if (j == word_size) { count++; i--; }
		}
	}
	return count;
}

int    str_pos_word_first     (char* str, char* word)
{
	int str_size = str_len(str);
	int word_size = str_len(word);

	for (auto i = 0, j = 0; i < str_size; i++, j = 0)
	{
		while (str[i] == word[j] && j < word_size)
		{
			if (j == word_size - 1) return i - word_size + 1;
			i++; j++;
		}
	}
	return -1;
}
int    str_pos_word_last      (char* str, char* word)
{
	int str_size = str_len(str);
	int word_size = str_len(word);
	
	for (auto i = str_size, j = word_size; i >= 0; i--, j = word_size)
	{
		while (str[i] == word[j] && j >= 0)
		{
			if (j == 0) return i;
			i--; j--;
		}
	}
	return -1;
}

void   str_delete_symbol      (char*& str, char symbol)
{
	int str_size = str_len(str) + 1 - str_count_symbol(str, symbol);
	char* str_new = new char[str_size];

	for (auto i = 0, j = 0; j < str_size; i++)
		if (str[i] != symbol) str_new[j++] = str[i];

	delete[] str; str = str_new;
}
void   str_delete_word        (char*& str, char* word)
{
	int word_size = str_len(word);

	for (auto i = 0, j = 0; str[i] != '\0'; i++, j = 0)
	{
		while (str[i] == word[j] && j < word_size)
		{
			bool flag = false;
			if (j == word_size - 1)
			{
				str_get_range(str, i - word_size + 1, word_size);
				flag = true;
			}
			if (flag) { i -= word_size - 1; j = 0; }
			else { i++; j++; }
		}
	}
}
void   str_delete             (char* str_1, char* str_2, char* str_3, char* str_4, char* str_5)
{
	delete[] str_1; delete[] str_2; delete[] str_3; delete[] str_4; delete[] str_5;
}

int    str_split              (char* str, char**& arr_words, char separator)
{
	int count_words = 1;
	for (auto i = 0; str[i] != '\0'; i++)
		if (str[i] == separator) count_words++;
	
	arr_words = new char* [count_words];
	for (auto i = 0, tmp = 0; str[i] != '\0'; i++)
	{
		if (str[i] != separator)
		{
			int word_size = 1;
			while (str[i + word_size] != separator) word_size++;

			arr_words[tmp] = new char[word_size + 1];
			for (auto j = 0; j < word_size; j++) arr_words[tmp][j] = str[i++];
			arr_words[tmp++][word_size] = '\0';
		}
	}
	return count_words;
}

int    str_count_copy_digits  (char* str, int**& arr_digits)
{
	int arr_size = 0;

	arr_digits = new int* [10]; int tmp = 0;
	for (auto i = 0; i < 10; i++) arr_digits[i] = new int[2]{};

	int str_size = str_len(str) + 1;
	char* clone = new char[str_size];
	for (auto i = 0; i < str_size; i++) clone[i] = str[i];

	for (auto i = 0; clone[i] != '\0'; i++)
	{
		int count_tmp_sym = 1;
		if (clone[i] >= 48 && clone[i] <= 57)
		{
			arr_digits[tmp][0] = int(clone[i]);
			for (auto j = i + 1; clone[j] != '\0'; j++)
				if (clone[i] == clone[j]) count_tmp_sym++;
			arr_digits[tmp][1] = count_tmp_sym;

			str_delete_symbol(clone, clone[i--]);
			arr_size++;
			tmp++;
		}
	}
	delete[] clone;
	return arr_size;
}
int    str_count_copy_letters (char* str, int**& arr_letter)
{
	int arr_size = 0;

	arr_letter = new int* [26]; int tmp = 0;
	for (auto i = 0; i < 26; i++) arr_letter[i] = new int[2]{};
	
	int str_size = str_len(str) + 1;
	char* clone = new char[str_size];
	for (auto i = 0; i < str_size; i++) clone[i] = str[i];
	
	for (auto i = 0, tmp_32 = 0; clone[i] != '\0'; i++)
	{
		int count_tmp_sym = 1;
		if ((clone[i] >= 65 && clone[i] <= 90) || (clone[i] >= 97 && clone[i] <= 122))
		{
			if (clone[i] >= 97 && clone[i] <= 122)
			{ tmp_32 = -32; arr_letter[tmp][0] = int(clone[i] + tmp_32); }
			else 
			{ tmp_32 =  32; arr_letter[tmp][0] = int(clone[i]); }
			
			for (auto j = i + 1; clone[j] != '\0'; j++)
			{
				if (((clone[j] >= 65 && clone[j] <= 90) || (clone[j] >= 97 && clone[j] <= 122)) &&
					(clone[i] == clone[j] || clone[i] == char(clone[j] + tmp_32))) count_tmp_sym++;
			}
			
			arr_letter[tmp][1] = count_tmp_sym;
			
			str_delete_symbol(clone, char(clone[i] + tmp_32));
			str_delete_symbol(clone, clone[i--]);
			
			arr_size++;
			tmp++;
		}
	}
	delete[] clone;
	return arr_size;
}
