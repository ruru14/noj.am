#include "1759.h"

void nojam1759::solution()
{
	int l, c;
	int cons, vow;
	char alphabet;
	scanf_s("%d %d", &l, &c);

	std::vector<int> list;
	std::vector<int> comb;
	
	for (int i = 0; i < l; i++) {
		comb.push_back(0);
	}

	for (int i = 0; i < c - l; i++) {
		comb.push_back(1);
	}

	std::sort(comb.begin(), comb.end());
	getchar();

	for (int i = 0; i < c; i++) {
		alphabet = getchar();
		list.push_back(alphabet);
		getchar();
	}

	std::sort(list.begin(), list.end());

	do {
		std::vector<int> temp;
		cons = vow = 0;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 0) {
				temp.push_back(list[i]);
				if ((list[i] == 'a') |
					(list[i] == 'e') |
					(list[i] == 'u') |
					(list[i] == 'i') |
					(list[i] == 'o')) {
					vow++;
				}
				else {
					cons++;
				}
			}
		}
		if ((cons > 1) & (vow > 0)) {
			for (int i = 0; i < temp.size(); i++) {
				printf("%c", temp[i]);
			}
			printf("\n");
		}
	} while (std::next_permutation(comb.begin(), comb.end()));
}
