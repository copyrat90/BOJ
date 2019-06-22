#include <bits/stdc++.h>
using namespace std;

bool found;
int cnt;
int udlr_y[4] = { 0, 0, 1, 1 };
int udlr_x[4] = { 0, 1, 0, 1 };
int r, c;

void Z(int n, int y, int x)
{
	if (n == 1)
	{
		for (int i = 0; i < 4; ++i)
		{
			++cnt;
			const int cur_y = y + udlr_y[i];
			const int cur_x = x + udlr_x[i];
			if (cur_y == r && cur_x == c)
			{
				found = true;
				return;
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			Z(n - 1, y + (1 << n - 1) * udlr_y[i], x + (1 << n - 1) * udlr_x[i]);
			if (found)
				return;
		}
	}
}

int main(void)
{
	int n;
	cnt = -1;
	cin >> n >> r >> c;
	Z(n, 0, 0);
	cout << cnt;
	return 0;
}