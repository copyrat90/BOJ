#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

enum field_status {not_allowed, unvisited, visited};
int field[50][50];
constexpr Point udlr[4] = {{1,0},{0,1}, {-1,0}, {0,-1}};

// DFS
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--)
    {
        // 입력
        int M_x, N_y, K;
        cin >> M_x >> N_y >> K;
        while (K--)
        {
            int x, y;
            cin >> x >> y;
            field[y][x] = unvisited;
        }
        // 연결된 배추 계산
        stack<Point> st;
        int cnt = 0;
        for (int y = 0; y < N_y; y++)
        {
            for (int x = 0; x < M_x; x++)
            {
                if (field[y][x] != unvisited)
                    continue;
                // 방문 안 한 배추면 방문하고 스택에 넣음
                field[y][x] = visited;
                st.push({x, y});
                cnt++;
                // Flood Fill
                while(!st.empty())
                {
                    Point cur = st.top();
                    st.pop();
                    // 상하좌우 방문
                    for (auto dir : udlr)
                    {
                        int x = cur.x + dir.x;
                        int y = cur.y + dir.y;
                        // 밭을 넘어가면 패스
                        if (x < 0 || y < 0 || x >= M_x || y >= N_y)
                            continue;
                        // 방문 안 한 배추가 아니면 패스
                        if (field[y][x] != unvisited)
                            continue;
                        
                        field[y][x] = visited;
                        st.push({x, y});
                    }
                }
            }
        }
        // 출력
        cout << cnt << '\n';
    }
}