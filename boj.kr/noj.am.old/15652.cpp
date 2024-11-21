#include "15652.h"

int n, m;
int arr[10] = { 0, };

void track(int cnt) {
	if (cnt == m + 1) {
		for (int i = 1; i < m + 1; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i < n + 1; i++) {
		if (i >= arr[cnt - 1]) {
			arr[cnt] = i;
			track(cnt + 1);
		}
	}
}

void nojam15652::solution() {
	scanf("%d %d", &n, &m);

	track(1);
}