#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool a_matrix[100][100];
bool visit[100];


bool dfs(int start, int cur, int dest)
{
	if (cur == dest && visit[dest])
		return true;
	for (int x = 0; x < N; ++x)
	{
		if (a_matrix[cur][x] && !visit[x])
		{
			visit[x] = true;
			if (dfs(start, x, dest))
				return true;
		}
	}
	return false;
}

int main(void)
{
	cin >> N;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> a_matrix[y][x];

	// 매 인접행렬마다 경로 존재 여부를 구한다.
	for (int start = 0; start < N; ++start)
	{
		for (int dest = 0; dest < N; ++dest)
		{
			fill(visit, visit + 100, false);
			cout << dfs(start, start, dest) << ' ';
		}
		cout << '\n';
	}
	return 0;
}