#include "1463.h"

int memo[10000001]{};

int calc(int num) {

	int a = 10000000;
	int b = 10000000;
	int c = 10000000;
	int min = 10000000;

	if (num == 1) {
		return 1;
	}

	if (num % 3 == 0) {
		if (memo[num / 3] == 10000000) {
			memo[num / 3] = calc(num / 3);
			a = memo[num / 3] + 1;
		}
		else {
			a = memo[num / 3] + 1;
		}
	}
	if (num % 2 == 0) {
		if (memo[num / 2] == 10000000) {
			memo[num / 2] = calc(num / 2);
			b = memo[num / 2] + 1;
		}
		else {
			b = memo[num / 2] + 1;
		}
	}
	if (memo[num - 1] == 10000000) {
		memo[num - 1] = calc(num - 1);
		c = memo[num - 1] + 1;
	}
	else {
		c = memo[num - 1] + 1;
	}


	min = (a <= b && a <= c) ? a :
		(b <= a && b <= c) ? b : c;
	memo[num] = min;

	return memo[num];
}

void nojam1463::solution()
{
	int num;
	scanf("%d", &num);
	std::fill_n(memo, 10000000, 10000000);

	printf("%d", calc(num) - 1);
}
