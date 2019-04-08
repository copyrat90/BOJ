#include <bits/stdc++.h>
using namespace std;

long long c;

long long power(long long a, long long b)
{
    if (b == 1)
        return a % c;

    long long tmp = power(a, b / 2) % c;
    if (b % 2 == 0)
        return tmp * tmp % c;
    else
        return ((a % c) * tmp % c) * tmp % c;
}

int main(void)
{
    long long a, b;
    cin >> a >> b >> c;
    cout << power(a, b);
    return 0;
}