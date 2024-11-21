#include "2630.h"

int white = 0;
int blue = 0;
int paper[128][128];

void test(int x, int dx, int y, int dy) {
	int flag = paper[x][y];
	int tmp = paper[4][0];
	printf("%d %d %d %d\n", x, y, flag, tmp);
	//printf("FLAG : %d %d\n", flag, paper[x][y]);
	for (int i = y; i < dy; i++) {
		for (int j = x; j < dx; j++) {
			int flag = paper[i][j];
			/*if (paper[i][j] != flag) {
				printf("??? %d %d ???", paper[i][j], flag);
			}*/
			printf("%d %d : %d |", i, j, flag);
		}
		printf("\n");
	}
}

void divide(int x, int dx, int y, int dy) {
	int flag = paper[y][x];
	for (int i = y; i < dy; i++) {
		for (int j = x; j < dx; j++) {
			if (paper[i][j] != flag) {
				divide(x, (x + dx) / 2, y, (y + dy) / 2);
				divide((x + dx) / 2, dx, y, (y + dy) / 2);
				divide(x, (x + dx) / 2, (y + dy) / 2, dy);
				divide((x + dx) / 2, dx, (y + dy) / 2, dy);
				return;
			}
		}
	}

	if (flag == 1)
		blue++;
	else
		white++;
}

void nojam2630::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			paper[i][j] = tmp;
		}
	}

	//test(4, 6, 0, 2);
	//printf("\n");
	divide(0, n, 0, n);
	//printf("\n");
	printf("%d\n%d", white, blue);
}
