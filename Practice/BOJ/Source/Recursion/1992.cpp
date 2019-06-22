#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_LEN = 64;
char board[MAX_LEN][MAX_LEN + 1];

void quad(int length, int base_y, int base_x)
{
    // 길이가 1이면 해당 비트 출력 후 return
    if (length == 1)
    {
        cout << board[base_y][base_x];
        return;
    }
    // 전체가 동일 비트면 그 비트 출력 후 return
    bool is_same = true;
    char same_char = board[base_y][base_x];
    for (int y = base_y; y < base_y + length; ++y)
        for (int x = base_x; x < base_x + length; ++x)
            if (same_char != board[y][x])
            {
                is_same = false;
                goto LOOP_EXIT;
            }
LOOP_EXIT:
    if (is_same)
    {
        cout << same_char;
        return;
    }
    // 아니면 4 영역을 나눠서 재귀호출
    cout << '(';
    quad(length / 2, base_y, base_x);
    quad(length / 2, base_y, base_x + length / 2);
    quad(length / 2, base_y + length / 2, base_x);
    quad(length / 2, base_y + length / 2, base_x + length / 2);
    cout << ')';
}

int main(void)
{
    int n;  cin >> n;
    for (int y = 0; y < n; ++y)
        cin >> board[y];

    quad(n, 0, 0);
    return 0;
}