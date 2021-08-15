#include "4948.h"

int arr[250000] = { 0, };

void nojam4948::solution() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 250000; i++) {
		arr[i] = i;
	}
	arr[1] = 0;
	
	do {
		int ans = 0;
		for (int i = 2; i <= (int)sqrt(2 * n); i++) {
			if (arr[i] != 0) {
				for (int j = 2; i * j <= 2 * n; j++) {
					arr[i * j] = 0;
				}
			}
		}
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0)
				ans++;
		}
		printf("%d\n", ans);
		scanf("%d", &n);
	} while (n != 0);
	
}