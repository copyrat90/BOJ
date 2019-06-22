#include <bits/stdc++.h>
using namespace std;

int N_y, M_x;
bool trash_board[100][100];
constexpr int dy[4] = {0, 0, -1, 1};
constexpr int dx[4] = {-1, 1, 0, 0};
int biggest_size = -1;

int main(void)
{
    int K;
    cin >> N_y >> M_x >> K;
    while (K--)
    {
        int r, c;
        cin >> r >> c;
        trash_board[r - 1][c - 1] = true;
    }

    // 각 점에 대해 Flood Fill
    // 간단하게 (방문 == 쓰레기 제거)
    stack<pair<int, int>> st;
    for (int y = 0; y < N_y; ++y)
        for (int x = 0; x < M_x; ++x)
            if (trash_board[y][x])
            {
                int cur_size = 0;
                trash_board[y][x] = false;
                st.push({y, x});
                while (!st.empty())
                {
                    ++cur_size;
                    auto p = st.top();
                    st.pop();
                    for (int i = 0; i < 4; ++i)
                    {
                        const int candi_y = p.first + dy[i];
                        const int candi_x = p.second + dx[i];
                        if (candi_y < 0 || candi_x < 0 || candi_y >= N_y || candi_x >= M_x)
                            continue;
                        if (!trash_board[candi_y][candi_x])
                            continue;
                        //++cur_size;
                        trash_board[candi_y][candi_x] = false;
                        st.push({candi_y, candi_x});
                    }
                }
                biggest_size = max(biggest_size, cur_size);
            }
    cout << biggest_size;
    return 0;
}