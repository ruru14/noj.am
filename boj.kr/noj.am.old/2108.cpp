#include "2108.h"

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

void nojam2108::solution()
{
	int n, sum = 0, min = 4000, max = -4000;
	scanf("%d", &n);
	int* count = new int[8001];
	std::fill_n(count, 8001, 0);
	std::vector<int> sta;
	std::vector<std::pair<int, int>> mode;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sta.push_back(tmp);
		sum += tmp;
		if (max < tmp)
			max = tmp;
		if (min > tmp)
			min = tmp;
		count[tmp + 4000]++;
	}
	
	for (int i = 0; i < 8001; i++) {
		if (count[i] == 0)
			continue;
		mode.push_back(std::make_pair(count[i], i - 4000));
	}

	std::sort(mode.begin(), mode.end(), compare);
	std::sort(sta.begin(), sta.end());


	printf("%d\n", (int)round(((double)sum / (double)n)));
	printf("%d\n", sta[(n - 1) / 2]);
	if (n == 1) {
		printf("%d\n", mode[0].second);
	}
	else {
		printf("%d\n", mode[0].first == mode[1].first ? mode[1].second : mode[0].second);
	}
	printf("%d", max - min);
}
