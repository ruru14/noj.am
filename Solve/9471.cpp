#include "9471.h"

long long pisano_period(long long m) {
	int f0 = 0, f1 = 1, f2 = f0 + f1;

	for (int i = 0; i < m * m; i++) {
		f2 = (f0 + f1) % m;
		f0 = f1;
		f1 = f2;
		if (f0 == 0 & f1 == 1) return i + 1;
	}
}

void nojam9471::solution()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		long long m;
		scanf("%d %lld", &n, &m);
		printf("%d %lld\n", n, pisano_period(m));
	}
}
