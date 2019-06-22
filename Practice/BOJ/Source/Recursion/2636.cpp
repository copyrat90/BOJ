#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

enum board_status {blank = -2, cheese = -1};
int board[100][100];
int visit_turn[100][100];
int board_y, board_x;
pair<int,int> udlr[4] = {{1,0},{0,1},{-1,0},{0,-1}};

void flood_melt(pair<int,int> cur, int turn);
bool cheese_remains();
int last_cheese_cnt(int turn);

int main(void)
{
    cin >> board_y >> board_x;
    for (int y = 0; y < board_y; ++y)
        for (int x = 0; x < board_x; ++x)
        {
            cin >> board[y][x];
            board[y][x] -= 2; // blank = -2, cheese = -1
        }
    
    int turn = 0;
    while (cheese_remains())
        flood_melt({0,0}, ++turn);
    
    cout << turn << '\n' << last_cheese_cnt(turn);
    return 0;
}

int last_cheese_cnt(int turn)
{
    int cnt = 0;
    for (int y = 0; y < board_y; ++y)
        for (int x = 0; x < board_x; ++x)
            if (board[y][x] == turn)
                ++cnt;
    return cnt;
}

bool cheese_remains()
{
    for (int y = 0; y < board_y; ++y)
        for (int x = 0; x < board_x; ++x)
            if (board[y][x] == cheese)
                return true;
    return false;
}

// Recursive DFS (Flood Fill)
void flood_melt(pair<int,int> cur, int turn)
{
    // 상하좌우 확인
    for (auto dir : udlr)
    {
        int y = cur.Y + dir.Y;
        int x = cur.X + dir.X;
        // 범위 벗어나면 pass
        if (y < 0 || x < 0 || y >= board_y || x >= board_x)
            continue;
        // 이번 턴에 이미 방문했으면 pass
        if (visit_turn[y][x] == turn)
            continue;
        // 치즈면 방문처리 후 녹인다.
        if (board[y][x] == cheese)
        {
            visit_turn[y][x] = turn;
            board[y][x] = turn;
        }
        // 공기중이면 재귀호출 (방문처리 후 스택에 넣음)
        // 전 턴에 치즈가 녹은 곳도 공기중이니 포함한다.
        else
        {
            visit_turn[y][x] = turn;
            flood_melt({y,x}, turn);
        }
    }
}