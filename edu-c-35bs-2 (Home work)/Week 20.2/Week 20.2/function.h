#pragma once


#ifdef INTEGER
	// Функция для заполнения массива случайными зна­чениями типа int
	void FillArrRandVal(int* array, int size, bool unique, int min, int max);
	// Функция для вывода на консоль значений массива типа int
	void PrintArrVal(int* array, int size);
	// Функция поиска минимального элемента в массиве типа int
	int FindArrMinVal(int* array, int size);
	// Функция поиска максимального элемента в массиве типа int
	int FindArrMaxVal(int* array, int size);
	// Функция для сортировки массива типа int
	void qSortArrVal(int* array, int size, int first_index = 0, int last_index = -2);
#endif

#ifdef CHAR
	// Функция для заполнения массива случайными зна­чениями типа char
	void FillArrRandVal(char* array, int size, bool unique, char min = 0, char max = 127);
	// Функция для вывода на консоль значений массива типа char
	void PrintArrVal(char* array, int size);
	// Функция поиска минимального элемента в массиве типа char
	char FindArrMinVal(char* array, int size);
	// Функция поиска максимального элемента в массиве типа char
	char FindArrMaxVal(char* array, int size);
	// Функция для сортировки массива типа char
	void qSortArrVal(char* array, int size, int first_index = 0, int last_index = -2);
#endif

#ifdef DOUBLE
	// Функция для заполнения массива случайными зна­чениями типа double
	void FillArrRandVal(double* array, int size, bool unique, double min, double max, int accuracy = 2);
	// Функция для вывода на консоль значений массива типа double
	void PrintArrVal(double* array, int size);
	// Функция поиска минимального элемента в массиве типа double
	double FindArrMinVal(double* array, int size);
	// Функция поиска максимального элемента в массиве типа double
	double FindArrMaxVal(double* array, int size);
	// Функция для сортировки массива типа double
	void qSortArrVal(double* array, int size, int first_index = 0, int last_index = -2);
#endif