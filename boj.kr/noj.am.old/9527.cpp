#include "9527.h"

int a, b;

int count(int index) {
	int ans = 0;
	while (index > 0) {
		ans++;
		index -= (index & -index);
	}
	return ans;
}

void nojam9527::solution()
{
	int ans = 0;
	//scanf("%d %d", &a, &b);

	for (int i = 1; i < 50; i++) {
		printf("%d : %d\n", i, count(i));
	}
}
