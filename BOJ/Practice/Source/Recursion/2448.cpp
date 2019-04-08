#include <bits/stdc++.h>
using namespace std;

char board[3 * (1 << 10)][6 * (1 << 10)];

void f(int n, int base_y, int base_x)
{
    if (n == 3)
    {
        board[base_y - 2][base_x + 2] = '*';
        board[base_y - 1][base_x + 1] = '*';
        board[base_y - 1][base_x + 3] = '*';
        for (int x = 0; x < 5; ++x)
            board[base_y][base_x + x] = '*';
        return;
    }

    int part_y = n / 2;
    int part_x = n;
    f(n / 2, base_y, base_x);
    f(n / 2, base_y - part_y, base_x + part_x / 2);
    f(n / 2, base_y, base_x + part_x);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  cin >> n;
    for (int y = 0; y < n; ++y)
        fill(board[y], board[y] + 2 * n - 1, ' ');
    
    f(n, n-1, 0);

    for (int y = 0; y < n; ++y)
        cout << board[y] << '\n';
    return 0;
}