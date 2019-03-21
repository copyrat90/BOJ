#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[20];

int recursive(int cur_sum = 0, int cur_idx = 0, bool has_val = false)
{
    if (cur_idx == N - 1)
    {
	    return (cur_sum + arr[cur_idx] == S)
		    + (has_val && (cur_sum == S));
    }

    return recursive(cur_sum, cur_idx + 1, has_val)
        + recursive(cur_sum + arr[cur_idx], cur_idx + 1, true);
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << recursive();
    return 0;
}