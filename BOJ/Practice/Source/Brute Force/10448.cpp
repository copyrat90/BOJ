#include <bits/stdc++.h>
using namespace std;


inline int T(int n)
{
    return n * (n + 1) / 2;
}

// T(44) = 990, T(45) = 1035
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int num;
        cin >> num;

        bool found = false;
        for (int i = 1; i <= 44; i++)
            for (int j = 1; j <= 44; j++)
                for (int k = 1; k <= 44; k++)
                    if (num == T(i) + T(j) + T(k))
                    {
                        found = true;
                        goto FOR_EXIT;
                    }
    FOR_EXIT:
        cout << found << '\n';
    }

    return 0;
}