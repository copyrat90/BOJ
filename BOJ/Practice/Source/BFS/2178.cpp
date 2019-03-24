#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second

constexpr int not_visited = -1;
constexpr int not_allowed = -2;

int maze[100][100];
pair<int, int> udlr[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int,int>> q;
    int n, m;
    cin >> n >> m;
    cin.get();  // '\n' 제거

    // 미로 입력
    for (int i = 0; i < n; i++)
    {
        // 방문 안 한 길은 -1, 못 가는 곳은 -2
        for (int j = 0; j < m; j++)
            maze[i][j] = cin.get() - '0' - 2;
        cin.get();  // '\n' 제거
    }

    // BFS
    // [0,0] 방문하고 큐에 넣음
    q.push({0,0});
    maze[0][0] = 1;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        // p 상하좌우 점을 방문
        for (auto dir : udlr)
        {
            const int x = p.X + dir.X;
            const int y = p.Y + dir.Y;
            if (x < 0 || y < 0 || x >= m || y >= n)
                continue;   // 범위를 넘으면 패스
            if (maze[y][x] == not_allowed || maze[y][x] != not_visited)
                continue;   // 못 가는 곳이거나 이미 방문했으면 패스

            // p 점까지의 거리 + 1 == 다음 점까지의 거리
            maze[y][x] = maze[p.Y][p.X] + 1;
            q.push({y, x});
        }
    }

    cout << maze[n-1][m-1];
    return 0;
}