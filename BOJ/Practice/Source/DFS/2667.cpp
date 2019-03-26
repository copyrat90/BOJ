#include <bits/stdc++.h>
using namespace std;

enum status { not_allowed, unvisited, visited };
int board[25][25];
vector<int> complex_size;
constexpr int udlr_x[4] = {1,-1,0,0};
constexpr int udlr_y[4] = {0,0,1,-1};

int main(void)
{
    int complex_num = 0;
    int N;  cin >> N;
    cin.get();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            board[i][j] = cin.get() - '0';
        cin.get();
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (board[y][x] != unvisited)
                continue;
            int size = 1;
            ++complex_num;
            stack<pair<int, int>> s;
            board[y][x] = visited;
            s.push({x, y});
            while (!s.empty())
            {
                auto p = s.top();
                s.pop();
                for (int i = 0; i < 4; i++)
                {
                    int cur_x = p.first + udlr_x[i];
                    int cur_y = p.second + udlr_y[i];
                    if (cur_x < 0 || cur_y < 0 || cur_x >= N || cur_y >= N)
                        continue;
                    if (board[cur_y][cur_x] != unvisited)
                        continue;
                    board[cur_y][cur_x] = visited;
                    s.push({cur_x, cur_y});
                    ++size;
                }
            }
            complex_size.push_back(size);
        }
    }

    cout << complex_num << '\n';
    sort(complex_size.begin(), complex_size.end());
    for (auto s : complex_size)
        cout << s << '\n';
    return 0;
}