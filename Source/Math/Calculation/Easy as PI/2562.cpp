#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int how_many = 9;
    int max;
    int max_idx = 0;

    cin >> max;
    for (int i = 1; i < how_many; i++)
    {
        int temp;
        cin >> temp;
        if (temp > max)
        {
            max = temp;
            max_idx = i;
        }
    }
    
    // (인덱스 + 1)번째 수
    cout << max << '\n' << max_idx + 1;
    return 0;
}