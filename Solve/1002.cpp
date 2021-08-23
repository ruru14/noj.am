#include "1002.h"

void nojam1002::solution() {
	int t;
	int x1, y1, r1, x2, y2, r2, dist;
	int in, out;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		out = pow(r1, 2) + pow(r2, 2) + r1 * r2 * 2;
		in = pow(r1, 2) + pow(r2, 2) - r1 * r2 * 2;
		if (dist == 0 & r1 == r2) {
			printf("-1\n");
			continue;
		}
		if (in == dist | out == dist) {
			printf("1\n");
			continue;
		}
		if (out < dist) {
			printf("0\n");
			continue;
		}
		if (in > dist) {
			printf("0\n");
			continue;
		}
		printf("2\n");
	}
}