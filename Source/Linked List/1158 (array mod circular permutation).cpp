#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> circle(N);
    for (int i = 1; i <= N; i++)
    {
        circle.at(i - 1) = i;
    }

    int curr = -1;
    cout << '<';
    while (circle.size())
    {
        curr += M;
        // 배열 나머지 연산 -> 원순열
        curr %= circle.size();
        cout << circle.at(curr);
        circle.erase(circle.begin() + curr--);
        if (circle.size() == 0)
            break;
        cout << ", ";
    }
    cout << '>';
    return 0;
}