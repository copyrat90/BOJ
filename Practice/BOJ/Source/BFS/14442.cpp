#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

constexpr int BIG_NUM = 987'654'321;
constexpr int MAX_BREAK = 10;

enum map_status { road, wall };
int map[1000][1000];
int visit[1000][1000][MAX_BREAK + 1];
constexpr pair<int, int> udlr[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N_y, M_x, K_break;
	cin >> N_y >> M_x >> K_break;
	cin.get();	// '\n'

	for (int y = 0; y < N_y; ++y)
	{
		for (int x = 0; x < M_x; ++x)
			map[y][x] = cin.get() - '0';
		cin.get();	// '\n'
	}

	// (y, x, 벽을 부순 횟수)
	queue<tuple<int, int, int>> q;
	visit[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int cur_y, cur_x, cur_break_cnt;
		tie(cur_y, cur_x, cur_break_cnt) = q.front();
		q.pop();
		if (cur_y == N_y - 1 && cur_x == M_x - 1)
			break;
		for (auto dir : udlr)
		{
			int candi_y = cur_y + dir.first;
			int candi_x = cur_x + dir.second;
			// 범위 체크
			if (candi_y < 0 || candi_x < 0 || candi_y >= N_y || candi_x >= M_x)
				continue;
			// 방문 체크
			bool is_visited = false;
			for (int i = cur_break_cnt; i >= 0; --i)
				if (visit[candi_y][candi_x][i] > 0)
				{
					is_visited = true;
					break;
				}
			if (is_visited) continue;
			// 방문
			if (map[candi_y][candi_x] == wall)
				if (cur_break_cnt >= K_break)
					continue;
				else
				{
					visit[candi_y][candi_x][cur_break_cnt + 1] = visit[cur_y][cur_x][cur_break_cnt] + 1;
					q.push({ candi_y, candi_x, cur_break_cnt + 1 });
				}
			else
			{
				visit[candi_y][candi_x][cur_break_cnt] = visit[cur_y][cur_x][cur_break_cnt] + 1;
				q.push({ candi_y, candi_x, cur_break_cnt });
			}
		}
	}
	// 최단거리 출력
	int min_turn = BIG_NUM;
	for (int turn : visit[N_y - 1][M_x - 1])
	{
		if (turn != 0)
			min_turn = min(turn, min_turn);
	}
	if (min_turn == BIG_NUM)
		min_turn = -1;
	cout << min_turn;
	return 0;
}