#include <cstdio>
#include <algorithm>

constexpr int MAX = 1005;
bool need_fix[MAX];

int main(void)
{
	int N, L;
	scanf("%d %d", &N, &L);

	// 수리가 필요한 위치 입력
	for (int i = 0; i < N; ++i)
	{
		int idx;
		scanf("%d", &idx);
		need_fix[idx] = true;
	}

	// Greedy
	// 가장 왼쪽부터 수리할 위치를 찾아 테이프 길이만큼 수리한 다음 찾는 걸 반복
	int cnt = 0;
	for (int i = 1; i < MAX; ++i)
	{
		if (need_fix[i])
		{
			++cnt;
			for (int j = i; j < i + L; ++j)
			{
				need_fix[j] = false;
			}
			i += L - 1;
		}
	}

	printf("%d", cnt);

	return 0;
}