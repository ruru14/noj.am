#include "1676.h"

void nojam1676::solution()
{
	int n, ans = 0;
	scanf("%d", &n);

	for (int i = 0; i < n + 1; i++) {
		if (i % 5 == 0) {
			int tmp = i;
			while (tmp % 5 == 0 && tmp != 0) {
				tmp = tmp / 5;
				ans++;
			}
		}
	}

	printf("%d", ans);

}
