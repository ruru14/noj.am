#include "1931.h"

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;

}

void nojam1931::solution()
{
	int n, time = 0, meet = 0;
	scanf("%d", &n);
	std::vector<std::pair<int, int>> schedule;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		schedule.push_back(std::make_pair(b, a));
	}

	std::sort(schedule.begin(), schedule.end());
	meet++;
	time = schedule[0].first;

	for (int i = 1; i < n; i++) {
		if (time <= schedule[i].second) {
			meet++;
			time = schedule[i].first;
		}
	}

	printf("%d", meet);
}
