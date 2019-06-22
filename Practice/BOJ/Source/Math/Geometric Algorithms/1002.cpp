#include <bits/stdc++.h>
using namespace std;

inline void swap(int & n1, int & n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, r1, x2, y2, r2;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        if (r2 > r1)
            swap(r1, r2);

        if (d < 1e-12)
        {
            if (r1 == r2)
                cout << -1;
            else
                cout << 0;
        }
        else if (r1+r2==d || r1-r2==d)
        {
            cout << 1;
        }
        else if (r1+r2<d || r1-r2>d)
        {
            cout << 0;
        }
        else // r1-r2 < d < r1+r2
        {
            cout << 2;
        }
        cout << '\n';
    }

    return 0;
}