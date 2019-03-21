#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strLine;
	while (getline(cin, strLine))
	{
		cout << strLine << endl;
	}

	return 0;
}