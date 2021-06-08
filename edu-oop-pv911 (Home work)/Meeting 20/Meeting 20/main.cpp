
#include "header.h"

int main()
{
#pragma region Presetting

	srand(time(0));
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

#pragma endregion
	
#pragma region Description
	
	/*
	 * Тема:
	 *   Виртуальные функции.
	 *   
	 * Задание.
	 *   Создайте иерархию классов по работе с файлами.
	 *   Базовый класс умеет открывать файл и отображать его содержимое в консоль,
	 *   первый класс потомка открывает файл и отображает содержимое в виде ASCII-кодов символов,
	 *   расположенных в файле, второй класс потомка открывает файл и показывает его содержимое в двоичном виде и т.д.
	 *   
	 *   Для отображения содержимого файла в базовом классе определена виртуальная функция
	 *   • void Display(const char * path);
	 *   • path — путь к файлу.
	 *   
	 *   Потомки создают свою реализацию виртуальной функции.
	 */
	
#pragma endregion
	
	do { system("cls");

		File_BASE* BASE = new File_BASE;
		std::cout << "\n";
		BASE->print("test.txt");
		std::cout << "\n";

		
		File_BASE* ASCII = new File_ASCII;
		std::cout << "\n";
		ASCII->print("test.txt");
		std::cout << "\n";


		File_BASE* BINARY = new File_BINARY;
		std::cout << "\n";
		BINARY->print("test.txt");
		std::cout << "\n";
		
	} while (restart());
}