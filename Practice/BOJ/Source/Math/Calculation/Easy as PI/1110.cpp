#include <iostream>
using namespace std;


int main(void)
{
	int n;
	cin >> n;

	int x = n;
	int cnt = 0;
	do
	{
		x = (x % 10) * 10 + (x / 10 + x % 10) % 10;
		cnt++;
	} while (x != n);

	cout << cnt;

	return 0;
}