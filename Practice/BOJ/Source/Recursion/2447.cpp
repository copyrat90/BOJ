#include <bits/stdc++.h>
using namespace std;

constexpr int N_MAX = 2188;
char board[N_MAX][N_MAX];

void f(int n, int base_y, int base_x)
{
    if (n == 1)
    {
        board[base_y][base_x] = '*';
        return;
    }

    int block = n / 3;
    for (int y = 0; y < 3; ++y)
        for (int x = 0; x < 3; ++x)
            if (y != 1 || x != 1)
                f(block, base_y + y * block, base_x + x * block);
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  cin >> n;
    for (int y = 0; y < n; ++y)
        fill(board[y], board[y] + n, ' ');

    f(n, 0, 0);

    for (int y = 0; y < n; ++y)
        cout << board[y] << '\n';
    return 0;
}