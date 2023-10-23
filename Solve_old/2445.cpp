#include "2445.h"

void nojam2445::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		for (int k = 0; k < 2 * (n - i); k++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		for (int k = 0; k < 2 * (n - i); k++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
