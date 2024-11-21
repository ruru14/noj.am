#include "1009.h"

void nojam1009::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		int ans = 1;
		scanf("%d %d", &a, &b);
		for (int j = 0; j < b; j++) {
			ans = ((ans % 10) * (a % 10)) % 10;
			if (ans == 0) {
				ans = 10;
				break;
			}
		}
		printf("%d\n", ans);
	}
}
