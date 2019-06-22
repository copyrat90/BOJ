#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 100'001;
// 0번 인덱스는 사용하지 않음
int wanted_mate[MAX];
bool visit[MAX];
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
            if (!visit[i])
            {
                stack<int> st_idx;
                // 방문 체크 후 다음 학생을 스택에 넣고
                // 이미 방문한 학생 나올 때까지 따라감.
                visit[i] = true;
                st_idx.push(i);

                while (!visit[wanted_mate[st_idx.top()]])
                {
                    visit[wanted_mate[st_idx.top()]] = true;
                    st_idx.push(wanted_mate[st_idx.top()]);
                }
                // 이미 방문한 학생은 순환의 시작점일 수 있으므로
                // 스택을 pop() 하며 그 학생이 다시 나오는지,
                // 즉 순환의 시작점인지를 검증
                queue<int> possible_team;
                int possible_loop_start_idx = wanted_mate[st_idx.top()];
                possible_team.push(possible_loop_start_idx);
                bool is_loop = false;
                while (!st_idx.empty())
                {
                    if (possible_loop_start_idx == st_idx.top())
                    {
                        is_loop = true;
                        break;
                    }
                    possible_team.push(st_idx.top());
                    st_idx.pop();
                }
                // 순환이 맞으면 순환하는 학생들은 팀이 있다고 체크
                if (is_loop)
                {
                    while (!possible_team.empty())
                    {
                        has_team[possible_team.front()] = true;
                        possible_team.pop();
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += has_team[i];
        cout << n - cnt << '\n';

        fill(wanted_mate, wanted_mate + MAX, 0);
        fill(visit, visit + MAX, false);
        fill(has_team, has_team + MAX, false);
    }

    return 0;
}