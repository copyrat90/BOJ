#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int word[2][26];
    for (int i = 0; i < 2; i++)
        fill(word[i], word[i] + 26, 0);
    for (int i = 0; i < 2; i++)
    {
        string str;
        cin >> str;
        for (auto ch : str)
        {
            word[i][ch - 'a']++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        cnt += abs(word[0][i] - word[1][i]);
    }
    cout << cnt;

    return 0;
}