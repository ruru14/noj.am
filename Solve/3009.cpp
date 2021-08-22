#include "3009.h"

void nojam3009::solution() {
	int t = 3;
	std::map<int, int> x, y;

	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (x.find(a) != x.end()) {
			x.erase(x.find(a));
		}
		else {
			x[a]++;
		}

		if (y.find(b) != y.end()) {
			y.erase(y.find(b));
		}
		else {
			y[b]++;
		}
	}
	printf("%d %d", x.begin()->first, y.begin()->first);

}