#include <bits/stdc++.h>
using namespace std;

// 완전 탐색 (Brute-Force Search)
// O(nlogn) : n개마다 각 자릿수 분리 연산
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int M = 1; M < N; M++)
    {
        int tmp = M;
        int digit_sum = 0;
        while (tmp > 0)
        {
            digit_sum += tmp % 10;
            tmp /= 10;
        }
        if (M + digit_sum == N)
        {
            cout << M;
            return 0;
        }
    }

    cout << 0;
    return 0;
}