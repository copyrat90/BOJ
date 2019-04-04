#include <bits/stdc++.h>
using namespace std;

int Z(int n, int y, int x)
{
    if (n == 0)
        return 0;
    // Z 모양의 사분면을 나누고
    // (x,y) 가 어느 사분면에 있는지 계산
    int z_quadrant = 1;
    if (y >= (1 << n-1))
        z_quadrant += 2;
    if (x >= (1 << n-1))
        z_quadrant += 1;
    // 지나친 사분면에 있는 점의 개수와
    // 다음 점의 좌표를 계산 
    int passed_points = (z_quadrant - 1) * (1 << 2*(n-1));
    int next_y = y - ((z_quadrant > 2) ? 1 << n-1 : 0);
    int next_x = x - ((z_quadrant % 2 == 0) ? 1 << n-1 : 0);
    // (지나친 사분면에 있는 점의 개수 + 재귀) 반환
    return passed_points + Z(n-1, next_y, next_x);
}

int main(void)
{
    int n, r, c;
    cin >> n >> r >> c;
    cout << Z(n, r, c);
    return 0;
}