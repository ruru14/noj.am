#include "11653.h"

void nojam11653::solution()
{
	int n;
	scanf("%d", &n);

	for (int i = 2; n != 1;) {
		if (n % i == 0) {
			printf("%d\n", i);
			n = n / i;
		}
		else {
			i++;
		}
	}
}
