#include "10816.h"

void nojam10816::solution()
{
	int n, m;
	std::map<int, int> card;
	std::map<int, int>::iterator iter;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		card[tmp]++;
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		iter = card.find(tmp);
		if (iter != card.end()) {
			printf("%d ", iter->second);
		}
		else {
			printf("0 ");
		}
	
	}
}
