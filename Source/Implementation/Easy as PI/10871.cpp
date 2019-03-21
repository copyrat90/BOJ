#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count, x;
	cin >> count >> x;

	int * nArray = new int[count];

	for (int i = 0; i < count; i++)
	{
		cin >> nArray[i];
	}
	for (int i = 0; i < count; i++)
	{
		if (nArray[i] < x)
			cout << nArray[i] << ' ';
	}
    delete[] nArray;
}