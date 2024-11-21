#include "10996.h"

void nojam10996::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 2 * n; i++) {
		for (int j = i; j < i + n - 1; j++) {
			if (j % 2 == 0) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		if ((i + n) % 2 == 1) {
			printf("*");
		}
		printf("\n");
	}
}
