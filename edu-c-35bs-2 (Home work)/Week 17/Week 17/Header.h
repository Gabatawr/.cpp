#pragma once

#pragma region Declaration
/**
 * Week 17
 *
 * Theme:
 *   Многомерные динамические массивы.
 *
 * @author Artem Kashyrin
 *
*/
#pragma endregion

#pragma region Files specification
/**
* Header.h         - Specification / Inclusion of libraries.
* Main.cpp         - Program menu.
* 
* Task_#.cpp       - Implementation of the function tasks.
* 
* Prototypes.h     - Prototypes of used functions.
* Functions.cpp    - Implementation of technical functions
* 
* Array_libMY.h    - Implementation of template functions from the library for working with arrays.
*
* Matrix_libMY.h   - Implementation of template functions from the library for working with matrix.
* 
* String_libMY.h   - Prototypes of functions from the library for working with string.
* String_libMY.cpp - Implementation of functions from the library for working with string.
*
*/
#pragma endregion

#ifndef Shield
#define Shield

#include <iostream>     // cout, cin, srand(), rand()
#include <windows.h>    // SetConsoleCP(), SetConsoleOutputCP()
#include <ctime>        // time()

using std::cout;
using std::cin;

#include "Prototypes.h"
#include "Array_libMY.h"
#include "Matrix_libMY.h"
#include "String_libMY.h"

#pragma execution_character_set( "utf-8" )

#endif //Shield