#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> l;
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string key_log;
        getline(cin, key_log);
        auto cursor = l.end();
        for (char ch : key_log)
        {
            switch(ch)
            {
            case '-':
                if (cursor != l.begin())
                    l.erase(prev(cursor));
                break;
            case '<':
                if (cursor != l.begin())
                    cursor--;
                break;
            case '>':
                if (cursor != l.end())
                    cursor++;
                break;
            default:
                l.insert(cursor, ch);
            }
        }

        for (auto ch : l)
            cout << ch;
        l.clear();
        cout << '\n';
    }

    return 0;
}