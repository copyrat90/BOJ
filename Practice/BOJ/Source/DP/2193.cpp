#include <bits/stdc++.h>
using namespace std;

constexpr int N_MAX = 90;
long long memo[N_MAX + 1][2];

long long pinary(long long n, int digit)
{
	// leaf 에 도달하면 1개이니 1 반환
	if (n == 1)
		return 1;
	// 이미 메모해놨다면 바로 반환
	if (memo[n][digit] != 0)
		return memo[n][digit];

	// 숫자가 1이면 다음 숫자는 0만 가능
	if (digit == 1)
		memo[n][digit] = pinary(n - 1, 0);
	// 숫자가 0이면 다음 숫자는 1 or 0
	else  // digit == 0
		memo[n][digit] = pinary(n - 1, 1) + pinary(n - 1, 0);

	return memo[n][digit];
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	cout << pinary(n, 1);

	return 0;
}