#include <bits/stdc++.h>
using namespace std;

int N;

bool is_prime(int n);
void amazing_prime(int num, int cnt);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    amazing_prime(0, 0);
    return 0;
}

void amazing_prime(int num, int cnt)
{
    if (cnt == N)
    {
        cout << num << '\n';
        return;
    }
    for (int i = 1; i < 10; ++i)
        if (is_prime(num*10 + i))
            amazing_prime(num*10 + i, cnt + 1);
}

bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
