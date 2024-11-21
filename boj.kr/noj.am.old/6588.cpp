#include "6588.h"

void nojam6588::solution()
{
	int n;
	scanf("%d", &n);

	bool arr[1000001] = { 0, };

	arr[1] = true;

	for (int i = 2; i <= 1000; i++) {
		if (!arr[i]) {
			for (int j = 2; i * j <= 1000000; j++) {
				arr[i * j] = true;
			}
		}
	}

	do {

		for (int i = 3; i < 500000; i++) {
			if (i > n) {
				break;
			}
			if (!arr[i] & !arr[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}


		scanf("%d", &n);
	} while (n != 0);
}
