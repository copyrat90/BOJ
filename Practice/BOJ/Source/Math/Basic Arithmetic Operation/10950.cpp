#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    int a, b;
    
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    
    return 0;
}