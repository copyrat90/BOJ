#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int alphabet[26];
    fill(alphabet, alphabet + 26, -1);
    char sz[101];
    cin >> sz;

    for (int i = 0; i < strlen(sz); i++)
    {
        if (alphabet[sz[i] - 'a'] == -1)
            alphabet[sz[i] - 'a'] = i;
    }
    for (auto num : alphabet)
    {
        cout << num << ' ';
    }
    return 0;
}