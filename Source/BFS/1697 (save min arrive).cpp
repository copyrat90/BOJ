#include <bits/stdc++.h>
using namespace std;

// #define DBG

struct Point
{
    int pos;
    int cnt = 0;
};

constexpr int MAX = 100'000;
constexpr int unvisited = -1;

int min_arrive[MAX + 1];

int main(void)
{
    // 방문 안 한 상태(-1)로 초기화
    fill(min_arrive, min_arrive + MAX + 1, unvisited);
#ifdef DBG
    ofstream fs("test.txt");
#endif
    int answer;
    int N, K;
    cin >> N >> K;

    // 시작점 방문 및 큐에 삽입
    queue<Point> q;
    min_arrive[N] = 0;
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
        if (p.pos != 0 && 2 * p.pos <= MAX && min_arrive[2 * p.pos] == unvisited)
        {
            min_arrive[2 * p.pos] = p.cnt + 1;
            q.push({2 * p.pos, p.cnt + 1});
        }
        // 오른쪽으로 한 칸 이동하는 경우
        if (p.pos + 1 <= MAX && min_arrive[p.pos + 1] == unvisited)
        {
            min_arrive[p.pos + 1] = p.cnt + 1;
            q.push({p.pos + 1, p.cnt + 1});
        }
        // 왼쪽으로 한 칸 이동하는 경우
        if (p.pos - 1 >= 0 && min_arrive[p.pos - 1] == unvisited)
        {
            min_arrive[p.pos - 1] = p.cnt + 1;
            q.push({p.pos - 1, p.cnt + 1});
        }
    }
#ifdef DBG
    for (int i = 0; i < MAX + 1; i++)
        fs << i << '\t' << min_arrive[i] << '\n';
#endif
    cout << answer;
    return 0;
}