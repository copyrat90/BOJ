#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int odd_sum = 0;
    int odd_min = 777;

    for (int i = 0; i < 7; i++)
    {
        int temp;
        cin >> temp;
        if (temp % 2 == 1)
        {
            odd_sum += temp;
            if (odd_min > temp)
                odd_min = temp;
        }
    }

    if (odd_sum == 0)
    {
        cout << -1;
    }
    else
    {
        cout << odd_sum << '\n' << odd_min;
    }
    return 0;
}