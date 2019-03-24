#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int prev = 0;
    int curr = 1;
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int temp = curr;
        curr += prev;
        prev = temp;
    }
    cout << curr;
    return 0;
}