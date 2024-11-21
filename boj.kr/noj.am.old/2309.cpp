#include "2309.h"

void nojam2309::solution()
{
	int nine[9] = { 0, };
	std::vector<int> l;
	std::vector<int> seven;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &nine[i]);
		l.push_back(1);
	}
	l[0] = 0;
	l[1] = 0;
	std::sort(l.begin(), l.end());

	do {
		sum = 0;
		seven.clear();
		for (int i = 0; i < 9; i++) {
			if (l[i] == 1) {
				sum += nine[i];
				seven.push_back(nine[i]);
			}
		}
		if (sum == 100) {
			std::sort(seven.begin(), seven.end());
			for (int i = 0; i < 7; i++) {
				printf("%d\n", seven[i]);
			}
		}
	} while (std::next_permutation(l.begin(), l.end()));
}
