#include "17626.h"

void nojam17626::solution()
{
	int n, ans = 0;
	int tmp;
	int a = 0, b = 0, c = 0, d = 0;
	scanf("%d,", &n);
	tmp = (int)sqrt(n) + 1;
	for (a = 0; a < tmp; a++) {
		for (b = 0; b < tmp; b++) {
			for (c = 0; c < tmp; c++) {
				for (d = 0; d < tmp; d++) {
					int sum = (int)pow(a, 2) + (int)pow(b, 2) + (int)pow(c, 2) + (int)pow(d, 2);
					if (sum == n) {
						if (a != 0)
							ans++;
						if (b != 0)
							ans++;
						if (c != 0)
							ans++;
						if (d != 0)
							ans++;
						printf("%d", ans);
						return;
					}
					if (sum > n) {
						break;
					}
				}
			}
		}
	}
}
