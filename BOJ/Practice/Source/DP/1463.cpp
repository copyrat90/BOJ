#include <bits/stdc++.h>
using namespace std;

constexpr int BIG = 987'654'321;
vector<int> memo;

int main(void)
{
    int N;  cin >> N;
    memo.resize(N + 1);

    for (int i = 2; i <= N; ++i)
    {
        int cnt = BIG;
        if (i % 3 == 0)
            cnt = min(cnt, memo[i / 3] + 1);
        if (i % 2 == 0)
            cnt = min(cnt, memo[i / 2] + 1);
        cnt = min(cnt, memo[i - 1] + 1);
        memo[i] = cnt;
    }
    cout << memo[N];
    return 0;
}