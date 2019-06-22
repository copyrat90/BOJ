#include <bits/stdc++.h>
using namespace std;

constexpr int CMD_MAX = 10000;

template <typename T>
class MyDeque
{
    T arr[2*CMD_MAX + 5];
    int head = CMD_MAX + 2;
    int tail = CMD_MAX + 2;
public:
    void push_front(T data) { arr[--head] = data; }
    void push_back(T data) { arr[tail++] = data; }
    void pop_front() { head++; }
    void pop_back() { tail--; }
    int size() { return tail - head; }
    bool empty() { return size() == 0; }
    int front() { return arr[head]; }
    int back() { return arr[tail - 1]; }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MyDeque<int> dq;
    int N;
    cin >> N;
    while (N--)
    {
        int arg;
        string cmd;
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> arg;
            dq.push_front(arg);
        }
        else if (cmd == "push_back")
        {
            cin >> arg;
            dq.push_back(arg);
        }
        else if (cmd == "pop_front")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if (cmd == "front")
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else // cmd == "back"
        {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }
    return 0;
}