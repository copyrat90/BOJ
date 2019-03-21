#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	constexpr int len = 3;
	int nArray[len];
	for (auto& n : nArray)
		cin >> n;

	sort(nArray, nArray + len);
	cout << nArray[len - 2];

	return 0;
}