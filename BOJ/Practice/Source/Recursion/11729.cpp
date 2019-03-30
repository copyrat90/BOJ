#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> process;

int hanoi(int n, int start = 1, int dest = 3)
{
    // base case
    if (n == 1)
    {
        process.push_back({start, dest});
        return 1;
    }

    int temp_pos = 6 - start - dest;
    int sum = 0;
    sum += hanoi(n-1, start, temp_pos);
    sum += hanoi(1, start, dest);
    sum += hanoi(n-1, temp_pos, dest);
    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  cin >> N;
    process.reserve((1<<N) - 1);
    cout << hanoi(N) << '\n';

    for (auto p : process)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}