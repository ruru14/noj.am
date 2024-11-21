#include "15650.h"

void nojam15650::solution()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<int> arr;
	std::vector<int> comb;

	for (int i = 1; i < n + 1; i++) {
		arr.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		comb.push_back(0);
	}
	for (int i = 0; i < n - m; i++) {
		comb.push_back(1);
	}

	std::sort(comb.begin(), comb.end());

	do {
		for (int i = 0; i < n; i++) {
			if (comb[i] == 0) {
				printf("%d ", arr[i]);
			}
		}
		printf("\n");
	} while (std::next_permutation(comb.begin(), comb.end()));

}
