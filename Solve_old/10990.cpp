#include "10990.h"

void nojam10990::solution()
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
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
}
