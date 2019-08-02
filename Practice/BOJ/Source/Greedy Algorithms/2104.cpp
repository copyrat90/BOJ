#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

constexpr ll INF = ((unsigned ll)-1ll >> 1);

int N;
ll A[100'003];


// 부분배열의 최댓값을 구하는 함수
// 범위 : [s, e)
ll calc_max_score(int s, int e)
{
	// base case
	if (s == e) return 0;
	if (s == e-1) return A[s];
	
	// recursive case
	
	// 왼쪽 영역, 오른쪽 영역의 최댓값
	const int mid = (s+e)/2;
	ll max_score = max(calc_max_score(s, mid), calc_max_score(mid, e));
	
	// 양단 걸친 영역의 최댓값까지 계산
	int l = mid, r = mid + 1;
	ll sum_part = 0, min_part = INF;
	while (l >= s || r < e)
	{
		ll l_score = l < s ? -1 : (sum_part + A[l]) * min(min_part, A[l]);
		ll r_score = r >= e ? -1 : (sum_part + A[r]) * min(min_part, A[r]);
		
		if (l_score >= r_score)
		{
			sum_part += A[l];
			min_part = min(min_part, A[l]);
			max_score = max(max_score, sum_part * min_part);
			--l;
		}
		else
		{
			sum_part += A[r];
			min_part = min(min_part, A[r]);
			max_score = max(max_score, sum_part * min_part);
			++r;
		}
	}
	
	return max_score;
}

int main(void)
{
	FAST_IO;
	
	cin >> N;
	for (int i=0;i<N;++i)
	{
		cin >> A[i];
	}

	cout << calc_max_score(0, N);
	return 0;
}