#include "1085.h"

void nojam1085::solution()
{
	int x, y, w, h, min1, min2;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	min1 = w - x < h - y ? w - x : h - y;
	min2 = x < y ? x : y;
	printf("%d", min1 < min2 ? min1 : min2);
}
