#include "11651.h"

void nojam11651::solution()
{
	int n;
	std::vector<std::pair<int, int>> dict;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		dict.push_back(std::make_pair(tmp1, tmp2));
	}

	std::sort(dict.begin(), dict.end());

	for (int i = 0; i < dict.size(); i++) {
		printf("%d %d\n", dict[i].first, dict[i].second);
	}
}
