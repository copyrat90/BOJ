#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
constexpr Point udlr[4] = {{1,0},{0,1}, {-1,0},{0,-1}};

int N;
char board[100][101];
bool visit_rg_blind[100][100];
bool visit_normal[100][100];

void flood_fill(const Point & start_pos, bool is_rg_blind)
{
    bool (* visit)[100] = (is_rg_blind) ? visit_rg_blind : visit_normal;
    char start_color = board[start_pos.y][start_pos.x];
    // 적록색맹은 녹색 -> 적색으로 처리
    if (is_rg_blind && start_color == 'G')
        start_color = 'R';
    queue<Point> q;
    q.push(start_pos);
    visit[start_pos.y][start_pos.x] = true;
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        for (auto dir : udlr)
        {
            Point candidate{cur.x + dir.x, cur.y + dir.y};
            if (candidate.x < 0 || candidate.y < 0 ||
                candidate.x >= N || candidate.y >= N)
                continue;
            if (visit[candidate.y][candidate.x])
                continue;
            // 적록색맹은 녹색 -> 적색으로 처리
            char candidate_color = board[candidate.y][candidate.x];
            if (is_rg_blind && candidate_color == 'G')
                candidate_color = 'R';
            // 후보가 시작위치 색깔과 다르면 패스
            if (start_color != candidate_color)
                continue;
            // 같은 영역이므로 방문 체크 후 큐에 push
            visit[candidate.y][candidate.x] = true;
            q.push({candidate.x, candidate.y});
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int area_cnt = 0, rg_area_cnt = 0;
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> board[i];
    
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (!visit_normal[y][x])
            {
                ++area_cnt;
                flood_fill({x,y}, false);
            }
            if (!visit_rg_blind[y][x])
            {
                ++rg_area_cnt;
                flood_fill({x,y}, true);
            }
        }
    }

    cout << area_cnt << ' ' << rg_area_cnt;
    return 0;
}