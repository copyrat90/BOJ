#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        string str1, str2;
        cin >> str1 >> str2;

        int alphabet_cnt[26];
        fill(alphabet_cnt, alphabet_cnt + 26, 0);
        for (auto ch : str1)
            alphabet_cnt[ch - 'a']++;
        for (auto ch : str2)
            alphabet_cnt[ch - 'a']--;

        bool is_possible = true;
        for (auto cnt : alphabet_cnt)
            if (cnt != 0)
            {
                is_possible = false; 
                break;
            }
        
        if (is_possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}