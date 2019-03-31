#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt;
	cin >> cnt;

	vector<int> even;
	even.reserve(cnt);
	vector<int> odd;
	odd.reserve(cnt);

	for (int i = 0; i < cnt; ++i)
	{
		int tmp;	cin >> tmp;
		if (tmp % 2 == 0)
			even.push_back(tmp);
		else
			odd.push_back(tmp);
	}

	int remain_cnt;
	bool even_is_big = false;
	if (even.size() > odd.size())
	{
		remain_cnt = even.size() - odd.size() - 1;
		even_is_big = true;
	}
	else if (even.size() < odd.size())
	{
		remain_cnt = odd.size() - even.size() - 1;
		even_is_big = false;
	}
	else
		remain_cnt = 0;

	int sum = 0;
	if (remain_cnt == 0)
		cout << 0;
	else if (even_is_big)
	{
		sort(even.begin(), even.end());
		for (int i = 0; i < remain_cnt; ++i)
			sum += even[i];
		cout << sum;
	}
	else
	{
		sort(odd.begin(), odd.end());
		for (int i = 0; i < remain_cnt; ++i)
			sum += odd[i];
		cout << sum;
	}

	return 0;
}