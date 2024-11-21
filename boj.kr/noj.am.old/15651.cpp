#include "15651.h"

int n, m;
int arr[9];

void track(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i < n + 1; i++) {
		arr[cnt] = i;
		track(cnt + 1);
	}
}

void nojam15651::solution() {
	scanf("%d %d", &n, &m);

	track(0);
}