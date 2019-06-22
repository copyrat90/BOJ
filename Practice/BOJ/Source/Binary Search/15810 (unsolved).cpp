#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

int main(void)
{
	FAST_IO;
	vector<ll> staff_time;
	ll staff, needed_balloon;
	cin >> staff >> needed_balloon;
	staff_time.resize(staff);
	for (int i = 0;i < staff;++i)
		cin >> staff_time[i];
	// binary search (how many second?)
	ll front = 0;
	ll rear = 1e12;
	ll cur_balloon;
	while (front <= rear)
	{
		ll mid = (front + rear) / 2;
		cur_balloon = 0;
		for (int i = 0;i < staff;++i)
		{
			cur_balloon += mid / staff_time[i];
		}
		if (cur_balloon < needed_balloon)
			front = mid + 1;
		else if (cur_balloon > needed_balloon)
			rear = mid - 1;
		else
			break;
	}

	ll time = front;
	// lower bound
	if (cur_balloon >= needed_balloon)
	{
		while (true)
		{
			cur_balloon = 0;
			for (int i = 0;i < staff;++i)
			{
				cur_balloon += (time - 1) / staff_time[i];
			}
			if (cur_balloon < needed_balloon)
			{
				cout << time;
				return 0;
			}
			--time;
		}
	}
	else // cur_balloon < needed_balloon
	{
		while (true)
		{
			cur_balloon = 0;
			++time;
			for (int i = 0;i < staff;++i)
			{
				cur_balloon += time / staff_time[i];
			}
			if (cur_balloon >= needed_balloon)
			{
				cout << time;
				return 0;
			}
		}
	}
}