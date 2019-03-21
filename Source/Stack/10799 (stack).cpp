#include <iostream>
#include <stack>
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
    stack<char> st;
    bool last_open;
    int sum = 0;
    for (auto ch : query)
    {
        if (ch == '(')
        {
            st.push(ch);
            last_open = true;
        }
        else
        {
            st.pop();
            if (last_open)
                sum += st.size();
            else
                sum++;
            last_open = false;
        }
    }

    cout << sum;
    return 0;
}