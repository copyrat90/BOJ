#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;	cin >> n;
	vector<int> arr(n);
	vector<int> once;
	vector<int> twice;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	bool impossible = false;
	for (auto iter = arr.begin(); iter != arr.end(); ++iter)
	{
		int cur = *iter;
		auto next_iter = upper_bound(iter, arr.end(), cur);
		if (next_iter - iter > 2)
		{
			impossible = true;
			break;
		}
		else if (next_iter - iter == 2)
		{
			once.push_back(cur);
			twice.push_back(cur);
		}
		else
		{
			once.push_back(cur);
		}
		iter = next_iter - 1;
	}

	if (impossible)
	{
		cout << "NO";
	}
	else
	{
		sort(once.begin(), once.end());
		sort(twice.rbegin(), twice.rend());
		cout << "YES\n";
		cout << once.size() << '\n';
		for (auto d : once)
			cout << d << ' ';
		cout << '\n';
		cout << twice.size() << '\n';
		for (auto d : twice)
			cout << d << ' ';
	}
	return 0;
}