#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		for (int j = a; j <= (a+b)/2; j++)
		{
			int temp = arr[j];
			arr[j] = arr[a + b - j];
			arr[a + b - j] = temp;
		}
#ifdef RAT_DBG
		for (auto data : arr)
		{
			cout << data << ' ';
		}
#endif
	}
	for (auto data : arr)
	{
		cout << data << ' ';
	}
	
	return 0;
}