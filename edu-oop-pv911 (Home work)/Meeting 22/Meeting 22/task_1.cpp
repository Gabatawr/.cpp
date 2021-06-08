#include "header.h"
#include "../../lib/DList.h"

#pragma region Description

	/**
	 * Задание 1.
	 *   Добавьте в класс двусвязного списка механизм обработки исключений.
	 *   На ваш выбор генерируйте исключения в случае ошибок.
	 *   Например, нехватка памяти, попытка удаления из пустого списка и т.д.
	 */

#pragma endregion

class Test_1
{
public:
    Test_1() = default;
    ~Test_1() = default;

    Test_1(const Test_1&) { throw 1; }
};

class Test_2
{
public:
    Test_2() = default;
    ~Test_2() = default;
};

void task_1()
{
    do { system("cls");

		Test_1 a;
		DList<Test_1> list_1(a); // ..lib/DList.h line  33 -> 14
        list_1.push_head(a);     // ..lib/DList.h line 107 -> 14
        list_1.push_pos(a,0);    // ..lib/DList.h line 125 -> 14
        list_1.push_tail(a);     // ..lib/DList.h line 148 -> 14

        Test_2 b;
        DList<Test_2> list_2;    // ok
        list_2[0];               // ..lib/DList.h line 271 -> 392
        list_2.push_head(b);     // ok
        list_2[-1];              // ..lib/DList.h line 271 -> 393
        list_2[2];               // ..lib/DList.h line 271 -> 394
    	
    } while (restart());
}