#pragma once


/**
 * Сортирует массив структур(array_pointer) по полю строки(string_field) в алфавитном порядке.
 * !! Требуеться реализация перегрузки операторов: копирования, присваивания и [] - возвращающий нужное поле char* по индексу
 */
template <typename T>
void alph_qsort(T* array_pointer, int string_field, int first, int last, int(*fun_compare)(char*, char*))
{
	int f = first, l = last;
	T mid = array_pointer[(f + l) / 2];

	while (f < l) 
	{
		while (fun_compare(array_pointer[f][string_field], mid[string_field]) == -1) f++;
		while (fun_compare(array_pointer[l][string_field], mid[string_field]) ==  1) l--;
		if (f <= l)
		{
			T tmp = array_pointer[f];
			array_pointer[f] = array_pointer[l];
			array_pointer[l] = tmp; f++; l--;
		}
	}

	if (first < l) alph_qsort(array_pointer, string_field, first, l, fun_compare);
	if (f < last) alph_qsort(array_pointer, string_field, f, last, fun_compare);
}