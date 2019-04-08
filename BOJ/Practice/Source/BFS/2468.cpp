#include <bits/stdc++.h>
using namespace std;

int height[101][101];
int n;
int udlr_y[4] {1,-1,0,0};
int udlr_x[4] {0,0,1,-1};

// 특정 높이의 홍수에 대해
// 안전한 영역의 개수 계산
int flood_fill(int flood_height)
{
    bool visit[101][101] = {false,};
    queue<pair<int,int>> q;
    int cnt = 0;
    // 매 지점마다 bfs 로 Flood Fill 시도
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
        {
            if (visit[y][x])
                continue;
            if (height[y][x] <= flood_height)
                continue;
            // 새로운 안전 영역 발견!
            ++cnt;
            visit[y][x] = true;
            q.push({y, x});
            // 연결된 안전 영역 Flood Fill
            while (!q.empty())
            {
                int cur_y, cur_x;
                tie(cur_y, cur_x) = q.front();
                q.pop();
                // 상하좌우
                for (int i = 0; i < 4; ++i)
                {
                    int candi_y = cur_y + udlr_y[i];
                    int candi_x = cur_x + udlr_x[i];
                    if (candi_y < 0  || candi_x < 0 ||
                        candi_y >= n || candi_x >= n )
                        continue;
                    if (visit[candi_y][candi_x])
                        continue;
                    if (height[candi_y][candi_x] <= flood_height)
                        continue;
                    
                    visit[candi_y][candi_x] = true;
                    q.push({candi_y, candi_x});
                }
            }
        }

    return cnt;
}

// 0~100 높이의 홍수에 대해
// 안전한 영역의 최대 개수 계산
int calc_max()
{
    int max_cnt = -1;
    for (int i = 0; i <= 100; ++i)
        max_cnt = max(max_cnt, flood_fill(i));
    return max_cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
            cin >> height[y][x];
    cout << calc_max();
    return 0;
}