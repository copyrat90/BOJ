#include <bits/stdc++.h>
using namespace std;

long long memo[31][31];

// 서로 다른 약 먹는 방법
long long dfs(long long w, long long h)
{
    // 한 조각이 없으면 경우의 수는 1
    if (w == 0)
        return 1;
    // 이전에 계산해놓은 값이 있으면 반환
    if (memo[w][h] != 0)
        return memo[w][h];
    
    long long sum = 0;
    if (w > 0)  // 한 조각을 반으로 잘라먹는 경우의 수
        sum += dfs(w - 1, h + 1);
    if (h > 0)  // 남은 반 조각을 먹는 경우의 수
        sum += dfs(w, h - 1);
    
    memo[w][h] = sum;
    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    while (cin >> N && N != 0)
        cout << dfs(N, 0) << '\n';
    return 0;
}