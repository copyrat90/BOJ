#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	string word;
	while (cin >> word)
		cnt++;
	
	cout << cnt;
	return 0;
}