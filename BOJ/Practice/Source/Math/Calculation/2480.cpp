#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int dice[3];
    cin >> dice[0] >> dice[1] >> dice[2];

    if (dice[0] == dice[1] && dice[1] == dice[2])
        cout << 10000 + dice[0] * 1000;
    else if (dice[0] == dice[1] || dice[1] == dice[2])
        cout << 1000 + dice[1] * 100;
    else if (dice[0] == dice[2])
        cout << 1000 + dice[0] * 100;
    else
    {
        int max = (dice[0] > dice[1]) ? dice[0] : dice[1];
        max = (dice[2] > max) ? dice[2] : max;
        cout << max * 100;
    }

    return 0;
}