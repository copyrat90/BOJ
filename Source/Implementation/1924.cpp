#include <iostream>
using namespace std;

int main(void)
{
	constexpr int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	constexpr char week_day_str[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	
	int day = 0;
	int month, date;
	cin >> month >> date;

	for (int i = 0; i < month - 1; i++)
	{
		day += month_day[i];
	}
	day += date;

	cout << week_day_str[day % 7];
}