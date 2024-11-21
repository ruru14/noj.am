#include "11047.h"

void nojam11047::solution()
{
	int n, k, ans = 0;
	scanf("%d %d", &n, &k);
	std::vector<int> coin(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	for (int i = coin.size() - 1; i >= 0; i--) {
		while (k >= coin[i]) {
			k -= coin[i];
			ans++;
		}
	}

	printf("%d", ans);
}
