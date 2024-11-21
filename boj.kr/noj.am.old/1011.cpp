#include "1011.h"

void nojam1011::solution() {
	int t, x, y, count;
	long long sum;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &x, &y);
		y -= x;
		count = 0;
		sum = 0;
		while (y > sum + count * 2) {
			sum += count * 2;
			count++;
		}

		if (sum + count >= y)
			printf("%d\n", 2 * count - 1);
		else
			printf("%d\n", 2 * count);
	}
}