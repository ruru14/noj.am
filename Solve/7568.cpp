#include "7568.h"

void nojam7568::solution()
{
	int n;
	scanf("%d", &n);
	std::vector<std::pair<int, int>> info;
	std::vector<int> rank(n);

	for (int i = 0; i < n; i++) {
		int weight, height;
		scanf("%d %d", &weight, &height);
		info.push_back(std::make_pair(weight, height));
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (info[i].first < info[j].first &
				info[i].second < info[j].second) {
				rank[i]++;
			}
			else if (info[i].first > info[j].first &
				info[i].second > info[j].second) {
				rank[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", rank[i] + 1);
	}
}
