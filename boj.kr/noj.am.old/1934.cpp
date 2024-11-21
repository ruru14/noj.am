#include "1934.h"

void nojam1934::solution()
{
	int t;
	scanf("%d", &t);

	while (t--) {
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
		printf("%d", (a * b) / gcdB);
	}
	
}
