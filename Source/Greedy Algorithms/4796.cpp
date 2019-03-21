#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, P, V;
    int case_cnt = 0;
    while (cin >> L >> P >> V && !(L == 0 && P == 0 && V == 0))
    {
        cout << "Case " << ++case_cnt << ": ";
        // V일 중 P 주기 (V / P) 동안 L일간 사용
        // 남은 (V % P) 일은 L 이하로 사용
        cout << L * (V / P) + min(L, V % P) << '\n';
    }
    return 0;
}