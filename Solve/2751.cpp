#include "2751.h"

void nojam2751::solution()
{
	int n;
	std::vector<int> dict;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		dict.push_back(tmp);
	}

	std::sort(dict.begin(), dict.end());

	for (int i = 0; i < dict.size(); i++) {
		printf("%d\n", dict[i]);
	}
}
