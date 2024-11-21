#include "2164.h"

void nojam2164::solution()
{
	int n;
	scanf("%d", &n);
	std::queue<int> cards;

	for (int i = 1; i < n + 1; i++) {
		cards.push(i);
	}
	
	while (cards.size() != 1) {
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	printf("%d", cards.front());
}
