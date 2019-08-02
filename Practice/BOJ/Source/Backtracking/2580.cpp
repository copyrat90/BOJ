#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

char board[9][10];

bool check_used(int y, int x, int num)
{
	// 가로줄 검사
	for (int i = 0; i < 9; ++i)
	{
		if (board[i][x] == num)
			return true;
	}
	// 세로줄 검사
	for (int j = 0; j < 9; ++j)
	{
		if (board[y][j] == num)
			return true;
	}
	// 정사각형 영역 검사
	for (int i = y / 3 * 3; i < y / 3 * 3 + 3; ++i)
	{
		for (int j = x / 3 * 3; j < x / 3 * 3 + 3; ++j)
		{
			if (board[i][j] == num)
				return true;
		}
	}

	return false;
}

bool fill_cell(int y, int x)
{
	if (board[y][x] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			if (check_used(y, x, i))
				continue;

			board[y][x] = i;
			if (y == 8 && x == 8)
				return true;
			if (fill_cell((y + (x + 1) / 9), ((x + 1) % 9)))
				return true;
			board[y][x] = 0;
		}
	}
	else
	{
		if (y == 8 && x == 8)
		{
			return true;
		}
		if (fill_cell((y + (x + 1) / 9), ((x + 1) % 9)))
			return true;
	}
	return false;
}


int main()
{
	// 입력!
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
			board[i][j] -= '0';
		}
	}

	fill_cell(0, 0);

	for (int y = 0; y < 9; ++y)
	{
		for (int x = 0; x < 9; ++x)
		{
			cout << (int)board[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}