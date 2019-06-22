#include <bits/stdc++.h>
using namespace std;

constexpr int N_MAX = 100'002;
// 안 떼기, 위쪽 떼기, 아래쪽 떼기
enum selection {nothing, upper, lower};
// 입력된 점수
int score[2][N_MAX];
// select 각 경우의 최대 점수 메모
int memo[3][N_MAX];

int n;
// 최대 점수를 계산하는 함수
int calc_max(int select, int idx)
{
    // 마지막 idx 면 선택된 값 그대로 반환
    // 선택된 게 없을 경우 0 반환
    if (idx == n)
        if (select != nothing)
            return score[select - 1][idx];
        else
            return 0;
    int & ret = memo[select][idx];
    // 메모된 값이 있으면 바로 반환
    if (ret != -1)
        return ret;
    
    // 다음 idx 의 max_score 를 구한다.
    int max_score = -1;
    if (select != upper)
        max_score = calc_max(upper, idx + 1);
    if (select != lower)
        max_score = max(max_score, calc_max(lower, idx + 1));
    max_score = max(max_score, calc_max(nothing, idx + 1));
    // 현재 선택한 스티커의 점수를 더한다. (선택이 없으면 0)
    max_score += (select != nothing) ? score[select - 1][idx] : 0;
    // 메모 후 반환한다.
    return (ret = max_score);
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--)
    {
        cin >> n;
        for (int y = 0; y < 3; ++y)
            fill(memo[y], memo[y] + n + 1, -1);

        for (int y = 0; y < 2; ++y)
            for (int x = 1; x <= n; ++x)
                cin >> score[y][x];

        cout << calc_max(nothing, 0) << '\n';
    }

    return 0;
}