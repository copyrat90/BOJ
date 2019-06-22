#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

constexpr int INF = 987654321;
enum board_stat { BLANK = '0', TOWN = '1' };
char board[20][21];

int main(void)
{
    FAST_IO;

    int N_r, M_c;
    cin >> N_r >> M_c;
    for (int r = 0; r < N_r; ++r)
        cin >> board[r];

    int min_sec = INF;
    // 독주머니 설치할 지점 1 선택
    for (int p1_r = 0; p1_r < N_r; ++p1_r)
        for (int p1_c = 0; p1_c < M_c; ++p1_c)
        {
            // 마을이면 pass
            if (board[p1_r][p1_c] == TOWN)
                continue;
            // 지점 2 선택
            for (int p2_r = 0; p2_r < N_r; ++p2_r)
                for (int p2_c = 0; p2_c < M_c; ++p2_c)
                {
                    // 마을이면 pass
                    if (board[p2_r][p2_c] == TOWN)
                        continue;
                    // 지점 1 과 같은 점이면 pass
                    if (p2_r == p1_r && p2_c == p1_c)
                        continue;
                    // 선택된 지점 1 & 2 에 대해 시간초 계산
                    // 각 마을에서 독주머니까지의 거리를 계산하면 됨.
                    int cur_sec = 0;
                    for (int town_r = 0; town_r < N_r; ++town_r)
                        for (int town_c = 0; town_c < M_c; ++town_c)
                        {
                            // 마을이 아니면 pass
                            if (board[town_r][town_c] != TOWN)
                                continue;
                            // 마을 <-> 독주머니 사이의 가로, 세로 거리 계산
                            int town_sec = min(abs(town_r - p1_r) + abs(town_c - p1_c), abs(town_r - p2_r) + abs(town_c - p2_c));
                            cur_sec = max(cur_sec, town_sec);
                        }
                    // 최소 시간초 계산
                    min_sec = min(min_sec, cur_sec);
                }
        }

    cout << min_sec;
    return 0;
}