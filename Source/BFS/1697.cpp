#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int pos;
    int cnt = 0;
};

constexpr int MAX = 100'000;
bool visited[MAX + 1];

int main(void)
{
    int answer;
    int N, K;
    cin >> N >> K;

    // 시작점 방문 및 큐에 삽입
    queue<Point> q;
    visited[N] = true;
    q.push({N, 0});
    // BFS
    while (true)
    {
        Point p = q.front();
        q.pop();
        // K에 도착하면 그 때의 cnt가 최소단계이므로 정답이다.
        // BFS이므로 c단계가 전부 실행된 후 (c+1)단계가 실행된다.
        if (p.pos == K)
        {
            answer = p.cnt;
            break;
        }
        // 순간이동 하는 경우
        if (p.pos != 0 && 2 * p.pos <= MAX && !visited[2 * p.pos])
        {
            visited[2 * p.pos] = true;
            q.push({2 * p.pos, p.cnt + 1});
        }
        // 오른쪽으로 한 칸 이동하는 경우
        if (p.pos + 1 <= MAX && !visited[p.pos + 1])
        {
            visited[p.pos + 1] = true;
            q.push({p.pos + 1, p.cnt + 1});
        }
        // 왼쪽으로 한 칸 이동하는 경우
        if (p.pos - 1 >= 0 && !visited[p.pos - 1])
        {
            visited[p.pos - 1] = true;
            q.push({p.pos - 1, p.cnt + 1});
        }
    }

    cout << answer;
    return 0;
}