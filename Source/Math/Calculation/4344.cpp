#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout.setf(ios::fixed);
	cout.precision(3);

	int test_case;

	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int score, sum = 0;
		vector<int> scores;

		int student;
		cin >> student;
		for (int j = 0; j < student; j++)
		{
			cin >> score;
			scores.push_back(score);
			sum += score;
		}
		double ave = (double)sum / student;

		int exceed_ave = 0;
		for (auto score : scores)
			if (score > ave)
				exceed_ave++;

		cout << (double)exceed_ave / student * 100 << "%\n";
	}

	return 0;
}