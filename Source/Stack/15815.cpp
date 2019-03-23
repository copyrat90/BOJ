#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    stack<int> st_num;
    string input;   cin >> input;
    for (char ch : input)
    {
        if ('0' <= ch && ch <= '9')
            st_num.push(ch - '0');
        else    // ch == +, -, *, /
        {
            int operand2 = st_num.top();
            st_num.pop();
            int operand1 = st_num.top();
            st_num.pop();
            switch(ch)
            {
            case '+':  st_num.push(operand1 + operand2);  break;
            case '-':  st_num.push(operand1 - operand2);  break;
            case '*':  st_num.push(operand1 * operand2);  break;
            case '/':  st_num.push(operand1 / operand2);  break;
            }
        }
    }

    cout << st_num.top();
    return 0;
}