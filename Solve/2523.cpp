#include "2523.h"

void nojam2523::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n ; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
