#include <iostream>
using namespace std;


// 10이 넘어가면 5(2n) + a 이므로
// 일의 자리 수 a 만 맞도록 3을 분배해 계산
int main(void)
{
	int N;
	cin >> N;

	if (N == 4 || N == 7)
		cout << -1;
	else if (N % 5 == 1)
		cout << 2 + (N - 6) / 5;
	else if (N % 5 == 2)
		cout << 4 + (N - 12) / 5;
	else if (N % 5 == 3)
		cout << 1 + (N - 3) / 5;
	else if (N % 5 == 4)
		cout << 3 + (N - 9) / 5;
	else
		cout << N / 5;

	return 0;
}