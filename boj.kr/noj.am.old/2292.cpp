#include "2292.h"

void nojam2292::solution()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		tmp = 3 * pow(i, 2) - 3 * i + 1;
		if (tmp >= n) {
			ans = i;
			break;
		}
	}

	printf("%d", ans);
}
