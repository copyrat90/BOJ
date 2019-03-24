#include <iostream>
using namespace std;

int main(void)
{
	int size, score, sum = 0, max = -1;
	double fake_ave;

	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> score;
		sum += score;
		if (score > max)
			max = score;
	}

	fake_ave = ((double)sum / max * 100) / size;
	cout << fake_ave;
	return 0;
}