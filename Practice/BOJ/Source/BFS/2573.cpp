#include <bits/stdc++.h>
using namespace std;

int N_y, M_x;
bool visit[301][301];
int board[301][301];
int udlr_y[4] = {0,0,1,-1};
int udlr_x[4] = {1,-1,0,0};


void bfs(int y, int x)
{    
    queue<pair<int, int>> q;
    visit[y][x] = true;
    q.push({y, x});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            const int candi_y = udlr_y[i] + p.first;
            const int candi_x = udlr_x[i] + p.second;
            // visit 을 먼저 체크해 방문했으면 continue
            if (visit[candi_y][candi_x])
                continue;
            // 0(바다)를 visit 보다 나중에 체크해 이번 해에 바다가 된 지점을 원래 바다였던     것으로 혼동하는 문제를 방지
            if (board[candi_y][candi_x] == 0)
            {
                // 인접한 바다 개수만큼 p 지점 빙하를 녹임
                --board[p.first][p.second];
                continue;
            }
            // 방문 후 큐에 넣음
            visit[candi_y][candi_x] = true;
            q.push({candi_y, candi_x});
        }
        // 음수가 되도록 녹였으면 0 으로 되돌려 준다.
        if (board[p.first][p.second] < 0)
            board[p.first][p.second] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int turn;
    cin >> N_y >> M_x;

    for (int y = 0; y < N_y; ++y)
        for (int x = 0; x < M_x; ++x)
            cin >> board[y][x];

    for (int turn = 0; ; ++turn)
    {
        // 방문 배열 초기화
        for (int r = 0; r < N_y; ++r)
            fill(visit[r], visit[r] + M_x, false);
        // 연결된 빙하 덩어리의 개수
        int connected = 0;
        for (int y = 1; y < N_y - 1; ++y)
        {
            for (int x = 1; x < M_x - 1; ++x)
            {
                if (board[y][x] == 0)
                    continue;
                if (visit[y][x])
                    continue;

                if (connected >= 1)
                {
                    cout << turn;
                    return 0;
                }
                else
                {
                    ++connected;
                    bfs(y, x);
                }
            }
        }
        // 빙하가 분리되지 않은 채로 다 녹았으면
        if (connected == 0)
        {
            cout << 0;
            return 0;
        }
    }
    
}