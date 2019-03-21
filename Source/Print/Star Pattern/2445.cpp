#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout.put('*');
        for (int j = 0; j < 2*(n-i); j++)
            cout.put(' ');
        for (int j = 0; j < i; j++)
            cout.put('*');
        cout.put('\n');
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            cout.put('*');
        for (int j = 0; j < 2*n-2*i; j++)
            cout.put(' ');
        for (int j = 0; j < i; j++)
            cout.put('*');
        cout << '\n';
    }

    return 0;
}