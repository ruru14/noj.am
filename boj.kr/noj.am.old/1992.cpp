#include "1992.h"

int arr[64][64] = { {0,} };

void nojam1992::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
