#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
constexpr Point udlr[4] = {{1,0},{0,1},{-1,0},{0,-1}};
enum status { not_allowed = -1, unvisited, visited };
int visit[100][100];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int area_cnt = 0;
    vector<int> area_size;
    int M_y, N_x, K;
    cin >> M_y >> N_x >> K;

    while (K--)
    {
        int ld_x, ld_y, ru_x, ru_y;
        cin >> ld_x >> ld_y >> ru_x >> ru_y;
        for (int y = ld_y; y < ru_y; ++y)
            for (int x = ld_x; x < ru_x; ++x)
                visit[y][x] = not_allowed;
    }

    for (int y = 0; y < M_y; ++y)
    {
        for (int x = 0; x < N_x; ++x)
        {
            if (visit[y][x] != unvisited)
                continue;
            ++area_cnt;
            int size = 1;
            stack<Point> s;
            visit[y][x] = visited;
            s.push({x, y});
            while (!s.empty())
            {
                Point p = s.top();
                s.pop();
                for (auto dr : udlr)
                {
                    Point && cur = {p.x + dr.x, p.y + dr.y};
                    if (cur.x < 0 || cur.y < 0 || cur.x >= N_x || cur.y >= M_y)
                        continue;
                    if (visit[cur.y][cur.x] != unvisited)
                        continue;
                    ++size;
                    visit[cur.y][cur.x] = visited;
                    s.push({cur.x, cur.y});
                }
            }
            area_size.push_back(size);
        }
    }

    cout << area_cnt << '\n';
    sort(area_size.begin(), area_size.end());
    for (auto s : area_size)
        cout << s << ' ';
    return 0;
}