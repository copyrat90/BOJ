#include <iostream>
using namespace std;

constexpr int CMD_MAX = 10000;

template <typename T>
class MyQueue
{
    T arr[CMD_MAX];
    int head = 0;
    int tail = 0;
public:
    void push(T data) { arr[tail++] = data; }
    void pop() { head++; }
    int size() { return tail - head; }
    bool empty() { return size() == 0; }
    int front() { return arr[head]; }
    int back() { return arr[tail - 1]; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	MyQueue<int> q;
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
			q.push(num);
		}
		else if (command == "pop")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (command == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else // command == "back"
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
	return 0;
}
