#include <bits/stdc++.h>
using namespace std;

constexpr int SMALL_NUM = -987'654'321;
int n, m;
int card[101];

int max_sum(int sum = 0, int i = -1, int cnt = 0)
{
    if (sum > m)
        return SMALL_NUM;
    if (cnt == 3)
        return sum;
    if (i + 1 >= n)
        return SMALL_NUM;

    return max(max_sum(sum + card[i + 1], i + 1, cnt + 1), max_sum(sum, i + 1, cnt));
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> card[i];

    cout << max_sum();
    return 0;
}