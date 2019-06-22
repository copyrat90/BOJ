#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000;
constexpr int PISANO_PERIOD = 1'500'000;
int fibo[PISANO_PERIOD + 2];

int main(void)
{
    long long n;  cin >> n;
    n %= PISANO_PERIOD;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; ++i)
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    cout << fibo[n];
    return 0;
}