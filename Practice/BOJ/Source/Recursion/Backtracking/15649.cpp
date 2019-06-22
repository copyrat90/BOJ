#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> selected;
bool is_used[10];

void permu()
{
    if (selected.size() == m)
    {
        for (auto num : selected)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!is_used[i])
        {
            is_used[i] = true;
            selected.push_back(i);
            permu();
            is_used[i] = false;
            selected.pop_back();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    permu();
    return 0;
}