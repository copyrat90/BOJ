#include <iostream>
#include <algorithm>

using namespace std;

// 완전 탐색! Brute Force!

char board[50][51];

int main(void)
{
    int min_change = 64;
    int Y, X;
    cin >> Y >> X;
    // 보드판 입력
    for (int i = 0; i < Y; i++)
        cin >> board[i];
    // 자를 보드판 선택
    for (int y = 0; y < Y - 7; y++)
    {
        for (int x = 0; x < X - 7; x++)
        {
            // 바꿔야 할 색깔 계산
            int cur_change = 0;
            char wanted = 'B';
            for (int i = y; i < y + 8; i++)
            {
                for (int j = x; j < x + 8; j++)
                {
                    cur_change += (wanted != board[i][j]);
                    wanted = (wanted == 'B') ? 'W' : 'B';
                }
                wanted = (wanted == 'B') ? 'W' : 'B';
            }
            cur_change = min(cur_change, 64 - cur_change);
            min_change = min(cur_change, min_change);
        }
    }

    cout << min_change;
    return 0;
}