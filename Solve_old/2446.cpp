#include "2446.h"

void nojam2446::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = n; i > 1; i--) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}
