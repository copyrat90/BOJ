#include <iostream>
using namespace std;

// 닫는 괄호를 만났을 때, 직전 괄호가 :
// 1. 여는 괄호였다면 그건 레이저 == (열린 괄호 - 1) 개의 조각 추가
// 2. 닫는 괄호였다면 그건 막대기 끝 == 1개의 조각 추가

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string query;
    cin >> query;
    char last_ch;
    int opened = 0;
    int sum = 0;
    for (auto ch : query)
    {
        switch(ch)
        {
        case '(':
            opened++;
            break;
        case ')':
            opened--;
            if (last_ch == '(')
                sum += opened;
            else
                sum++;
            break;
        }

        last_ch = ch;
    }

    cout << sum;
    return 0;
}