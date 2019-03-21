#include <iostream>
using namespace std;


int main(void)
{
	int year = 1;
	int e = 1, s = 1, m = 1;
	int input[3];
	cin >> input[0] >> input[1] >> input[2];

	while (!(e == input[0] && s == input[1] && m == input[2]))
	{
		year++; e++; s++; m++;
		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;
	}

	cout << year;
	return 0;
}