#include <bits/stdc++.h>
using namespace std;
// #define DBG  // 디버그용

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DBG
    ofstream file("test.txt");
#endif
    bool possible[1000] = {false,};
    fill(possible + 111, possible + 1000, true);
    // 0이 들어갔거나 중복 있는 조합 제거
    for (int i = 111; i < 1000; i++)
    {
        int digit[3];
        int tmp = i;
        for (int j = 0; j < 3; j++)
        {
            digit[j] = tmp % 10;
            // 0이 들어간 조합 제거
            if (digit[j] == 0)
            {
                possible[i] = false;
                goto IMPOSSIBLE;
            }
            // 중복 있는 조합 제거
            for (int k = 0; k < j; k++)
            {
                if (digit[j] == digit[k])
                {
                    possible[i] = false;
                    goto IMPOSSIBLE;
                }
            }
            tmp /= 10;
        }
    IMPOSSIBLE:;
    }

    
    int N;
    cin >> N;
    // 입력받은 조합으로 불가능한 것 제거
    while (N--)
    {
        int guess, strike, ball;
        cin >> guess >> strike >> ball;

        for (int i = 111; i < 1000; i++)
            if (possible[i])
            {
                // digit에 자릿수 잘라 저장
                int digit[3];
                int tmp = i;
                for (int j = 0; j < 3; j++)
                {
                    digit[j] = tmp % 10;
                    tmp /= 10;
                }
                // 이번 조합의 Strike, Ball 계산
                int strike_test = 0, ball_test = 0;
                tmp = guess;
                for (int j = 0; j < 3; j++)
                {
                    int one = tmp % 10;
                    for (int k = 0; k < 3; k++)
                        if (one == digit[k])
                            if (j == k)
                                strike_test++;
                            else
                                ball_test++;

                    tmp /= 10;
                }
                // Strike, Ball 이 틀리면 이번 조합 제거
                if (strike_test != strike || ball_test != ball)
                    possible[i] = false;
            }
    }

    // 가능한 개수 세서 출력
    int cnt = 0;
    for (int i = 111; i < 1000; i++)
    {
        cnt += possible[i];
#ifdef DBG
        file << i << ' ' << possible[i] << '\n';
#endif
    }

    cout << cnt;
    return 0;
}