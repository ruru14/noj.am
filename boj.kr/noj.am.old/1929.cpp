#include "1929.h"

void nojam1929::solution()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int* arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = i;
	}
	arr[1] = 0;

	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (arr[i] != 0) {
			for (int j = 2; i * j <= n; j++) {
				arr[i * j] = 0;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i] != 0) {
			printf("%d\n", i);
		}
	}
}
