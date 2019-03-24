#include <iostream>
#include <sstream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	getline(cin, temp);
	stringstream ss(temp);
	int cnt = 0;
	while (ss >> temp)
		cnt++;

	cout << cnt;
}