#include <bits/stdc++.h>
using namespace std;

int arr[26];
constexpr int visit = -1;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		bool impossible = false;
		fill(arr, arr + 26, 0);
		string input;
		cin >> input;
		if (input.length() > 26)
		{
			cout << "No\n";
			continue;
		}
		for (char ch : input)
		{
			++arr[ch - 'a'];
			if (arr[ch - 'a'] > 1)
			{
				impossible = true;
				break;
			}
		}
		if (impossible)
		{
			cout << "No\n";
			continue;
		}
		bool chunk_start = false;
		bool chunk_end = false;
		for (int i = 0; i < 26; ++i)
		{
			if (chunk_end)
			{
				if (arr[i] == 1)
				{
					impossible = true;
					break;
				}
			}
			else if (chunk_start)
			{
				if (arr[i] == 0)
					chunk_end = true;
			}
			else if (arr[i] == 1) // chunk just started
			{
				chunk_start = true;
			}
		}
		if (impossible)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}