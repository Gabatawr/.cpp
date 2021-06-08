#pragma once

template <typename DataType>
void mtx_create(DataType**& mtx, const int row, const int col)
{
	mtx = new DataType* [row];
	for (auto i = 0; i < row; i++) mtx[i] = new DataType[col]{};
}

template <typename DataType>
void mtx_echo(DataType** mtx, const int row, const int col)
{
	for (auto y = 0; y < row; y++)
	{
		for (auto x = 0; x < col; x++)
		{
			cout << "\t" << mtx[y][x];
		}
		cout << "\n";
	}
}

template <typename DataType>
void mtx_rand(DataType** mtx, const int row, const int col, bool is_unique = false, DataType min = 0, DataType max = 100, int accuracy = 2)
{
	for (auto y = 0; y < row; y++)
	{
		for (auto x = 0; x < col; x++)
		{
			mtx[y][x] = DataType(int(rand() % int(max - min)) + min);

			// if double
			if (typeid(DataType) == typeid(double)) mtx[y][x] += double(rand() % int(pow(10, accuracy))) / int(pow(10, accuracy));
			
			// if unique
			if (is_unique)
			{
				if (y == 0 && x == 0) continue;
				bool trigger = false;
				for (auto yu = 0; yu <= y; yu++)
				{
					for (auto xu = 0; xu < col; xu++)
					{
						if (trigger || (yu == y && xu == x)) break;
						if (mtx[y][x] == mtx[yu][xu]) trigger = true;
					}
					if (trigger) { x--; break; }
				}
			}
		}
	}
}

template <typename DataType>
void mtx_add_col(DataType**& mtx, const int row, int& col, int index = 0)
{
	DataType** mtx_old = mtx;
	mtx = new DataType* [row]; col++;
	for (auto i = 0; i < row; i ++) mtx[i] = new DataType[col];

	for (auto y = 0; y < row; y++)
	{
		for (auto x = 0; x < col; x++)
		{
			if (x < index) mtx[y][x] = mtx_old[y][x];
			if (x == index) mtx[y][x] = 0;
			if (x > index) mtx[y][x] = mtx_old[y][x - 1];
		}
	}
	
	for (auto i = 0; i < row; i++) delete[] mtx_old[i];
	delete[] mtx_old;
}

template <typename DataType>
void mtx_del_col(DataType**& mtx, const int row, int& col, int index = 0)
{
	DataType** mtx_old = mtx;
	mtx = new DataType * [row]; col--;
	for (auto i = 0; i < row; i++) mtx[i] = new DataType[col];

	for (auto y = 0; y < row; y++)
	{
		for (auto x = 0; x < col; x++)
		{
			if (x < index) mtx[y][x] = mtx_old[y][x];
			else mtx[y][x] = mtx_old[y][x + 1];
		}
	}

	for (auto i = 0; i < row; i++) delete[] mtx_old[i];
	delete[] mtx_old;
}

template <typename DataType>
void mtx_shift(DataType**& mtx, const int row, const int col, char way = 'r', int count = 1)
{
	if (count < 0) return;
	
	if ((way == 'r' || way == 'l') && (count == col || count == 0)) return;
	if ((way == 't' || way == 'b') && (count == row || count == 0)) return;
	
	if ((way == 'r' || way == 'l') && count > col) count -= col;
	if ((way == 't' || way == 'b') && count > row) count -= row;

	switch (way) {

	case 'l':
		for (auto c = 0; c < count; c++) {
			for (auto y = 0; y < row; y++) {
				DataType temp = mtx[y][0];
				for (int x = 0; x < col - 1; x++) {
					mtx[y][x] = mtx[y][x + 1];
				}
				mtx[y][col - 1] = temp;
			}
		}
		break;
		
	case 'r':
		for (auto c = 0; c < count; c++) {
			for (auto y = 0; y < row; y++) {
				DataType temp = mtx[y][col - 1];
				for (int x = col - 1; x >= 0; x--) {
					mtx[y][x] = mtx[y][x - 1];
				}
				mtx[y][0] = temp;
			}
		}
		break;

	case 't':
		for (int c = 0; c < count; c++) {
			for (int x = 0; x < col; x++) {
				DataType temp = mtx[0][x];
				for (int y = 0; y < row - 1; y++) {
					mtx[y][x] = mtx[y + 1][x];
				}
				mtx[row - 1][x] = temp;
			}
		}
		break;
	
	case 'b':
		for (int c = 0; c < count; c++) {
			for (int x = 0; x < col; x++) {
				DataType temp = mtx[row - 1][x];
				for (int y = row - 1; y > 0; y--) {
					mtx[y][x] = mtx[y - 1][x];
				}
				mtx[0][x] = temp;
			}
		}
		break;

	default:
		break;
	}

}

template <typename DataType>
void mtx_transpose(DataType**& mtx, int &row, int &col)
{
	int tmp = row; row = col; col = tmp;
	DataType** mtx_old = mtx; mtx = new DataType * [row];
	for (auto i = 0; i < row; i++) mtx[i] = new DataType[col];

	for (auto y = 0; y < row; y++)
	{
		for (auto x = 0; x < col; x++)
		{
			mtx[y][x] = mtx_old[x][y];
		}
	}
	
	for (auto i = 0; i < col; i++) delete[] mtx_old[i];
	delete[] mtx_old;
}
