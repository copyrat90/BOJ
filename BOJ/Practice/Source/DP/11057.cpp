#include <bits/stdc++.h>
using namespace std;

constexpr int mod_val = 10'007;
int memo[10][1001];

int dfs(int digit, int cnt)
{
    if (cnt == 1)
        return 1;
    if (memo[digit][cnt])
        return memo[digit][cnt];
    
    int sum = 0;
    for (int i = digit; i < 10; ++i)
        sum += dfs(i, cnt - 1) % mod_val;
    memo[digit][cnt] = sum;
    return sum;
}

int main(void)
{
    int n;  cin >> n;
    int sum = 0;
    for (int i = 0; i < 10; ++i)
        sum += dfs(i, n) % mod_val;
    
    sum %= mod_val;
    cout << sum;
    return 0;
}