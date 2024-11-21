#include "14936.h"

void nojam14936::solution()
{
	int answer = 1;
	int n;
	int m;
	scanf_s("%d %d", &n, &m);

	int act_one = n;
	int act_two = n / 2;
	int act_three = (n + 1) / 2;
	int act_four = (n + 2) / 3;

	if (m >= act_one) answer++;

	if (m >= act_two) answer++;

	if (m >= act_three) answer++;

	if (n > 2) {
		if (m >= act_four) answer++;

		if (m >= act_one + act_four) answer++;

		if (m >= act_two + act_four) answer++;

		if (m >= act_three + act_four) answer++;
	}

	if (n == 1) answer = 1 + (m == 0 ? 0 : 1);

	printf("%d", answer);
}
