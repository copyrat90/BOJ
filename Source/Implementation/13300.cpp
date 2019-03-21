#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int student_arr[12] = {0};
    int student_num;
    int max;
    cin >> student_num >> max;

    for (int i = 0; i < student_num; i++)
    {
        bool is_boy;
        int room_num;
        cin >> is_boy >> room_num;
        student_arr[is_boy * 6 + room_num - 1]++;
    }

    int room_cnt = 0;
    for (int i = 0; i < 12; i++)
    {
        room_cnt += student_arr[i] / max;
        room_cnt += (student_arr[i] % max != 0);
    }

    cout << room_cnt;
    return 0;
}