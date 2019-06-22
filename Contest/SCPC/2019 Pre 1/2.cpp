#include <iostream>
#include <algorithm>
#include <cmath>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

// 제출 시 주석처리 필수 !!!
//#define TEST

#ifdef TEST
#include <time.h>
#endif

constexpr double PI = 3.14159265358979323846;


int main(void)
{
#ifdef TEST
	clock_t begin, end;
	begin = clock();
	
	// 제출 시 주석처리 필수 !!!
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#ifndef TEST
	FAST_IO;
#endif

	cout << fixed;
	cout.precision(15);
	
	int T;	cin >> T;
	for (int i = 1;i <= T;++i)
	{
		// 반지름, 시작지점, 도착지점 입력
		double R, S, E;
		cin >> R >> S >> E;
		// 최초 거리 계산
		double distance = E - S;
		// 각 장애물마다 거리 가감
		int N;	cin >> N;
		while (N--)
		{
			double l, r, h;
			cin >> l >> r >> h;
			if (h >= R)
			{
				distance += 2 * (h - R) + PI * R - 2 * R;
			}
			else
			{
				distance += (-2) * sqrt(R * R - (R - h) * (R - h)) + 2 * R * (PI / 2 - asin((R - h) / R));
			}
		}

		cout << "Case #" << i << '\n';
		cout << distance << '\n';
	}
	

#ifdef TEST
	end = clock();
	cout << "수행 시간 : " << (end - begin) << " ms" << '\n';
#endif
	return 0;
}