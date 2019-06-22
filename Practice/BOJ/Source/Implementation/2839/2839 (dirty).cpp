#include <iostream>
#include <stack>
using namespace std;


// 순서도 바탕으로 작성한, 가독성과 효율은 갖다버린 코드.
// https://drive.google.com/file/d/1gxip9HBnoG3IGafWSLWIDqR980gnZxEL/view?usp=sharing
int main(void)
{
	stack<int> st;
	int x;
	cin >> x;
	
	while (true)
	{
		if (x == 5 || x == 3)
		{
			cout << st.size() + 1;
			return 0;
		}
		else if (x > 5)
		{
			st.push(5);
			x -= 5;
		}
		else if (x > 3)
		{
			st.push(3);
			x -= 3;
		}
		else
		{
			if (st.size() == 0)
			{
				cout << -1;
				return 0;
			}
			while (true)
			{
				x += st.top();
				if (st.top() == 5)
				{
					st.pop();
					st.push(3);
					x -= 3;
					break;
				}
				else
				{
					st.pop();
					if (st.size() == 0)
					{
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
}