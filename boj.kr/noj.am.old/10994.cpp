#include "10994.h"

int arr[500][500] = { {0,}, };

void square(int x, int y, int size) {
	for (int i = 0; i < size; i++) {
		arr[y + i][x] = 1;
		arr[y][x + i] = 1;

		arr[y + i][x + size - 1] = 1;
		arr[y + size - 1][x + i] = 1;
	}
}

void nojam10994::solution()
{
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("*");
		return;
	}

	for (int i = 0; i < n; i++) {
		square(2 * i, 2 * i, 4 * (n - i) - 3);
	}

	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			if (arr[i][j] == 0) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}
