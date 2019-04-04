#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 10'007;
int memo[1002][503];

int combination(int n, int r)
{
    r = min(r, n-r);
    if (r == 0) return 1;
    if (r == 1) return n;
    if (memo[n][r] != 0)
        return memo[n][r];

    memo[n][r] = (combination(n-1,r-1) + combination(n-1,r)) % MOD;
    return memo[n][r];
}

int main(void)
{
    int n, r;
    cin >> n >> r;
    cout << combination(n, r);
    return 0;
}