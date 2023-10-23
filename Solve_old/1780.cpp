#include "1780.h"

int zero = 0;
int plus = 0;
int minus = 0;
int paper[2188][2188] = { {0,} };

void divide(int x, int dx, int y, int dy) {
	int flag = paper[y][x];
	for (int i = y; i < dy; i++) {
		for (int j = x; j < dx; j++) {
			if (paper[i][j] != flag) {
				int nx = (dx - x) / 3;
				int ny = (dy - y) / 3;
				divide(x + nx * 0, x + nx * 1, y + ny * 0, y + ny * 1);
				divide(x + nx * 1, x + nx * 2, y + ny * 0, y + ny * 1);
				divide(x + nx * 2, dx, y + ny * 0, y + ny * 1);
				divide(x + nx * 0, x + nx * 1, y + ny * 1, y + ny * 2);
				divide(x + nx * 1, x + nx * 2, y + ny * 1, y + ny * 2);
				divide(x + nx * 2, dx, y + ny * 1, y + ny * 2);
				divide(x + nx * 0, x + nx * 1, y + ny * 2, dy);
				divide(x + nx * 1, x + nx * 2, y + ny * 2, dy);
				divide(x + nx * 2, dx, y + ny * 2, dy);
				return;
			}
		}
	}

	switch (flag) {
	case 0:
		zero++;
		break;
	case 1:
		plus++;
		break;
	case -1:
		minus++;
		break;
	}
}

void nojam1780::solution()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	divide(0, n, 0, n);

	printf("%d\n%d\n%d", minus, zero, plus);
}
