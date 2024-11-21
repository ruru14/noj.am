#include "2522.h"

void nojam2522::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		for (int k = 0; k < n - i; k++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n; i > 0; i--) {
		for (int k = 0; k < n - i; k++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
