#include <bits/stdc++.h>
using namespace std;

int memo[1003];

// 경우의 수 세는 함수
int count_case(int width)
{
	if (width < 2)
		return 1;
	if (memo[width] != 0)
		return memo[width];
	memo[width] = (count_case(width - 2) + count_case(width - 1)) % 10'007;
	return memo[width];
}


int main(void)
{
	int n;	cin >> n;
	cout << count_case(n);
	return 0;
}