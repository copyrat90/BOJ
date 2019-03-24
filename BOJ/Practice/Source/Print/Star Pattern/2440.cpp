#include <iostream>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = N; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
			cout << '*';
		cout << endl;
	}

	return 0;
}