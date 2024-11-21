#include "1012.h"

bool visit[2501];
int m, n, num = 0;
int map[2501] = { {0,} };

void numbering(int index) {
	visit[index] = !visit[index];
	//UP (index > m)
	if (index >= m) {
		if (!visit[index - m] && map[index - m] == 1) {
			numbering(index - m);
		}
	}
	//Left (index % m != 0)
	if (index % m != 0) {
		if (!visit[index - 1] && map[index - 1] == 1) {
			numbering(index - 1);
		}
	}
	//Down (index < m * n - m)
	if (index < m * n - m) {
		if (!visit[index + m] && map[index + m] == 1) {
			numbering(index + m);
		}
	}
	//Right (index % m != m-1)
	if (index % m != m - 1) {
		if (!visit[index + 1] && map[index + 1] == 1) {
			numbering(index + 1);
		}
	}
}

void nojam1012::solution()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int k;
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y * m + x] = 1;
		}
		for (int l = 0; l < n; l++) {
			for (int j = 0; j < m; j++) {
				if (!visit[l * m + j] && map[l * m + j] != 0) {
					numbering(l * m + j);
					num++;
				}
			}
		}

		printf("%d\n", num);
		num = 0;
		for (int j = 0; j < 2501; j++) {
			visit[j] = false;
			map[j] = 0;
		}
	}

	
}
