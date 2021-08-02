#include "11660.h"

int mem[1025][1025] = { {0, } };

void nojam11660::solution()
{
	int n, m;
	int x, y, z, w;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			mem[i + 1][j + 1] = mem[i + 1][j] + mem[i][j + 1] - mem[i][j] + tmp;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &x, &y, &z, &w);
		printf("%d\n", mem[z][w] + mem[x - 1][y - 1] - mem[x - 1][w] - mem[z][y - 1]);
	}
}
