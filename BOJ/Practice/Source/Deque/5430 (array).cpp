#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int T;
    scanf("%d%*c", &T);
    while (T--)
    {
        char func[100'001];
        int arr[100'000];

        // 입력
        fgets(func, sizeof(func), stdin);
        int num_cnt;
        scanf("%d%*c", &num_cnt);
        scanf("[");
        for (int i = 0; i < num_cnt; i++)
        {
            scanf("%d", arr + i);
            if (i == num_cnt - 1)
                break;
            scanf(",");
        }
        scanf("]%*c");

        // 계산
        int front = 0;
        int rear = num_cnt;
        bool reversed = false;
        bool error = false;
        for (int i = 0; i < strlen(func); i++)
        {
            if (func[i] == 'R')
                reversed = !reversed;
            else if (func[i] == 'D')
                if (front == rear)
                {
                    error = true;
                    break;
                }
                else if (reversed)
                    rear--;
                else
                    front++;
        }

        // 출력
        if (error)
            printf("error");
        else
        {
            putchar('[');
            if (reversed)
            {
                for (int i = rear - 1; i >= front; i--)
                {
                    printf("%d", arr[i]);
                    if (i == front)
                        break;
                    putchar(',');
                }
            }
            else
            {
                for (int i = front; i < rear; i++)
                {
                    printf("%d", arr[i]);
                    if (i == rear - 1)
                        break;
                    putchar(',');
                }
            }
            putchar(']');
        }
        
        putchar('\n');
    }

}