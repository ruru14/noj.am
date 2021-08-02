#include "9461.h"

long long mem[101] = { 1, 1, 1, };

long long padovan(int n) {
	if (n < 3)
		return mem[n];
	if (mem[n] == 0)
		mem[n] = padovan(n - 2) + padovan(n - 3);
	return mem[n];
}

void nojam9461::solution()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%lld\n", padovan(tmp - 1));
	}
}
