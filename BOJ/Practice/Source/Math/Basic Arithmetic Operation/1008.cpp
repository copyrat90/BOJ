#include <iostream>
using namespace std;

int main(void)
{
    double a, b;
    cin >> a >> b;
    // 가장 큰 자리수부터 15자리를 출력
    // 바로 다음 출력에만 적용됨.
    cout.precision(15);
    cout << a / b;
    return 0;
}