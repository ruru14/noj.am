#include "10250.h"

void nojam10250::solution()
{
	int t, h, w, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);
		printf("%d%.2d\n", n % h == 0 ? h : n % h, (int)ceil((double)n / h));
	}
}
