#include "header.h"

using namespace std;

inline void gotoXY(const int x, const int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
#pragma region Presetting

	srand(time(0));
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

#pragma endregion
	
	do { system("cls");
		
		
		
	} while (restart());
}