#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--)
    {
        int bracket_cnt = 0;
        string s;  cin >> s;

        for (char ch : s)
        {
            if (ch == '(')
                ++bracket_cnt;
            else // ch == ')'
            {
                if (--bracket_cnt < 0)
                    break;
            }
        }

        if (bracket_cnt == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}