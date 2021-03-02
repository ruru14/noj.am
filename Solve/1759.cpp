#include "1759.h"

void nojam1759::solution()
{
	int l, c;
	scanf_s("%d %d", &l, &c);

	std::vector<int> list;
	std::vector<int> comb;
	
	for (int i = 0; i < l; i++) {
		comb.push_back(1);
	}

	for (int i = 0; i < c - l; i++) {
		comb.push_back(0);
	}

	std::sort(comb.begin(), comb.end());

	for (int i = 0; i < c; i++) {
		char alphabet;
		scanf_s("%c", &alphabet);
		list.push_back(alphabet);
	}

	for (int i = 0; i < list.size(); i++) {
		printf("%d ", list[i]);
	}
}
