#include <bits/stdc++.h>
using namespace std;
 
int ac_pos[100'000];
int len;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, Q;
    cin >> N >> Q;
    string input;
    cin >> input;
 
    int pos = 0;
    while ((pos = input.find("AC", pos)) != string::npos)
    {
        ac_pos[len++] = pos;
        pos += 2;
    }
 
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int diff = lower_bound(ac_pos, ac_pos + len, r) - lower_bound(ac_pos, ac_pos + len, l);
        cout << diff << '\n';
    }
    return 0;
}