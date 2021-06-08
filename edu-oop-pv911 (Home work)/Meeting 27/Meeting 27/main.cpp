#include "header.h"

#pragma region Description

	/**
	 * Тема:
	 *   Умные указатели.
	 *
	 * Задание.
	 *   Создайте пользовательские классы умных указателей.
	 *   Один из классов должен повторять функциональность
	 *   стандартного класса unique_ptr, а другой shared_ptr.
	 *   
	 *   Напишите код по тестированию ваших классов.
	 */

#pragma endregion

int main()
{
	uptr<int> p1(new int(10));       // int*
	uptr<int> p2;                    // nullptr

	//p2 = p1;                       // error
	//p2(p1);                        // error

	p1.get();                        // int*

	p1.swap(p2);                     // p1 = nullptr; p2 = int*;

	uptr<int>p3(p2.release());       // p2 = nullptr; p3 = int*;

	p3.reset();                      // p3 = nullptr; memory leak;

	//============================================================//

	sptr<int> s1;                    // s1 = nullptr;
	sptr<int> s2(new int(10));       // s2 #1

	sptr<int> s3(s2);                // s2, s3 #2
	sptr<int> s4(s3);                // s2, s3, s4 #3;
	s3.release();                    // s2, s4 #2; s3 = nullptr;
	{
		sptr<int> s5 = s2;           // s2, s4, s5 #3
		s4 = s5;                     // s2, s4, s5 #3
	}

	s4.swap(s1);                     // s1, s2 #2; s4 = nullptr;

	s1.reset();                      // s1 = nullptr
	
	delete s2.release();             // ok, no memory leak
}