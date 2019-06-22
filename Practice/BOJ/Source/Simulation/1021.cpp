#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    deque<int> dq_l;
    deque<int> dq_r;
    for (int i = 1; i <= N; i++)
    {
        dq_l.push_back(i);
        dq_r.push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        int wanted;  cin >> wanted;
        int left = 0, right = 0;
        while (dq_l.front() != wanted)
        {
            int tmp = dq_l.front();
            dq_l.pop_front();
            dq_l.push_back(tmp);
            left++;
        }
        while (dq_r.front() != wanted)
        {
            int tmp = dq_r.back();
            dq_r.pop_back();
            dq_r.push_front(tmp);
            right++;
        }
        dq_l.pop_front();
        dq_r.pop_front();
        
        cnt += (left < right) ? left : right;
    }

    cout << cnt;
    return 0;
}