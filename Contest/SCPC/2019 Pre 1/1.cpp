#include <iostream>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

// 제출 시 주석처리 필수 !!!
//#define FILE_TEST

#ifdef FILE_TEST
#include <time.h>
#endif

constexpr int MAX = 1'000'004;
// 각 작업 횟수
int memo[MAX];
// 작업 횟수의 1부터의 누산
int accum_memo[MAX];

int n1, n2;


int work_count(int n)
{
	//  0. 이미 계산된 답이 있으면 그 답을 반환
	if (memo[n] != -1)
		return memo[n];

	//  1. 만약 수가 1 이면 작업 횟수는 0회
	if (n == 1)
		return 0;
	//  2. 만약 수가 1 이 아닌 홀수이면 1 을 더한다.
	if (n % 2 == 1)
	{
		memo[n] = 1 + work_count(n + 1);
		return memo[n];
	}
	//  3. 만약 수가 짝수이면 2 로 나눈다.
	else
	{
		memo[n] = 1 + work_count(n / 2);
		return memo[n];
	}
}


int main(void)
{
#ifdef FILE_TEST
	clock_t begin, end;
	begin = clock();

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#ifndef FILE_TEST
	FAST_IO;
#endif

	fill(memo, memo + MAX, -1);
	memo[1] = 0;

	int T;
	cin >> T;

	// 누산 배열을 미리 전부 채운다.
	accum_memo[0] = 0;
	int accum = 0;
	for (int i = 1;i < MAX;++i)
	{
		accum += work_count(i);
		accum_memo[i] = accum;
	}

	for (int i = 1; i <= T; ++i)
	{
		cin >> n1 >> n2;

		int sum = accum_memo[n2] - accum_memo[n1-1];

		cout << "Case #" << i << '\n';
		cout << sum << '\n';
	}

#ifdef FILE_TEST
	end = clock();
	cout << "수행 시간 : " << (end - begin) << " ms" << '\n';
#endif
	return 0;
}