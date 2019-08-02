#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;




int main(void)
{
	int max_hole, list_cnt;
	scanf("%d %d", &max_hole, &list_cnt);

	int* gadget_use_order = new int[list_cnt];
	for (int i = 0; i < list_cnt; ++i)
	{
		scanf("%d", gadget_use_order + i);
	}

	// 구멍 개수가 총 사용횟수보다 크거나 같으면 다 꽂아 쓰면 되므로 0번 뽑는다.
	if (max_hole >= list_cnt)
	{
		printf("0");
		return 0;
	}

	set<int> gadget_in_use;
	int unplug_cnt = 0;
	for (int i = 0; i < list_cnt; ++i)
	{
		const int cur_gadget = gadget_use_order[i];
		const bool cur_gadget_already_in_use = gadget_in_use.find(cur_gadget) != gadget_in_use.end();
		
		// 이미 사용중인 가전제품이라면 pass
		if (cur_gadget_already_in_use)
			continue;

		// 새로 플러그 꽂을 가전제품 처리

		// 안 쓰는 구멍이 남아있다면
		if (gadget_in_use.size() < max_hole)
		{
			gadget_in_use.insert(gadget_use_order[i]);
		}
		// 남은 구멍이 없으면
		else
		{
			unplug_cnt++;

			// 사용중인 가전제품 중 가장 나중에 재사용할 가전제품 플러그를 뽑는다.
			set<int> remove_candi(gadget_in_use);
			for (int j = i + 1; j < list_cnt && remove_candi.size() > 1; ++j)
			{
				remove_candi.erase(gadget_use_order[j]);
			}
			const int gadget_removed = *remove_candi.begin();
			gadget_in_use.erase(gadget_removed);

			// 이번 가전제품의 플러그를 꽂는다.
			gadget_in_use.insert(cur_gadget);
		}
	}

	printf("%d", unplug_cnt);
	return 0;
}