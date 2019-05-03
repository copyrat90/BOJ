#include <bits/stdc++.h>
using namespace std;

constexpr int dy[4] = {1, -1, 0, 0};
constexpr int dx[4] = {0, 0, 1, -1};
int N;
int region_height[100][100];
bool visit[100][100];

void flood_fill(int y, int x, int flood_height)
{
    for (int i = 0; i < 4; ++i)
    {
        const int candi_y = y + dy[i];
        const int candi_x = x + dx[i];
        if (candi_y < 0 || candi_x < 0 || candi_y >= N || candi_x >= N)
            continue;
        if (visit[candi_y][candi_x])
            continue;
        if (region_height[candi_y][candi_x] <= flood_height)
            continue;
        visit[candi_y][candi_x] = true;
        flood_fill(candi_y, candi_x, flood_height);
    }
}

int main(void)
{
    int max_height = 0;
    cin >> N;
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < N; ++x)
        {
            cin >> region_height[y][x];
            max_height = max(max_height, region_height[y][x]);
        }

    int max_safe_cnt = 0;
    // 장마 수위 : 0 ~ max_height - 1 (max_height 로 오면 어차피 0개)
    for (int flood_height = 0; flood_height < max_height; ++flood_height)
    {
        for (int y = 0; y < N; ++y)
            fill(visit[y], visit[y] + N, false);
        int cur_safe_cnt = 0;
        // 방문하지 않은 매 안전 영역마다 새로운 dfs 시작
        for (int y = 0; y < N; ++y)
            for (int x = 0; x < N; ++x)
                if (!visit[y][x] && region_height[y][x] > flood_height)
                {
                    ++cur_safe_cnt;
                    flood_fill(y, x, flood_height);
                }
        max_safe_cnt = max(max_safe_cnt, cur_safe_cnt);
    }
    cout << max_safe_cnt;
    return 0;
}