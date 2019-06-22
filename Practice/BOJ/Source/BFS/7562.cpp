#include <bits/stdc++.h>
using namespace std;

int visit[300][300];
constexpr int unvisited = -1;
struct Point
{
    int x;
    int y;
};
constexpr Point knight_move[8] =
{
    {2,1},{2,-1},{-2,1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int l;
        cin >> l;
        // 보드 초기화
        for (int i = 0; i < l; ++i)
            fill(visit[i], visit[i] + l, unvisited);
        // 나이트 시작, 끝점 입력
        Point start_pos, end_pos;
        cin >> start_pos.x >> start_pos.y;
        cin >> end_pos.x >> end_pos.y;
        // BFS
        queue<Point> q;
        visit[start_pos.y][start_pos.x] = 0;
        q.push({start_pos.x, start_pos.y});
        while (!q.empty())
        {
            Point p = q.front();
            q.pop();
            // 도착점에 도착했으면 break
            if (p.x == end_pos.x && p.y == end_pos.y)
                break;
            for (auto move : knight_move)
            {
                Point cur{p.x+move.x, p.y+move.y};
                if (cur.x < 0 || cur.y < 0 || cur.x >= l || cur.y >= l)
                    continue;
                if (visit[cur.y][cur.x] != unvisited)
                    continue;
                // 현재 방문점에 (지난번 방문 턴수 + 1) 을 대입
                visit[cur.y][cur.x] = visit[p.y][p.x] + 1;
                q.push(cur);
            }
        }

        cout << visit[end_pos.y][end_pos.x] << '\n';
    }

    return 0;
}