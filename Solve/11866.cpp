#include "11866.h"

void nojam11866::solution()
{
	int n, k;
	std::queue<int> queue;
	scanf("%d %d", &n, &k);

	for (int i = 1; i < n + 1; i++) {
		queue.push(i);
	}
	printf("<");

	while (!queue.empty()) {
		for (int i = 0; i < k - 1; i++) {
			queue.push(queue.front());
			queue.pop();
		}
		printf("%d", queue.front());
		queue.pop();
		if (!queue.empty())
			printf(", ");
		else
			printf(">");
	}
}
