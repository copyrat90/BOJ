#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


int main(void)
{
	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		char input[4];
		cin >> input;

		int a = atoi(strtok(input, ","));
		int b = atoi(strtok(NULL, ","));
		cout << a + b << '\n';
	}

	return 0;
}