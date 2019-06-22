#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int call_cnt = 0;
	int y_fee = 0, m_fee = 0;
	
	int input_cnt;
	cin >> input_cnt;
	
	for (int i = 0; i < input_cnt; i++)
	{
		int call_sec;
		cin >> call_sec;
		y_fee += (call_sec / 30 + 1) * 10;
		m_fee += (call_sec / 60 + 1) * 15;
	}
	
	if (y_fee == m_fee)
	{
		cout << "Y M " << y_fee;
	}
	else if (y_fee < m_fee)
	{
		cout << "Y " << y_fee;
	}
	else
	{
		cout << "M " << m_fee;
	}
}