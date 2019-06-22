#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	// 피연산자 입력 받음
	// HI IM HIM
	string operands[3];
	for (int i = 0; i < 3; ++i)
		cin >> operands[i];

	// set 으로 문자 중복을 걸러냄
	// {'H', 'I', 'M'}
	set<char> char_set;
	for (int i = 0; i < 3; ++i)
		for (char ch : operands[i])
			char_set.insert(ch);

	// 중복 없는 문자 벡터 생성
	// v[0]='H', v[1]='I', v[2]='M'
	const vector<char> char_vector(char_set.begin(), char_set.end());

	// 선택 순서를 저장할 select 배열 선언
	// 0 1 2 3 4 5 6 7 8 9    idx
	// x x x x x x x 0 1 2    select[idx] (x == -1)
	//               H I M    char_vector[select[idx]]
	// 이 경우 H=7, I=8, M=9 로 매핑됨. select 넥퍼뮤 돌리면 모든 조합.
	int select[10];
	fill(select, select + 10, -1);
	for (int i = 10 - char_vector.size(), cnt = 0; i < 10; ++i, ++cnt)
		select[i] = cnt;

	do
	{
		// 피연산자 복사 (원본 보존)
		string copy_op[3];
		for (int i = 0; i < 3; ++i)
			copy_op[i] = operands[i];

		long long ll_operands[3];
		for (int i = 0; i < 3; ++i)
		{
			// char_vector[select[j]] 에 대응되는 문자를 'j' 로 치환.
			// 예를 들어 "HI" 면 "78" 로 치환됨.
			for (int j = 0; j < 10; ++j)
				if (select[j] != -1)
					replace(copy_op[i].begin(), copy_op[i].end(), char_vector[select[j]], (char)('0' + j));
			// 다 치환됐으면 int 로 파싱
			ll_operands[i] = stoll(copy_op[i]);
		}
		// a + b = c 가 성립하면 YES 출력 후 종료
		if (ll_operands[0] + ll_operands[1] == ll_operands[2])
		{
			cout << "YES";
			return 0;
		}
	} while (next_permutation(select, select + 10)); // 다음 치환 조합으로!

	// 끝까지 안 나오면 답이 없는 것이니 NO 출력 후 종료
	cout << "NO";
	return 0;
}