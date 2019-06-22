#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 100'001;
// 0번 인덱스는 사용하지 않음
int wanted_mate[MAX];
int visit[MAX];
bool has_team[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--)
    {
        // 원하는 팀원 입력
        int n;  cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> wanted_mate[i];
        for (int i = 1; i <= n; i++)
        {
            // 만약 방문한 적이 없는 학생이면
            if (visit[i] == 0)
            {
                // i번째에 방문했다고 체크 후
                // 이미 방문한 학생 나올 때까지 따라감.
                visit[i] = i;
                int next_idx = wanted_mate[i];
                while (visit[next_idx] == 0)
                {
                    visit[next_idx] = i;
                    next_idx = wanted_mate[next_idx];
                }
                // 이번 for 루프(i번째)에 다시 나온 학생은 순환 시작점
                // 그 학생을 따라 돌며 모두 팀이 있다고 체크
                if (visit[next_idx] != i)
                    continue;
                int loop_start_idx = next_idx;
                has_team[loop_start_idx] = true;
                next_idx = wanted_mate[next_idx];
                while (loop_start_idx != next_idx)
                {
                    has_team[next_idx] = true;
                    next_idx = wanted_mate[next_idx];
                }
                // 방문했는데 팀 체크가 안 된 학생은 팀이 없는 것.
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += has_team[i];
        cout << n - cnt << '\n';

        fill(wanted_mate, wanted_mate + MAX, 0);
        fill(visit, visit + MAX, 0);
        fill(has_team, has_team + MAX, false);
    }

    return 0;
}