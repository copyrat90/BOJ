#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long result = 1;
    do
    {
        int cur_digit = b % 2;
        b /= 2;
        if (cur_digit)
            result = result * a % c;
        a = a * a % c;
    } while (b != 0);
    
    cout << result;
    return 0;
}