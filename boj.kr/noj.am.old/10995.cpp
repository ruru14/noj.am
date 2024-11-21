#include "10995.h"

void nojam10995::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) {
			printf(" ");
		}
		for (int j = 0; j < 2 * n; j++) {
			if (j % 2 == 0) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
