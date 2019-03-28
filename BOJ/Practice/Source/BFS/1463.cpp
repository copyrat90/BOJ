#include <bits/stdc++.h>
using namespace std;

#define num first
#define turn second

constexpr int unvisited = 0;
// 인덱스 0은 사용하지 않음
int visit[1'000'001];

int main(void)
{
    int n;  cin >> n;
    // 현재 숫자, 오는데 걸린 횟수
    queue<pair<int,int>> q;
    // visit[n] = 0; // 있으나마나
    q.push({n, 0});
    // BFS
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur.num <= 1)
            break;
        if (cur.num % 3 == 0 && visit[cur.num / 3] == unvisited)
        {
            visit[cur.num / 3] = cur.turn + 1;
            q.push({cur.num / 3, cur.turn + 1});
        }
        if (cur.num % 2 == 0 && visit[cur.num / 2] == unvisited)
        {
            visit[cur.num / 2] = cur.turn + 1;
            q.push({cur.num / 2, cur.turn + 1});
        }
        if (visit[cur.num - 1] == unvisited)
        {
            visit[cur.num - 1] = cur.turn + 1;
            q.push({cur.num - 1, cur.turn + 1});
        }
    }
    cout << visit[1];
    return 0;
}