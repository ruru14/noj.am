#include "1931.h"

void nojam1931::solution()
{
	int n, time = 0;
	scanf("%d", &n);
	std::vector<std::pair<int, int>> schedule;

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		schedule.push_back(std::make_pair(a, b));
	}
}
