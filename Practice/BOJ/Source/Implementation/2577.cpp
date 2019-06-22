#include <iostream>
using namespace std;


int main(void)
{
	int a, b, c, num;
	cin >> a >> b >> c;
	num = a * b * c;

	int nArr[10] = { 0 };

	while (num > 0)
	{
		nArr[num % 10]++;
		num /= 10;
	}
	for (auto num : nArr)
		cout << num << '\n';
}