#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    if (a > b)
    {
        long long temp = a;
        a = b;
        b = temp;
    }
    int diff = b - a - 1;
    if (diff < 0)
        diff = 0;
    cout << diff << '\n';
    for (long long i = a + 1; i < b; i++)
    {
        cout << i << ' ';
    }
    return 0;
}