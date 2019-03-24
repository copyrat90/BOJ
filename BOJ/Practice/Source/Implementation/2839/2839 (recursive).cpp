// 재귀적인(Recursive) 풀이법

#include <iostream>
using namespace std;



// answer() : 재귀함수(Recursive Function)

// 남은 무게(remain)가 5보다 크고 직전 무게(kg)가 3kg 이 아니면 5kg 을 빼고 재귀호출
// 남은 무게가 3이상 5미만이면 3kg 을 빼고 재귀호출
// 호출마다 현재까지의 봉지 수(count)를 1씩 올리다 remain == 0 이 되면 count 반환
// remain 이 1~2면 불가능한 경우이므로 이전 무게(kg)가 틀린 것이므로 -1 반환
// 5kg 시도에서 -1 이 반환되면 3kg 으로 재시도 후 결과 반환

// 반환 : (양수) 설탕 봉지 개수 / (음수) 불가능한 경우 -1
// 인수 : remain = 남은 무게, count = 현재까지 봉지 수, kg = 직전 봉지 무게
int answer(int remain, int count = 0, int kg = 0)
{
	int ret;

	if (remain == 0)
	{
		return count;
	}

	if (remain >= 5 && kg != 3)
	{
		ret = answer(remain - 5, count + 1, 5);
		if (ret > 0)
		{
			return ret;
		}
		else
		{
			return answer(remain - 3, count + 1, 3);
		}
	}
	else if (remain >= 3)
	{
		return answer(remain - 3, count + 1, 3);
	}
	else
	{
		return -1;
	}
}


int main(void)
{
	int N;
	cin >> N;

	cout << answer(N);
	return 0;
}