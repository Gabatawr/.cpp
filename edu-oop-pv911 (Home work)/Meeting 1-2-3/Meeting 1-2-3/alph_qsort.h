#pragma once

/**
 * Сортирует массив указателей классов(array_pointer) по полю строки(string_field) в алфавитном порядке.
 * !! Требуеться реализация перегрузки оператора [] - возвращающего нужное поле char* по индексу
 */
template <typename T>
void alph_qsort(T**& array_pointer, int string_field, int first, int last, int(*fun_compare)(char*, char*))
{
	int f = first, l = last;
	int mid = (f + l) / 2;

	while (f < l)
	{
		while (fun_compare(array_pointer[f]->operator[](string_field), array_pointer[mid]->operator[](string_field)) == -1) f++;
		while (fun_compare(array_pointer[l]->operator[](string_field), array_pointer[mid]->operator[](string_field)) ==  1) l--;
		if (f <= l)
		{
			T* tmp = array_pointer[f];
			array_pointer[f] = array_pointer[l];
			array_pointer[l] = tmp; f++; l--;
		}
	}

	if (first < l) alph_qsort(array_pointer, string_field, first, l, fun_compare);
	if (f < last) alph_qsort(array_pointer, string_field, f, last, fun_compare);
}