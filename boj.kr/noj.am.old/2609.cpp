#include "2609.h"

void nojam2609::solution()
{
	int a, b;
	int lcm, gcdA, gcdB;
	scanf("%d %d", &a, &b);
	gcdA = a;
	gcdB = b;
	
	while (gcdA % gcdB != 0) {
		int tmp = gcdA;
		gcdA = gcdB;
		gcdB = tmp % gcdB;
	}
	printf("%d\n", gcdB);
	printf("%d", (a * b) / gcdB);
}
