#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
    char input;
    cin >> input;
 
    if (input == 'C')
        cout << 'G';
    else if (input == 'A')
        cout << 'T';
    else if (input == 'T')
        cout << 'A';
    else
        cout << 'C';
    return 0;
}