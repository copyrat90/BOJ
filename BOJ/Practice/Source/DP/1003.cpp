#include <bits/stdc++.h>
using namespace std;

int cnt_0, cnt_1;
// 피보나치 값, cnt_0, cnt_1
tuple<int,int,int> memo[41];

int fibo(int n)
{
    if (n == 0)
    {
        ++cnt_0;
        return 0;
    }
    if (n == 1)
    {
        ++cnt_1;
        return 1;
    }
    if (get<0>(memo[n]) != 0)
    {
        int tmp_fibo, tmp_0, tmp_1;
        tie(tmp_fibo, tmp_0, tmp_1) = memo[n];
        cnt_0 += tmp_0;
        cnt_1 += tmp_1;
        return tmp_fibo;
    }

    memo[n] = {fibo(n-1) + fibo(n-2), cnt_0, cnt_1};
    return get<0>(memo[n]);
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--)
    {
        cnt_0 = 0, cnt_1 = 0;
        int N;  cin >> N;
        fibo(N);
        cout << cnt_0 << ' ' << cnt_1 << '\n';
    }
    return 0;
}