#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
    string input;
    cin >> input;
 
    int max_len = 0;
 
    for (int i = 0; i < input.length(); i++)
    {
        int len = 0;
        for (int j = i; j < input.length(); j++)
        {
            if (!(input[j] == 'A' || input[j] == 'T' || input[j] == 'G' || input[j] == 'C'))
                break;
            len++;
        }
        max_len = max(len, max_len);
    }
 
    cout << max_len;
    return 0;
}