#include <bits/stdc++.h>
using namespace std;

int gms(int n, int k = 0)
{
    if (k > n)
        return k / 10;
    return max(gms(n, k*10+4), gms(n, k*10+7));
}

int main(void)
{
    int n;
    cin >> n;

    cout << gms(n);
    return 0;
}