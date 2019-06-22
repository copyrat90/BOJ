#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    return (n == 0 || n == 1) ? 1 : n * factorial(n-1);
}

int main()
{
    vector<int> arr;
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i)
        arr.push_back(i);
    bool exist = true;
    do
    {
        for (int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';

	for (int i = 0; i < factorial(n-m) && exist; ++i)
	    exist = next_permutation(arr.begin(), arr.end());
    } while (exist);
    
    return 0;
}