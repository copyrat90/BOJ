#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

bool is_used[1002];

int main(void)
{
	FAST_IO;

	int N;	cin >> N;
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < N; ++i)
	{
		int day_left, score;
		cin >> day_left >> score;
		pq.emplace(score, day_left);
	}

	int answer_score = 0;
	while (!pq.empty())
	{
		int score, day_left;
		tie(score, day_left) = pq.top();
		pq.pop();

		for (int i = day_left; i > 0; --i)
		{
			if (!is_used[i])
			{
				is_used[i] = true;
				answer_score += score;
				break;
			}
		}
	}

	cout << answer_score;
	return 0;
}