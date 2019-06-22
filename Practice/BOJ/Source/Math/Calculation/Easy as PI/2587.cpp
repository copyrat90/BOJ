#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    constexpr int odd_len = 5;
    int arr[odd_len];
    int sum = 0;

    for (int i = 0; i < odd_len; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + odd_len);

    cout << sum / odd_len << '\n' << arr[odd_len / 2];
    return 0;
}