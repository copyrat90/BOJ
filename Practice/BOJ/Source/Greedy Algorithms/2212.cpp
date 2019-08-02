#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

int sensor_coords[10'000];
priority_queue<int> adjacent_sensor_distances;

int main(void)
{
	FAST_IO;

	// (수신 가능 영역 길이 합) = (가장 왼쪽 센서에서 가장 오른쪽 센서까지의 거리) - {삭제된 라인들 거리}
	int answer, total_len, del_lines_len = 0;

	int num_of_sensors, num_of_centers;
	cin >> num_of_sensors >> num_of_centers;

	for (int i = 0; i < num_of_sensors; ++i)
	{
		cin >> sensor_coords[i];
	}

	// 센서보다 기지국이 더 많으면 각 센서 바로 옆에 기지국을 지으면 총 거리는 0 이다.
	// priority_queue 의 정상 작동을 위하여 예외 처리
	if (num_of_sensors <= num_of_centers)
	{
		cout << 0;
		return 0;
	}

	sort(sensor_coords, sensor_coords + num_of_sensors);

	total_len = sensor_coords[num_of_sensors - 1] - sensor_coords[0];

	// 삭제된 라인들 거리 구하기
	for (int i = 0; i < num_of_sensors - 1; ++i)
	{
		adjacent_sensor_distances.push(sensor_coords[i + 1] - sensor_coords[i]);
	}

	// 인접한 센서의 거리의 최댓값을 삭제할 횟수만큼 가져와 삭제한다.
	const int num_of_del_lines = num_of_centers - 1;
	for (int i = 0; i < num_of_del_lines; ++i)
	{
		del_lines_len += adjacent_sensor_distances.top();
		adjacent_sensor_distances.pop();
	}


	// 답 출력
	answer = total_len - del_lines_len;
	cout << answer;

	return 0;
}