#include <bits/stdc++.h>
using namespace std;

int word[2][26];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str1, str2;
    cin >> str1 >> str2;

    for (auto ch : str1)
        word[0][ch - 'a']++;
    for (auto ch : str2)
        word[1][ch - 'a']++;

    int cnt = 0;
    for (int i = 0; i < 26; i++)
        cnt += abs(word[0][i] - word[1][i]);
    cout << cnt;

    return 0;
}