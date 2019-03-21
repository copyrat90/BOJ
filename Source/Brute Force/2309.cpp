#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int num = 9;
    int height[num];
    int everyone_sum = 0;
    int fake_two_sum = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> height[i];
        everyone_sum += height[i];
    }
    fake_two_sum = everyone_sum - 100;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (height[i] + height[j] == fake_two_sum)
            {
                height[i] = height[j] = 666;
                goto NESTED_LOOP_EXIT;
            }
        }
    }
    NESTED_LOOP_EXIT:
    sort(height, height + num);
    for (int i = 0; i < num - 2; i++)
    {
        cout << height[i] << '\n';
    }
}