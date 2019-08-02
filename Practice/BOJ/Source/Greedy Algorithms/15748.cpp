#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);


struct Reststop
{
	long long score;
	long long pos;

	bool operator < (const Reststop& other) const
	{
		if (this->score != other.score)
			return this->score < other.score;
		else
			return this->pos < other.pos;
	}
};

int main(void)
{
	FAST_IO;

	long long L, N, rate_f, rate_b;
	cin >> L >> N >> rate_f >> rate_b;

	priority_queue<Reststop> max_heap;
	for (int i = 0; i < N; ++i)
	{
		Reststop stop;
		cin >> stop.pos >> stop.score;
		max_heap.push(stop);
	}

	long long answer_taste = 0;
	long long prev_pos = 0;
	while (!max_heap.empty())
	{
		Reststop next_stop = max_heap.top();
		max_heap.pop();

		if (prev_pos > next_stop.pos)
			continue;

		long long sec = (rate_f - rate_b) * (next_stop.pos - prev_pos);
		answer_taste += next_stop.score * sec;

		prev_pos = next_stop.pos;
	}

	cout << answer_taste;
	return 0;
}