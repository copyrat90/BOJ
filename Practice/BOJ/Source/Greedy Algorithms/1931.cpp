#include <cstdio>
#include <algorithm>
using namespace std;

#include <vector>

struct Meeting
{
	int start_time;
	int end_time;

	bool operator <(const Meeting& other)
	{
		if (this->end_time != other.end_time)
			return (this->end_time < other.end_time);
		else
			return (this->start_time < other.start_time);
	}
};

int main(void)
{
	int N;
	scanf("%d", &N);

	vector<Meeting> meeting_list(N);
	for (Meeting& meeting : meeting_list)
	{
		scanf("%d %d", &meeting.start_time, &meeting.end_time);
	}

	sort(meeting_list.begin(), meeting_list.end());

	int answer_cnt = 1;
	Meeting & first_meeting = meeting_list[0];
	int last_end_time = first_meeting.end_time;
	
	for (int i = 1; i < N; ++i)
	{
		if (last_end_time <= meeting_list[i].start_time)
		{
			++answer_cnt;
			last_end_time = meeting_list[i].end_time;
		}
	}

	printf("%d", answer_cnt);

	return 0;
}