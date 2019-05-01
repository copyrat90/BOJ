#include <bits/stdc++.h>
using namespace std;

constexpr char POISONED = 'p';
constexpr char TOWN = '1';
constexpr pair<int, int> udlr[4] = { {1,0},{0,1},{-1,0},{0,-1} };
int N_r, M_c;
int min_sec = 987654321;
char town[20][21];

pair<pair<int, int>, pair<int, int>> selected_points;


// 중독되지 않은 마을이 남아있는지 체크하는 함수
bool check_remain_town(char(*town_status)[21])
{
	for (int r = 0; r < N_r; ++r)
		for (int c = 0; c < M_c; ++c)
			if (town_status[r][c] == TOWN)
				return true;
	return false;
}

// 두 지점을 받아 전부 중독시키는 데 몇 초 걸리는지 계산
void calc_sec()
{
	// 이번에 쓸 마을 중독 현황 지도 생성
	char town_status[20][21];
	for (int r = 0; r < N_r; ++r)
		strcpy(town_status[r], town[r]);
	// bfs
	int sec = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(selected_points.first, sec));
	q.push(make_pair(selected_points.second, sec));

	while (true)
	{
		// 남은 마을이 없으면 min_sec 계산하고 return
		if (!check_remain_town(town_status))
		{
			min_sec = min(min_sec, sec);
			return;
		}
		++sec;
		// 1초 전에 중독된 지점의 인접 지역을 중독시킴
		while (!q.empty() && q.front().second == sec - 1)
		{
			auto prev_poisoned = q.front().first;
			q.pop();
			// 상하좌우
			for (auto dir : udlr)
			{
				pair<int, int> candi = { prev_poisoned.first + dir.first, prev_poisoned.second + dir.second };
				// 배열 범위를 벗어나면 pass
				if (candi.first < 0 || candi.first >= N_r ||
					candi.second < 0 || candi.second >= M_c)
					continue;
				// 이미 중독된 지점이면 pass
				if (town_status[candi.first][candi.second] == POISONED)
					continue;
				// 빈 공간이거나 마을이면 중독시키고 큐에 넣음
				town_status[candi.first][candi.second] = POISONED;
				q.push(make_pair(candi, sec));
			}
		}
	}
}


// 독주머니를 설치할 두 곳의 모든 조합 구해
// 각 조합마다 calc_sec 호출
void select_two_points(int selected_cnt = 0)
{
	// 첫번째 설치 지점 선택
	if (selected_cnt == 0)
	{
		auto& p1 = selected_points.first;
		for (int r = 0; r < N_r; ++r)
			for (int c = 0; c < M_c; ++c)
			{
				// 마을에는 독주머니를 설치할 수 없으니 pass
				if (town[r][c] == '1')
					continue;

				p1.first = r;
				p1.second = c;
				select_two_points(1);
			}
	}
	// 두번째 설치 지점 선택
	else // (selected_cnt == 1)
	{
		const auto& p1 = selected_points.first;
		auto& p2 = selected_points.second;
		for (int r = 0; r < N_r; ++r)
			for (int c = 0; c < M_c; ++c)
			{
				// 마을에는 독주머니를 설치할 수 없으니 pass
				if (town[r][c] == '1')
					continue;
				// 같은 지점에 독주머니를 2개 설치하는 경우는 pass
				if (p1.first == r && p1.second == c)
					continue;

				p2.first = r;
				p2.second = c;
				calc_sec();
			}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N_r >> M_c;
	for (int r = 0; r < N_r; ++r)
		cin >> town[r];
	select_two_points();
	cout << min_sec;
	return 0;
}