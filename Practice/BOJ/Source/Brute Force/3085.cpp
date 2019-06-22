#include <bits/stdc++.h>
using namespace std;

char board[50][51];
int N;

inline int this_board_max();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];

    int max = 0;

    // 가로 인접 사탕 swap 후 최대 사탕 함수 호출
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            swap(board[i][j], board[i][j+1]);
            int cur_max = this_board_max();
            max = (cur_max > max) ? cur_max : max;
            swap(board[i][j], board[i][j+1]);
        }
    }

    // 세로 인접 사탕 swap 후 최대 사탕 함수 호출
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            swap(board[i][j], board[i+1][j]);
            int cur_max = this_board_max();
            max = (cur_max > max) ? cur_max : max;
            swap(board[i][j], board[i+1][j]);
        }
    }

    cout << max;
    return 0;
}


// 특정 보드 상태일 때 최대 사탕 구하는 함수
inline int this_board_max()
{
    int max = 0;

    // 가로줄 최대 연속 사탕 찾기
    for (int i = 0; i < N; i++)
    {
        char color = board[i][0];
        int cur_max = 1;
        for (int j = 1; j < N; j++)
        {
            if (board[i][j] == color)
                cur_max++;
            else
            {
                color = board[i][j];
                max = (cur_max > max) ? cur_max : max;
                cur_max = 1;
            }
        }
        max = (cur_max > max) ? cur_max : max;
    }

    // 세로줄 최대 연속 사탕 찾기
    for (int j = 0; j < N; j++)
    {
        char color = board[0][j];
        int cur_max = 1;
        for (int i = 1; i < N; i++)
        {
            if (board[i][j] == color)
                cur_max++;
            else
            {
                color = board[i][j];
                max = (cur_max > max) ? cur_max : max;
                cur_max = 1;
            }
        }
        max = (cur_max > max) ? cur_max : max;
    }
    return max;
}

