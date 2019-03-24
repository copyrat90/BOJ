#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < n - i; j++)
            cout.put(' ');
        for (int j = 0; j < 2*i-1; j++)
            cout.put('*');
        cout.put('\n');
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout.put(' ');
        for (int j = 0; j < 2*i-1; j++)
            cout.put('*');
        cout.put('\n');
    }
    return 0;
}