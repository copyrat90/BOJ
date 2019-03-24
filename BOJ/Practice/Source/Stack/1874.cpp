#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    queue<int> sequence;
    queue<char> result;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sequence.push(temp);
    }
    
    stack<int> s;
    int next_num = 1;
    bool success = true;
    while (!sequence.empty())
    {
        if (s.empty() || s.top() < sequence.front())
        {
            s.push(next_num++);
            result.push('+');
        }
        else if (s.top() == sequence.front())
        {
            s.pop(); sequence.pop();
            result.push('-');
        }
        else // s.top() > sequence.front()
        {
            success = false;
            break;
        }
    }

    if (success)
    {
        while (!result.empty())
        {
            cout << result.front() << '\n';
            result.pop();
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}