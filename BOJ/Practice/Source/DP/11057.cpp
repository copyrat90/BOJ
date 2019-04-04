#include <bits/stdc++.h>
using namespace std;

constexpr int mod_val = 10'007;
int memo[10][1002];

int inc(int digit, int remain)
{
	if (remain == 0)
		return 1;
	int & cur_memo = memo[digit][remain];
	if (cur_memo != 0)
		return cur_memo;

	int sum = 0;
	for (int i = digit; i < 10; ++i)
		sum += inc(i, remain - 1) % mod_val;
	sum %= mod_val;
	return cur_memo = sum;
}

int main(void)
{
	int n;	cin >> n;
	cout << inc(0, n);
	return 0;
}