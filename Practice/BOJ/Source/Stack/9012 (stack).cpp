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
        string s;  cin >> s;
        stack<char> st;

        bool vps = true;
        for (char ch : s)
        {
            if (ch == '(')
                st.push(ch);
            // 아래는 ch == ')' 전제
            else if (st.empty() || st.top() != '(')
            {
                vps = false;
                break;
            }
            else
                st.pop();
        }
        vps = vps && st.empty();

        if (vps)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}