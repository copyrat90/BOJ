#include <iostream>
using namespace std;


// 3씩 빼며 세다가 5로 나누어 떨어지면 그 몫만큼 추가
int main(void)
{
	int N, cnt = 0;
	cin >> N;

	while (N % 5 != 0 && N > 0)
	{
		N -= 3;
		cnt++;
	}

	if (N < 0)
	{
		cout << -1;
	}
	else
	{
		cnt += N / 5;
		cout << cnt;
	}

	return 0;
}