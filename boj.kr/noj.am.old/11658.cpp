#include "11658.h"

int n, m;
int arr[1025][1025] = { {0,} };
int tree[1025][1025] = { {0,} };

int sum(int index_x, int index_y) {
	int ans = 0;
	while (index_x > 0) {

		int temp_y = index_y;
		while (temp_y > 0) {
			ans += tree[index_x][temp_y];
			temp_y -= (temp_y & -temp_y);
		}
		index_x -= (index_x & -index_x);
	}
	return ans;
}

void update(int index_x, int index_y, int value) {
	while (index_x <= n) {
		int temp_y = index_y;
		while (temp_y <= n) {
			tree[index_x][temp_y] += value;
			temp_y += (temp_y & -temp_y);
		}
		index_x += (index_x & -index_x);
	}
}

void nojam11658::solution()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			scanf("%d", &arr[i][j]);
			update(i, j, arr[i][j]);
		}
	}

	while (m--) {
		int flag;
		scanf("%d", &flag);
		if (flag == 0) {
			int x, y, value;
			scanf("%d %d %d", &x, &y, &value);
			update(x, y, value - arr[x][y]);
			arr[x][y] = value;
		}
		else if (flag == 1) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1) - sum(x1 - 1, y2));
		}
	}
}
