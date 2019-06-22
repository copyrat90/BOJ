#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

enum board_stat{land='L', water='W' };
char board[50][51];
int max_distance;

constexpr int dy[4] = { 0,0,-1,1 };
constexpr int dx[4] = { 1,-1,0,0 };


int main(void)
{
	FAST_IO;
	int H_y, W_x;
	cin >> H_y >> W_x;

	for (int y = 0; y < H_y; ++y)
		cin >> board[y];

	for (int y=0;y<H_y;++y)
		for (int x = 0; x < W_x; ++x)
		{
			if (board[y][x] == water)
				continue;
			// 새로운 bfs : 보물상자 (x,y) -> 가장 먼 지점
			int visit_turn[50][50];
			for (int i = 0; i < 50; ++i)
				fill(visit_turn[i], visit_turn[i] + 50, 0);
			queue<pair<int, int>> q;
			// visit_turn[y][x] = 0;
			q.push({ y,x });
			while (!q.empty())
			{
				auto p = q.front(); q.pop();
				for (int i = 0; i < 4; ++i)
				{
					const int candi_y = p.first + dy[i];
					const int candi_x = p.second + dx[i];
					if (candi_y < 0 || candi_x < 0 || candi_y >= H_y || candi_x >= W_x)
						continue;
					if (board[candi_y][candi_x] == water || visit_turn[candi_y][candi_x] != 0)
						continue;
					// 방문하지 않은 점 발견
					visit_turn[candi_y][candi_x] = visit_turn[p.first][p.second] + 1;
					q.push({ candi_y, candi_x });
				}
			}
			// bfs 종료, 이번 (x,y)의 보물상자 최대 거리 계산
			int cur_distance = 0;
			for (int y = 0; y < H_y; ++y)
				for (int x = 0; x < W_x; ++x)
					if (visit_turn[y][x] > cur_distance)
						cur_distance = visit_turn[y][x];

			max_distance = max(max_distance, cur_distance);
		}

	cout << max_distance;
	return 0;
}