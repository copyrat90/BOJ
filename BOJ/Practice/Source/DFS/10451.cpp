#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int N;
int next_idx[1001];
bool visit[1001];

void dfs(int cur_idx)
{
    if (visit[cur_idx])
        return;
    visit[cur_idx] = true;
    dfs(next_idx[cur_idx]);
}

int main(void)
{
    FAST_IO;
    
    int T;
    cin >> T;
    while (T--)
    {
        fill(visit, visit + 1001, false);
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> next_idx[i];
            --next_idx[i];  // 0-based idx
        }
        // 매 정점(vertex)마다 dfs 돌려
        // 새 사이클을 찾을 때마다 ++cnt
        int cycle_cnt = 0;
        for (int i = 0; i < N; ++i)
            if (!visit[i])
            {
                ++cycle_cnt;
                visit[i] = true;
                dfs(next_idx[i]);
            }
        cout << cycle_cnt << '\n';
    }
    return 0;
}