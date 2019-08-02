#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



struct Lecture
{
	int start_time;
	int end_time;

	bool operator < (const Lecture& other) const
	{
		if (this->start_time != other.start_time)
			return this->start_time < other.start_time;
		return this->end_time < other.end_time;
	}
};


int main(void)
{
	int N;
	scanf("%d", &N);
	vector<Lecture> lectures(N);
	for (Lecture& lec : lectures)
	{
		scanf("%d %d", &lec.start_time, &lec.end_time);
	}

	// 시작 시간이 빠른 순으로 정렬 (operator <)
	sort(lectures.begin(), lectures.end());

	priority_queue<int, vector<int>, greater<int>> end_time_min_heap;
	end_time_min_heap.push(lectures[0].end_time);
	
	// 사용이 끝난 강의실에 다음 시작하는 수업을 넣고,
	// 빈 강의실이 없는 경우 강의실을 하나 늘린다.
	for (int i = 1; i < lectures.size(); ++i)
	{
		if (end_time_min_heap.top() <= lectures[i].start_time)
		{
			end_time_min_heap.pop();
			end_time_min_heap.push(lectures[i].end_time);
		}
		else
		{
			end_time_min_heap.push(lectures[i].end_time);
		}
	}
	
	// 강의실의 개수를 출력
	printf("%d", end_time_min_heap.size());
	return 0;
}