#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int T;
    cin >> str;
    cin >> T;

    while (T--)
    {
        int i, j;
        cin >> i >> j;
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    cout << str;
    return 0;
}