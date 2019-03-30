#include <bits/stdc++.h>
using namespace std;

constexpr int BIG = 987654321;

tuple<int, int, int> housing_cost[1000];
map<pair<int,char>,int> memo;
int house_cnt;


// 반환 : [idx, house_cnt) 까지
// idx 를 cur_color 로 색칠했을 때 비용 합의 최솟값
int calc_min_sum(int idx, char cur_color)
{
    // 집 범위 벗어나면 return 0
    if (idx >= house_cnt)
        return 0;
    // 이미 메모이제이션 된 값이 있으면 바로 반환
    if (memo.find({idx, cur_color}) != memo.end())
        return memo[{idx, cur_color}];

    int min_sum = BIG;
    // 색깔별로 (이전 비용 합의 최솟값 + 이번 비용)을 구하고
    // 그 중에 최솟값을 min_sum 에 저장한다.
    int tmp_next_min;
    switch(cur_color)
    {
    case 'R':
        tmp_next_min = min(calc_min_sum(idx + 1, 'G'), calc_min_sum(idx + 1, 'B'));
        min_sum = tmp_next_min + get<0>(housing_cost[idx]);
        break;
    case 'G':
        tmp_next_min = min(calc_min_sum(idx + 1, 'R'), calc_min_sum(idx + 1, 'B'));
        min_sum = tmp_next_min + get<1>(housing_cost[idx]);
        break;
    case 'B':
        tmp_next_min = min(calc_min_sum(idx + 1, 'R'), calc_min_sum(idx + 1, 'G'));
        min_sum = tmp_next_min + get<2>(housing_cost[idx]);
        break;
    }
    
    // map 에 메모이제이션 후 min_sum 반환
    memo.insert(make_pair(make_pair(idx, cur_color), min_sum));
    return min_sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> house_cnt;
    for (int i = 0; i < house_cnt; ++i)
    {
        cin >> get<0>(housing_cost[i]);
        cin >> get<1>(housing_cost[i]);
        cin >> get<2>(housing_cost[i]);
    }

    int min_sum = calc_min_sum(0, 'R');
    min_sum = min(min_sum, calc_min_sum(0, 'G'));
    min_sum = min(min_sum, calc_min_sum(0, 'B'));

    cout << min_sum;
    return 0;
}