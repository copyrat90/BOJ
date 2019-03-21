#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; ; i++)
    {
        if (N <= 3*i*(i-1) + 1)
        {
            cout << i;
            return 0;
        }
    }
}

// 1~1      1   1개
// 2~7      2   6개
// 8~19     3   12개
// 20~37    4   18개
// 38~61    5   24개
// ...
// An = 3n(n-1)+1