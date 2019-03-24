#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct __POINT
{
    int x;
    int y;
    const __POINT operator + (const __POINT & other) const
    {
        return {x + other.x, y + other.y};
    }
} POINT;

// 상하좌우를 의미하는 POINT 배열
constexpr POINT udlr[4] = {{1,0},{0,1},{-1,0},{0,-1}};
// 방문을 의미하는 값
constexpr int visit = 9;

int sketchbook[500][500];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    int max_size = 0;

    int n, m;
    cin >> n >> m;

    // 그림 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> sketchbook[i][j];

    // BFS
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            queue<POINT> q;
            // [i,j]가 그림인데 아직 방문한 적이 없으면
            if (sketchbook[i][j] == 1)
            {
                cnt++;  // 새로운 그림이므로 카운트
                int drawing_size = 1;
                // [i,j]를 큐에 넣고 방문처리
                q.push({i, j});
                sketchbook[i][j] = visit;
                // Flood Fill
                while (!q.empty())
                {
                    POINT p = q.front();
                    q.pop();
                    // 지점 p 의 상하좌우를 방문하고 큐에 넣음
                    for (const POINT & direction : udlr)
                    {
                        const POINT && cur = p + direction;
                        // 도화지를 벗어나면 패스
                        if (cur.x < 0 || cur.y < 0 || cur.x >= n || cur.y >= m)
                            continue;
                        // 이미 방문했거나 그림이 아니면 패스
                        if (sketchbook[cur.x][cur.y] == visit || sketchbook[cur.x][cur.y] == 0)
                            continue;
                        // 방문 안 한 그림이면 방문하고 큐에 넣음
                        drawing_size++;
                        sketchbook[cur.x][cur.y] = visit;
                        q.push({cur.x, cur.y});
                    }
                }

                max_size = (drawing_size > max_size) ? drawing_size : max_size;
            }
        }
    }

    cout << cnt << '\n' << max_size;
    return 0;
}