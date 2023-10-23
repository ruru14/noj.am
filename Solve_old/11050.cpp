#include "11050.h"

int factorial(int num) {
	if (num <= 1) return 1;
	else return num * factorial(num - 1);
}

void nojam11050::solution()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", (int)(factorial(n) / (int)(factorial(k) * factorial(n - k))));
}
