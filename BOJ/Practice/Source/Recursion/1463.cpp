#include <bits/stdc++.h>
using namespace std;

constexpr int BIG = 987654321;
vector<int> memo;

// 반환 : 연산 횟수의 최솟값
int recursive(int n)
{
    if (n == 1) return 0;
    if (memo[n] != -1)  return memo[n];

    int min_cnt = BIG;
    if (n % 3 == 0)
        min_cnt = min(min_cnt, recursive(n / 3) + 1);
    if (n % 2 == 0)
        min_cnt = min(min_cnt, recursive(n / 2) + 1);
    min_cnt = min(min_cnt, recursive(n - 1) + 1);
    
    memo[n] = min_cnt;
    return min_cnt;
}

int main(void)
{
    int n;  cin >> n;
    memo.resize(n + 1, -1);
    cout << recursive(n);
    return 0;
}