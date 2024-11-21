#include "9020.h"

void nojam9020::solution()
{
	int t, n;
	scanf("%d", &t);
	bool arr[10001] = { 0, };

	arr[1] = true;

	for (int i = 2; i <= 100; i++) {
		if (!arr[i]) {
			for (int j = 2; i * j <= 10000; j++) {
				arr[i * j] = true;
			}
		}
	}

	while (t--) {
		scanf("%d", &n);
		int a, b, dis = 10000;
		for (int i = 0; i < 5000; i++) {
			if (i > n)
				break;
			if (arr[i])
				continue;
			if (!arr[n - i]) {
				if (dis > n - i - i & n - i - i >= 0) {
					dis = n - i - i;
					a = i;
					b = n - i;
				}
			}
		}
		printf("%d %d\n", a, b);
	}
}
