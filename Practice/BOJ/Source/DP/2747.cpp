#include <bits/stdc++.h>
using namespace std;

constexpr int N_MAX = 45;
int dp[N_MAX + 1];

int main(void)
{
    int n;  cin >> n;
    dp[0] = 0, dp[1] = 1;
    // 이전에 구한 값들을 이용해 계산
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}
