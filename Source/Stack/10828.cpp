#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_SIZ = 10003;

template <typename T>
class MyStack
{
    T arr[MAX_SIZ];
    int curr = 0;
public:
    void push(T x) { arr[curr++] = x; }
    void pop() { curr--; }
    int size() { return curr; }
    bool empty() { return curr == 0; }
    int top() { return arr[curr-1]; }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    MyStack<int> s;
    int N;
    cin >> N;

    while (N--)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (command == "pop")
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (command == "size")
        {
            cout << s.size() << '\n';
        }
        else if (command == "empty")
        {
            cout << s.empty() << '\n';
        }
        // command == "top"
        else if (s.empty())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << s.top() << '\n';
        }
    }
    return 0;
}