#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int name_len;
    string name;
    cin >> name_len;
    cin >> name;

    int score = 0;
    for (char ch : name)
    {
        score += ch - 'A' + 1;
    }
    cout << score;
    return 0;
}