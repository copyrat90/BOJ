#include <bits/stdc++.h>
using namespace std;

enum tomato_stat {nothing=-2, unripe};
// -2 = 토마토 없음, -1 = 안 익음
// 0 이상 = 익음(숫자는 익는데 걸린 일수)
int box[1000][1000];

struct Point
{
    int x;
    int y;
};
Point udlr[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M_x, N_y;
    cin >> M_x >> N_y;
    queue<Point> q;
    
    // 상자에 토마토를 채운다.
    // 익음을 0 이상으로 하기 위해 (입력-1) 을 채움
    for (int i = 0; i < N_y; i++)
        for (int j = 0; j < M_x; j++)
        {
            int temp;
            cin >> temp;
            box[i][j] = temp - 1;
        }

    // 상자 상태 점검
    for (int y = 0; y < N_y; y++)
    {
        for (int x = 0; x < M_x; x++)
        {
            // [x,y]에 토마토가 있으면
            if (box[y][x] != nothing)
            {
                bool isolated = true;
                // 상하좌우 체크 : 고립 여부 판단
                for (auto dr : udlr)
                {
                    int px = x + dr.x;
                    int py = y + dr.y;
                    if (px < 0 || py < 0 || px >= M_x || py >= N_y)
                        continue;
                    if (box[py][px] != nothing)
                    {
                        isolated = false;
                        break;
                    }
                }
                // 안 익었는데 고립된 토마토가 있으면 불가능
                if (box[y][x] == unripe && isolated)
                {
                    cout << -1;
                    return 0;
                }
                // 익었는데 고립되지 않았으면 큐에 넣는다.
                if (box[y][x] >= 0 && !isolated)
                {
                    q.push({x, y});
                }
            }
        }
    }

    // BFS
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();
        // 상하좌우 체크해 토마토를 익게 만든다.
        for (auto dr : udlr)
        {
            int px = p.x + dr.x;
            int py = p.y + dr.y;
            if (px < 0 || py < 0 || px >= M_x || py >= N_y)
                continue;
            if (box[py][px] == unripe)
            {
                // 익는 데 걸린 일수 = 직전 토마토 일수 + 1
                // 0 이상이면 익은 토마토임을 알 수 있다.
                box[py][px] = box[p.y][p.x] + 1;
                q.push({px, py});
            }
        }
    }

    // 가장 익는 데 오래 걸린 일수를 찾아 출력한다.
    int max_day = 0;
    for (int i = 0; i < N_y; i++)
        for (int j = 0; j < M_x; j++)
        {
            if (box[i][j] == nothing)
                continue;
            max_day = max(box[i][j], max_day);
        }
    cout << max_day;
    return 0;
}