#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int cnt[201] = {0,};
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int input;
        cin >> input;
        cnt[input + 100]++;
    }
    int wanted;
    cin >> wanted;
    cout << cnt[wanted + 100];
    return 0;
}