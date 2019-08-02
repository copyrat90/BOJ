#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;



int main(void)
{
	int N;
	scanf("%d", &N);

	int* rope_weights = new int[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", rope_weights + i);
	}

	sort(rope_weights, rope_weights + N, greater<int>());

	int max_lift_weight = rope_weights[0];
	for (int i = 1; i < N; ++i)
	{
		const int rope_cnt = i + 1;
		max_lift_weight = max(max_lift_weight, rope_weights[i] * rope_cnt);
	}

	printf("%d", max_lift_weight);


	delete[] rope_weights;
	return 0;
}