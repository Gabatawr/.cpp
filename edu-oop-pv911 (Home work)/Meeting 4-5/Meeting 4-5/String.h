#pragma once
#include <iostream>

class String
{
private:
	char* line;                                                          // массив символов
	unsigned size;                                                       // размер строки с учетом '\0'

	static int created_now;                                              // сколько создано объектов в данный момент
	static int created_all;                                              // сколько всего объектов было создано
	
public:
	String();                                                            // создание пустой строки (содержит только '\0')
	String(const char*);                                                 // создание по const char* строке
	String(char, unsigned = 1);                                          // создание по символу, можно указать размер, строка будет заполнена этим символом
	String(char*, unsigned = 1);                                         // создание по массиву символов (указание размера обязательно)
	String(int);                                                         // создание по целочисленному числу
	String(double, unsigned = 2);                                        // создание по дробному числу
	String(const String&);                                               // создание по подобному объекту
	
	~String();                                                           // деструктор

	static int get_created_now();                                        // вернуть число созданных объектов в данный момент
	static int get_created_all();                                        // вернуть число всего созданных объектов

	void put(const char&, unsigned, unsigned = 1);                       // внедрить символ начиная с индекса указанное количество раз
	void put(const char*, unsigned);                                     // внедрить const char* строку начиная с индекса
	void put(const String&, unsigned);                                   // внедрить подобную строку начиная с индекса

	void cut(unsigned, unsigned = 1);                                    // вырезать диапазон указанного размера начиная с индекса
	void cut(const char&);                                               // вырезать указанный символ из строки
	
	int len() const;                                                     // размер строки без учета '\0'

	int count_letters() const;                                           // подсчет кол-ва букв
	int count_digits() const;                                            // подсчет кол-ва цифр
	int count_numbers() const;                                           // подсчет целочисленных чисел
	int count_symbol(char) const;                                        // подсчет указанного символа

	int count_word(const char*) const;                                   // подсчет совпадений const char* строки
	int count_word(char*, unsigned) const;                               // подсчет совпадений с массивом символов (указание размера обязательно)
	int count_word(String&) const;                                       // подсчет совпадений с подобной строкой
	
	void replace(String&, String&);                                      // заменить в строке совпадения с подобной строкой 1 на подобную строку 2
	void replace(char&, char&) const;                                    // заменить символ
	
	template <typename T1, typename T2>                                  // шаблонный метод, можно использовать любые комбинации типов (с условием их реализации в конструкторе данного объекта)
	void replace(T1&, T2&);                                              // заменить в строке текст_1 на текст_2

	template <typename T>                                                // шаблонный метод, для использования масива символов с любым типом (с условием их реализации в конструкторе данного объекта)
	void replace(char*, T&, unsigned = 1);                               // заменить в строке совпадение с масивом символов (указание размера обязательно) на Т текст

	template <typename T>                                                // шаблонный метод, для использования масива символов с любым типом (с условием их реализации в конструкторе данного объекта)
	void replace(T&, char*, unsigned = 1);                               // заменить в строке совпадение с Т текстом на масив символов (указание размера обязательно)

	void capital_letters() const;                                        // сделать каждое новое предложение с заглавной буквы
	void uppercase() const;                                              // все буквы в верхний регистр
	void lowercase() const;                                              // все буквы в нижний регистр
	void reverse() const;                                                // реверс строки
	void clear();                                                        // очистить строку (будет содержать только '\0')
	bool empty() const;                                                  // пустая ли строка (true если строка содержит только '\0')
	
	bool has(const char*) const;                                         // есть ли совпадения с const char* строкой
	bool has(char*, unsigned) const;                                     // есть ли совпадения с массивом символов (указание размера обязательно)
	bool has(String&) const;                                             // есть ли совпадения с подобной строкой
	
	int fpos(const char*) const;                                         // вернуть индекс начала первого совпадения с const char* строкой
	int fpos(char*, unsigned) const;                                     // вернуть индекс начала первого совпадения с массивом символов (указание размера обязательно)
	int fpos(String&) const;                                             // вернуть индекс начала первого совпадения с подобной строкой
	
	int lpos(const char*) const;                                         // вернуть индекс начала последнего совпадения с const char* строкой
	int lpos(char*, unsigned) const;                                     // вернуть индекс начала последнего совпадения с массивом символов (указание размера обязательно)
	int lpos(String&) const;                                             // вернуть индекс начала последнего совпадения с подобной строкой
	
	String between(char) const;                                          // вернуть содержимое между указанным символом (между кавычками например)

	int to_int(unsigned = 1) const;                                      // вернуть целочисленное число по указанному номеру его вхождения
	double to_double(unsigned = 1) const;                                // вернуть дробное число по указанному номеру его вхождения
	
	String& operator = (const char*);                                    // очистить строку и присвоить содержимое const char* строки
	String& operator = (const char&);                                    // очистить строку и присвоить содержимое символа
	String& operator = (int);                                            // очистить строку и присвоить содержимое целочисленного числа
	String& operator = (double);                                         // очистить строку и присвоить содержимое дробного числа
	String& operator = (const String&);                                  // очистить строку и присвоить содержимое подобной строки

	String operator + (const char*) const;                               // вернуть новую строку, объединение текущей строки с const char* строкой
	String operator + (char&) const;                                     // вернуть новую строку, объединение текущей строки с символом
	String operator + (int&) const;                                      // вернуть новую строку, объединение текущей строки с целочисленным числом
	String operator + (double&) const;                                   // вернуть новую строку, объединение текущей строки с дробным числом
	String operator + (String&) const;                                   // вернуть новую строку, объединение текущей строки с подобной строкой

	String& operator += (unsigned);                                      // добавить в конец текущей строки указанное кол-во символов '#'
	String& operator += (const char*);                                   // добавить в конец текущей строки const char* строку
	String& operator += (const char&);                                   // добавить в конец текущей строки указыный символ
	String& operator += (const String&);                                 // добавить в конец текущей строки подобную строку

	String& operator -= (unsigned);                                      // вырезать с конца текущей строки указанное кол-во символов
	String& operator -= (const char*);                                   // вырезать из текущей строки все совпадения с const char* строкой
	String& operator -= (const char&);                                   // вырезать указанный символ из строки
	String& operator -= (const String&);                                 // вырезать из текущей строки все совпадения с подобной строкой

	bool operator <  (String&) const;                                    // сравнение по алфавиту с подобной строкой
	bool operator <  (const char*) const;                                // сравнение по алфавиту с const char* строкой
	bool operator >  (String&) const;                                    // сравнение по алфавиту с подобной строкой
	bool operator >  (const char*) const;                                // сравнение по алфавиту с const char* строкой
	bool operator == (String&) const;                                    // сравнение по алфавиту с подобной строкой
	bool operator == (const char*) const;                                // сравнение по алфавиту с const char* строкой
	bool operator != (String&) const;                                    // сравнение по алфавиту с подобной строкой
	bool operator != (const char*) const;                                // сравнение по алфавиту с const char* строкой
	bool operator <= (String&) const;                                    // сравнение по алфавиту с подобной строкой
	bool operator <= (const char*) const;                                // сравнение по алфавиту с const char* строкой
	bool operator >= (String&) const;                                    // сравнение по алфавиту с подобной строкой
	bool operator >= (const char*) const;                                // сравнение по алфавиту с const char* строкой

	friend std::istream& operator >> (std::istream&, String&);           // возможность инициализации строки через поток ввода
	friend std::ostream& operator << (std::ostream&, const String&);     // возможность вывода строки через поток вывода

	char& operator [] (unsigned) const;                                  // вернуть символ по индексу

	operator int() const;                                                // присваивает первое целочисленное число
	operator double() const;                                             // присваивает первое дробное число
	operator const char*() const;                                        // возвращает свою копию в виде const char* строки
	operator char*() const;                                              // возвращает свою копию в виде си строки (требуется удаление после использования)

private:
	int tech_size() const;                                               // техфункция подсчета размера строки
};

template <typename T1, typename T2>
void String::replace(T1& old_word, T2& new_word)
{
	String old_w(old_word);
	String new_w(new_word);
	
	this->replace(old_w, new_w);
}

template <typename T>                                                
void String::replace(char* old_word, T& new_word, unsigned old_word_size)
{
	String old_w(old_word, old_word_size);
	String new_w(new_word);

	this->replace(old_w, new_w);
}

template <typename T>
void String::replace(T& old_word, char* new_word, unsigned new_word_size)
{
	String old_w(old_word);
	String new_w(new_word, new_word_size);

	this->replace(old_w, new_w);
}