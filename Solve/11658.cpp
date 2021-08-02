#include "11658.h"

int mem[1025][1025] = { {0,} };
int ori[1025][1025] = { {0,} };
int trs[1025][1025] = { {0,} };

void nojam11658::solution()
{
	int n, m;
	int w, x, y, z, v, c;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			mem[i + 1][j + 1] = mem[i + 1][j] + mem[i][j + 1] - mem[i][j] + tmp;
			ori[i][j] = tmp;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &w);
		if (w == 0) {
			scanf("%d %d %d", &x, &y, &c);
			x--;
			y--;
			trs[x][y] = c - ori[x][y];
			//printf("B : %d %d : %d\n", ori[x][y], c, trs[x][y]);
			ori[x][y] = c;
			/*printf("S : %d %d\n", x, y);
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					printf("%d ", trs[a][b]);
				}
				printf("\n");
			}*/
		}
		else {
			scanf("%d %d %d %d", &x, &y, &z, &v);
			int ans = mem[z][v] + mem[x - 1][y - 1] - mem[x - 1][v] - mem[z][y - 1];
			for (int a = x - 1; a <= z; a++) {
				for (int b = y - 1; b <= v; b++) {
					ans += trs[a][b];
				}
			}
			printf("%d\n", ans);
		}
	}
}
