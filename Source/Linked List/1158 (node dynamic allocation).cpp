#include <bits/stdc++.h>
using namespace std;

typedef struct __PERSON
{
    int num;
    __PERSON * next;
} PERSON;

int main(void)
{
    int N, M;
    cin >> N >> M;

    // 원형 연결 리스트 초기화
    PERSON * curr = nullptr;
    for (int i = N; i >= 1; i--)
    {
        curr = new PERSON{i, curr};
    }
    PERSON * temp = curr;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;

    // M개씩 돌며 조세퍼스 순열 출력
    cout << '<';
    while (true)
    {
        for (int i = 0; i < M - 1; i++)
            curr = curr->next;
        PERSON * prev = curr;
        curr = curr->next;
        cout << curr->num;
        if (prev == curr)
        {
            cout << '>';
            delete curr;
            break;
        }
        else
        {
            cout << ", ";
            prev->next = curr->next;
        }
        delete curr;
        curr = prev;
    }

    return 0;
}