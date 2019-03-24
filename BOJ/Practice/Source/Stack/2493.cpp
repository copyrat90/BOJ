#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

typedef struct
{
    int idx_0;
    int height;
} RECEIVER;

int receive_pos[500'000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<RECEIVER> possible_receiver;

    int N;  cin >> N;
    RECEIVER receiver{0, };

    for (int i = 0; i < N; i++)
    {
        receiver.idx_0 = i;
        cin >> receiver.height;
        // 현재 탑보다 낮은 탑은 송신 불가능한 탑이니 지움
        // 최초로 발견된 높은 탑의 위치가 송신할 위치
        while (!possible_receiver.empty())
        {
            if (possible_receiver.top().height < receiver.height)
                possible_receiver.pop();
            else
            {
                receive_pos[i] = possible_receiver.top().idx_0 + 1;
                break;
            }
        }
        // 현재 탑을 송신가능한 탑에 추가
        possible_receiver.push(receiver);
    }

    for (int i = 0; i < N; i++)
        cout << receive_pos[i] << ' ';
    return 0;
}