#include <iostream>
#include <algorithm>
using namespace std;

enum COLOR { NO_COLOR, R, G, B };

constexpr int INF = 987'654'321;
int n;
int house_cost[4][1002];
int memo[4][1002];

int cost(int color, int idx)
{
	if (idx == n)
		return house_cost[color][idx];
	if (memo[color][idx] != 0)
		return memo[color][idx];
	int next_min_cost = INF;
	if (color != R)
		next_min_cost = min(next_min_cost, cost(R, idx + 1));
	if (color != G)
		next_min_cost = min(next_min_cost, cost(G, idx + 1));
	if (color != B)
		next_min_cost = min(next_min_cost, cost(B, idx + 1));

	int min_cost = house_cost[color][idx] + next_min_cost;
	memo[color][idx] = min_cost;
	return min_cost;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> house_cost[R][i] >> house_cost[G][i] >> house_cost[B][i];
	}	
	cout << cost(NO_COLOR, 0);
	return 0;
}