#include <cstdio>
#include <algorithm>
using namespace std;

#include <vector>



int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> cost(N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &cost[i]);
	}

	int coin_cnt = 0;
	int remain = K;
	for (int i = N - 1; i >= 0; --i)
	{
		coin_cnt += remain / cost[i];
		remain %= cost[i];
	}

	printf("%d", coin_cnt);

	return 0;
}