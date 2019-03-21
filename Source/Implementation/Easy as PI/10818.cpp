#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int min = 1000001;
    int max = -1000001;
    while (n--)
    {
        int num;
        cin >> num;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    
    cout << min << ' ' << max;
    return 0;
}