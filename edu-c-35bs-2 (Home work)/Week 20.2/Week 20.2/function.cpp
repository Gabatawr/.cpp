#include <iostream>
#include <cstdlib>


/*
 * В файле function.cpp необходимо написать следующие функции для работы с массивом данных:
 *  a) функцию для заполнения массива случайными зна­чениями;
 *  b) функцию для вывода значений массива на консоль;
 *  c) функцию для поиска минимального элемента;
 *  d) функцию для поиска максимального элемента;
 *  e) функцию для сортировки;
 *  f) функцию для редактирования значения массива.
 * Данные функции необходимо написать для работы с массивом целых, действительных и символьных значений.
 * (Для каждого типа написать отдельную функцию).
 */


#pragma region FillArrRandVal

// Функция для заполнения массива случайными зна­чениями типа int
void FillArrRandVal(int* array, int size, bool unique, int min, int max)
{
	for (auto i = 0; i < size; i++)
	{
        array[i] = rand() % (max + 1 - min) + min;
        if (unique)   for (auto j = 0; j < i; j++)    if (array[i] == array[j])   i--;
	}
}

// Функция для заполнения массива случайными зна­чениями типа char
void FillArrRandVal(char* array, int size, bool unique, char min = 0, char max = 127)
{
    if (min < 0) min = 0;
    if (max > 127) max = 127;
	
	for (auto i = 0; i < size; i++)
    {
        array[i] = char(rand() % int(max + 1 - min) + min);
        if (unique)   for (auto j = 0; j < i; j++)    if (array[i] == array[j])   i--;
    }
}

// Функция для заполнения массива случайными зна­чениями типа double
void FillArrRandVal(double* array, int size, bool unique, double min, double max, int accuracy = 2)
{
    for (auto i = 0; i < size; i++)
    {
        array[i] = double(rand() % int(max + 1 - min) + min) + double(rand() % int(pow(10, accuracy))) / pow(10, accuracy);
        if (array[i] > max || array[i] < min) { i--; continue; }
        if (unique)   for (auto j = 0; j < i; j++)    if (array[i] == array[j])   i--;
    }
}

#pragma endregion

#pragma region PrintArrVal

// Функция для вывода на консоль значений массива типа int
void PrintArrVal(int* array, int size)
{
    std::cout << "{ ";
    for (auto i = 0; i < size; i++)
    {
        std::cout << array[i];
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << " }";
}

// Функция для вывода на консоль значений массива типа char
void PrintArrVal(char* array, int size)
{
    std::cout << "{ '";
    for (auto i = 0; i < size; i++)
    {
        std::cout << array[i];
        if (i != size - 1) std::cout << "', '";
    }
    std::cout << "' }";
}

// Функция для вывода на консоль значений массива типа double
void PrintArrVal(double* array, int size)
{
    std::cout << "{ ";
    for (auto i = 0; i < size; i++)
    {
        std::cout << array[i];
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << " }";
}

#pragma endregion

#pragma region FindArrMinVal

// Функция поиска минимального элемента в массиве типа int
int FindArrMinVal(int* array, int size)
{
    int min = array[0];
    for (auto i = 1; i < size; i++)
    {
        if (array[i] < min) min = array[i];
    }
    return min;
}

// Функция поиска минимального элемента в массиве типа char
char FindArrMinVal(char* array, int size)
{
    char min = array[0];
    for (auto i = 1; i < size; i++)
    {
        if (array[i] < min) min = array[i];
    }
    return min;
}

// Функция поиска минимального элемента в массиве типа double
double FindArrMinVal(double* array, int size)
{
    double min = array[0];
    for (auto i = 1; i < size; i++)
    {
        if (array[i] < min) min = array[i];
    }
    return min;
}

#pragma endregion

#pragma region FindArrMaxVal

// Функция поиска максимального элемента в массиве типа int
int FindArrMaxVal(int* array, int size)
{
    int max = array[0];
    for (auto i = 1; i < size; i++)
    {
        if (array[i] > max) max = array[i];
    }
    return max;
}

// Функция поиска максимального элемента в массиве типа char
char FindArrMaxVal(char* array, int size)
{
    char max = array[0];
    for (auto i = 1; i < size; i++)
    {
        if (array[i] > max) max = array[i];
    }
    return max;
}

// Функция поиска максимального элемента в массиве типа double
double FindArrMaxVal(double* array, int size)
{
    double max = array[0];
    for (auto i = 1; i < size; i++)
    {
        if (array[i] > max) max = array[i];
    }
    return max;
}

#pragma endregion

#pragma region qSortArrVal

// Функция для сортировки массива типа int
void qSortArrVal(int* array, int size, int first_index = 0, int last_index = -2)
{
    if (last_index == -2 || last_index >= size) last_index = size - 1;
    if (first_index < 0) first_index = 0;
	
    int first_tmp = first_index;
    int last_tmp = last_index;
    int mid = array[(first_tmp + last_tmp) / 2];

    while (first_tmp < last_tmp) {
        while (array[first_tmp] < mid) first_tmp++;
        while (array[last_tmp] > mid) last_tmp--;
        if (first_tmp <= last_tmp) std::swap(array[first_tmp++], array[last_tmp--]);
    }

    if (first_index < last_tmp) qSortArrVal(array, size, first_index, last_tmp);
    if (first_tmp < last_index) qSortArrVal(array, size, first_tmp, last_index);
}

// Функция для сортировки массива типа char
void qSortArrVal(char* array, int size, int first_index = 0, int last_index = -2)
{
    if (last_index == -2 || last_index >= size) last_index = size - 1;
    if (first_index < 0) first_index = 0;

    int first_tmp = first_index;
    int last_tmp = last_index;
    char mid = array[(first_tmp + last_tmp) / 2];

    while (first_tmp < last_tmp) {
        while (array[first_tmp] < mid) first_tmp++;
        while (array[last_tmp] > mid) last_tmp--;
        if (first_tmp <= last_tmp) std::swap(array[first_tmp++], array[last_tmp--]);
    }

    if (first_index < last_tmp) qSortArrVal(array, size, first_index, last_tmp);
    if (first_tmp < last_index) qSortArrVal(array, size, first_tmp, last_index);
}

// Функция для сортировки массива типа double
void qSortArrVal(double* array, int size, int first_index = 0, int last_index = -2)
{
    if (last_index == -2 || last_index >= size) last_index = size - 1;
    if (first_index < 0) first_index = 0;

    int first_tmp = first_index;
    int last_tmp = last_index;
    double mid = array[(first_tmp + last_tmp) / 2];

    while (first_tmp < last_tmp) {
        while (array[first_tmp] < mid) first_tmp++;
        while (array[last_tmp] > mid) last_tmp--;
        if (first_tmp <= last_tmp) std::swap(array[first_tmp++], array[last_tmp--]);
    }

    if (first_index < last_tmp) qSortArrVal(array, size, first_index, last_tmp);
    if (first_tmp < last_index) qSortArrVal(array, size, first_tmp, last_index);
}

#pragma endregion

/*
#pragma region EditArrVal

// Функция для редактирования значения массива типа int
void EditArrVal(int* array, int index_edit_el)
{

}

#pragma endregion
*/