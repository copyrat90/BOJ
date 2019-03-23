#include <bits/stdc++.h>

using namespace std;

// 자세한 풀이 설명
// https://copyrat90.blogspot.com/2019/03/boj-2504.html

int main(void)
{
    stack<char> st_bracket;
    stack<int> st_value;
    bool is_valid = true;

    string input;
    cin >> input;

    st_value.push(0);
    for (char ch : input)
    {
        if (ch == '(' || ch == '[')
        {
            st_bracket.push(ch);
            st_value.push(0);
        }
        // 괄호열이 잘못되었으면 break
        else if (st_bracket.empty() ||
                ch == ')' && st_bracket.top() != '(' ||
                ch == ']' && st_bracket.top() != '[')
        {
            is_valid = false;
            break;
        }
        else
        {
            int closed_val, open_val;
            // ')' == 2 ,   ']' == 3
            int multiplier = (ch == ')') ? 2 : 3;
            st_bracket.pop();
            // top == 0 이면 괄호 안에 아무것도 안 들었으니 2 or 3
            if (st_value.top() == 0)
                closed_val = multiplier;
            // 그렇지 않으면 괄호 안에 든 값(top)과 2 or 3 을 곱한다.
            else
                closed_val = st_value.top() * multiplier;
            st_value.pop();
            // 바깥 괄호에 있던 값과 더해준다.
            open_val = st_value.top() + closed_val;
            st_value.pop();
            st_value.push(open_val);
        }
    }

    if (is_valid && st_bracket.empty())
        cout << st_value.top();
    else
        cout << 0;

    return 0;
}