#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);


int main(void)
{
	FAST_IO;

	int dna_cnt, str_len;
	cin >> dna_cnt >> str_len;

	vector<string> dna_strs;
	for (int i = 0; i < dna_cnt; ++i)
	{
		string input;
		cin >> input;
		dna_strs.push_back(input);
	}

	string answer_str;
	int hamming_distance = 0;
	for (int i = 0; i < str_len; ++i)
	{
		int A_cnt = 0, C_cnt=0, G_cnt=0, T_cnt=0;
		for (int j = 0; j < dna_cnt; ++j)
		{
			switch (dna_strs[j][i])
			{
			case 'A': ++A_cnt; break;
			case 'C': ++C_cnt; break;
			case 'G': ++G_cnt; break;
			case 'T': ++T_cnt; break;
			}
		}

		int max_cnt = max(max(A_cnt, C_cnt), max(G_cnt, T_cnt));
		hamming_distance += dna_cnt - max_cnt;
		if (max_cnt == A_cnt)
			answer_str += "A";
		else if (max_cnt == C_cnt)
			answer_str += "C";
		else if (max_cnt == G_cnt)
			answer_str += "G";
		else // max_cnt == T_cnt
			answer_str += "T";
	}

	cout << answer_str << '\n' << hamming_distance;
	return 0;
}