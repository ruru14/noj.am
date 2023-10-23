#include "5086.h"

void nojam5086::solution()
{
	int a, b;
	scanf("%d %d", &a, &b);

	do {
		if (a / b != 0) {
			if (a % b != 0) {
				printf("neither\n");
			}
			else {
				printf("multiple\n");
			}
		}
		else if (b / a != 0) {
			if (b % a != 0) {
				printf("neither\n");
			}
			else {
				printf("factor\n");
			}
		}


		scanf("%d %d", &a, &b);
	} while (a != 0 & b != 0);
}
