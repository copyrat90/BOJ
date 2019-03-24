#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	int sum = 0;
	string inputLine;

	cin >> inputLine;

	for (int i = 0; i < n; i++)
	{
		sum += inputLine[i] - '0';
	}

	cout << sum;
	return 0;
}