#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int alphabet_cnt[26] = {0,};
    string str;
    cin >> str;
    
    for(auto ch : str)
    {
        alphabet_cnt[ch - 'a']++;
    }
    for(auto cnt : alphabet_cnt)
    {
        cout << cnt << ' ';
    }
    return 0;
}