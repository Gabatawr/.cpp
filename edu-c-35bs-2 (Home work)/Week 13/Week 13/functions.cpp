#include "my-lib_of_week-13.h"


//---------------------------------------------------------------------------------------------------------------------------//

void print_XOBoard(int(&board)[3][3])
{
	int digit_size = 2;

	cout << "\n " << setfill('-') << setw((3 + digit_size) * 3 + 1) << "" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 11) cout << " | " << setfill(' ') << setw(digit_size) << "X";
			else if (board[i][j] == 10) cout << " | " << setfill(' ') << setw(digit_size) << "O";
			else cout << " | " << setfill(' ') << setw(digit_size) << board[i][j];
			if (j == 3 - 1) cout << " |";
		}
		cout << "\n " << setfill('-') << setw((3 + digit_size) * 3 + 1) << "" << endl;
	}
}

void XOGame(int(&board)[3][3], int& num, int& count, bool& end_game)
{
	if (end_game) return;
	
	int pos_x = 0, pos_y = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == num) {
				pos_y = i;
				pos_x = j;
			}
		}
	}
	if (board[pos_y][pos_x] != 11 && board[pos_y][pos_x] != 10)
	{
		if (count % 2 == 0) board[pos_y][pos_x] = 11;
		else board[pos_y][pos_x] = 10;
	}
	
	system("cls");
	print_XOBoard(board);
	
	if (   (board[0][0] == 10 && board[0][1] == 10 && board[0][2] == 10) // ---
		|| (board[1][0] == 10 && board[1][1] == 10 && board[1][2] == 10) 
		|| (board[2][0] == 10 && board[2][1] == 10 && board[2][2] == 10)

		|| (board[0][0] == 10 && board[1][0] == 10 && board[2][0] == 10) // |
		|| (board[0][1] == 10 && board[1][1] == 10 && board[2][1] == 10)
		|| (board[0][2] == 10 && board[1][2] == 10 && board[2][2] == 10)

		|| (board[0][0] == 10 && board[1][1] == 10 && board[2][2] == 10) // X
		|| (board[2][0] == 10 && board[1][1] == 10 && board[0][2] == 10))
	{
		cout << "\n Win !!_O_!!\n";
		end_game = true;
		return;
	}

	if (   (board[0][0] == 11 && board[0][1] == 11 && board[0][2] == 11) // ---
		|| (board[1][0] == 11 && board[1][1] == 11 && board[1][2] == 11)
		|| (board[2][0] == 11 && board[2][1] == 11 && board[2][2] == 11)

		|| (board[0][0] == 11 && board[1][0] == 11 && board[2][0] == 11) // |
		|| (board[0][1] == 11 && board[1][1] == 11 && board[2][1] == 11)
		|| (board[0][2] == 11 && board[1][2] == 11 && board[2][2] == 11)

		|| (board[0][0] == 11 && board[1][1] == 11 && board[2][2] == 11) // X
		|| (board[2][0] == 11 && board[1][1] == 11 && board[0][2] == 11))
	{
		cout << "\n Win !!_X_!!\n";
		end_game = true;
		return;
	}

	for (int i = 0, c = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 11 || board[i][j] == 10) c++;
			if (c == 9)
			{
				cout << "\n !!_Draw_!!\n";
				end_game = true;
				return;
			}
		}
	}

	
	if (count % 2 == 0) cout << "\n O: ";
	else cout << "\n X: ";
	cin >> num;
	XOGame(board, num, ++count, end_game);
}

void start_XO_Game()
{
	int board[3][3];
	for (int i = 0, k = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++, k++) {
			board[i][j] = k;
		}
	}
	print_XOBoard(board);
	
	cout << " Enter cell number for X: ";
	int num, count = 0;
	cin >> num;
	
	bool end_game = false;
	XOGame(board, num, count, end_game);
}

//---------------------------------------------------------------------------------------------------------------------------//

void print_pBoard(int(&board)[4][4])
{
	int digit_size = 2;

	cout << "\n " << setfill('-') << setw((3 + digit_size) * 4 + 1) << "" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0) cout << " | " << setfill(' ') << setw(digit_size) << "";
			else cout << " | " << setfill(' ') << setw(digit_size) << board[i][j];
			if (j == 4 - 1) cout << " |";
		}
		cout << "\n " << setfill('-') << setw((3 + digit_size) * 4 + 1) << "" << endl;
	}
}
 
void pGame(int(&board)[4][4], int& num, int& all_in_place)
{
	if (all_in_place == 16) return;
	all_in_place = 0;
	
	for (int i = 0, count = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++, count++) {
			if (board[i][j] == count) all_in_place++;
			if (all_in_place == 16) return;
		}
	}
	
	int pos_x = 0, pos_y = 0, pos_Zx = 0, pos_Zy = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				pos_Zy = i;
				pos_Zx = j;
			}
			if (board[i][j] == num) {
				pos_y = i;
				pos_x = j;
			}
		}
	}

	if (((pos_x + 1 == pos_Zx || pos_x - 1 == pos_Zx) && pos_y == pos_Zy) || ((pos_y + 1 == pos_Zy || pos_y - 1 == pos_Zy) && pos_x == pos_Zx))
	{
		swap(board[pos_y][pos_x], board[pos_Zy][pos_Zx]);
	}
	
	system("cls");
	print_pBoard(board);
	cout << "\n Enter: ";
	cin >> num;
	pGame(board, num, all_in_place);
}

void start_pGame()
{
	int board[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			bool is_flag = false;
			board[i][j] = rand() % 16;
			for (int k = 0; k <= i; k++)
			{
				if (is_flag) break;
				for (int p = 0; p < 4; p++)
				{
					if (k == i && p == j)
					{
						is_flag = true;
						break;
					}
					if (board[i][j] == board[k][p])
					{
						j--;
						is_flag = true;
						break;
					}
				}
			}
		}
	}
	print_pBoard(board);
	
	cout << " Enter the number to shift: ";
	int num, all_in_place = 0;
	cin >> num;
	
	pGame(board,num, all_in_place);
	cout << "\n You WIN!!!";
}

//---------------------------------------------------------------------------------------------------------------------------//

int const size_board = 8;

void print_matrix(int (&board)[size_board][size_board])
{
	// cell width calculation
	int digit_size = 1;
	int tmp = size_board * size_board;
	do {
		tmp /= 10;
		digit_size++;
	} while (tmp > 10);

	cout << "\n " << setfill('-') << setw((3 + digit_size) * size_board + 1) << "" << endl; // header row line ---
	for (int i = 0; i < size_board; i++)
	{
		for (int j = 0; j < size_board; j++)
		{
			cout << " | " << setfill(' ') << setw(digit_size) << board[i][j]; // output number
			if (j == size_board - 1) cout << " |";
		}
		cout << "\n " << setfill('-') << setw((3 + digit_size) * size_board + 1) << "" << endl; // line ---
	}
}

void horse_journey(int(&board)[size_board][size_board], int pos_y, int pos_x, int* x, int* y, int &cells)
{
	if (cells != 0 && board[pos_y][pos_x] != 0) return;
	if (pos_y < 0 || pos_x < 0 || pos_y > size_board - 1 || pos_x > size_board - 1) return;

	if (cells == size_board * size_board) return;
	board[pos_y][pos_x] = ++cells;
	
	for (int f = 0, l = size_board - 1; f < size_board / 2; f++, l--)
	{
		
		for (int i = 0; i < 8; i++)
			if (pos_y + y[i] == f && pos_x + x[i] == f)
				horse_journey(board, pos_y + y[i], pos_x + x[i], y, x, cells);
		for (int i = 0; i < 8; i++)
			if (pos_y + y[i] == l && pos_x + x[i] == f)
				horse_journey(board, pos_y + y[i], pos_x + x[i], y, x, cells);
		for (int i = 0; i < 8; i++)
			if (pos_y + y[i] == l && pos_x + x[i] == l)
				horse_journey(board, pos_y + y[i], pos_x + x[i], y, x, cells);
		for (int i = 0; i < 8; i++)
			if (pos_y + y[i] == f && pos_x + x[i] == l)
				horse_journey(board, pos_y + y[i], pos_x + x[i], y, x, cells);
		
		for (int i = 0; i < 8; i++)		
			if (pos_y + y[i] == f || pos_y + y[i] == l || pos_x + x[i] == f || pos_x + x[i] == l)	
				horse_journey(board, pos_y + y[i], pos_x + x[i], y, x, cells);
	}
	horse_journey(board, pos_y + y[rand() % 8], pos_x + x[rand() % 8], y, x, cells);
	
	if (cells == size_board * size_board) return;
	board[pos_y][pos_x] = 0;
	cells--;
}

void start_horse_journey(int pos_y, int pos_x)
{
	int cells = 0;
	
	int board[size_board][size_board]{{}};

	int y[8]{ -2, -2, -1, -1,  1,  1,  2,  2 };
	int x[8]{ -1,  1, -2,  2, -2,  2, -1,  1 };

	horse_journey(board, pos_y, pos_x, x, y, cells);
	
	print_matrix(board);
}

//---------------------------------------------------------------------------------------------------------------------------//


// question about restarting the task
bool restart_task()
{
	cout << endl << " Restart task? (0 / 1)" << endl << " Enter: _\b";
	char u_enter;
	cin >> u_enter;
	
	if (u_enter == '1') return true;
	if (u_enter == '0') return false;
	
	cout << " Invalid command.." << endl;
	return restart_task();
}
