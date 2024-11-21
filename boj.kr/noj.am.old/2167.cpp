#include "2167.h"

int mem[301][301] = { {0, } };

void nojam2167::solution()
{
	int n, m;
	int k, x, y, z, w;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d", &tmp);
			mem[i + 1][j + 1] = mem[i + 1][j] + mem[i][j + 1] - mem[i][j] + tmp;
		}
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x, &y, &z, &w);
		printf("%d\n", mem[z][w] + mem[x - 1][y - 1] - mem[x - 1][w] - mem[z][y - 1]);
	}
}
