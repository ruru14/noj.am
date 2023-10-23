#include "2869.h"

void nojam2869::solution()
{
	int a, b, v, ans;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d", (int)ceil((double)(v - b) / (a - b)));
}
