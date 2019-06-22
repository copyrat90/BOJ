#include <bits/stdc++.h>
using namespace std;
//#define RAT_DBG

// 숫자의 개수를 배열에 누산한다.
// 이 때 9가 들어왔는데 (9의개수) > (6의개수) 이면 6을 대신 증가.
// 또한  6이 들어왔는데 (6의개수) > (9의개수) 이면 9를 대신 증가.
int main(void)
{
    int num_cnt[10] = {0,};
    int set_cnt = 1;
    
    int num;
    cin >> num;
    do
    {
        int rem = num % 10;
        if (rem == 9 && num_cnt[6] < num_cnt[9])
            num_cnt[6]++;
        else if (rem == 6 && num_cnt[6] > num_cnt[9])
            num_cnt[9]++;
        else
            num_cnt[rem]++;
        
        num /= 10;
        
    } while (num != 0);

// 배열에 어떻게 누산되는지 보고 싶다면 Line 3의 주석을 해제하세요.
#ifdef RAT_DBG
    for (int i = 0; i < 10; i++)
        cout << i << ' ';
    cout << '\n';
    for (auto data : num_cnt)
        cout << data << ' ';
    cout << '\n';
#endif

    int max = num_cnt[0];
    for (int i = 1; i < 10; i++)
    {
        if (num_cnt[i] > max)
            max = num_cnt[i];
    }
    cout << max;
    return 0;
}