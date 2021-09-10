#include "10991.h"

void nojam10991::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		printf("*");
		if (i > 0) {
			for (int k = 0; k < 2 * i - 1; k++) {
				if (k % 2 == 0) {
					printf(" ");
				}
				else {
					printf("*");
				}
			}
			printf("*");
		}
		printf("\n");
	}
}
