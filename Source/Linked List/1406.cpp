#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	string str;
	int T;
	list<char> l;
	getline(cin, str);
	cin >> T;
	for(int i = 0; i < str.size(); i++)
		l.push_back(str[i]);
	
	auto cursor = l.end();
	while (T--)
	{
		char input;
		cin >> input;
		switch (input)
		{
		case 'L':
			if (cursor != l.begin())
				cursor--;
			break;
		case 'D':
			if (cursor != l.end())
				cursor++;
			break;
		case 'B':
			if (cursor != l.begin())
			    l.erase(prev(cursor));
			break;
		case 'P':
			cin >> input;
			l.insert(cursor, input);
			break;
		}
	}
	
	for (auto ch : l)
		cout << ch;
	return 0;
}