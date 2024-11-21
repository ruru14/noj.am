#include "2231.h"

int generate_number(int num) {
	int g = num;
	for (int i = 0; i < 7; i++) {
		g = g + num % (int)pow(10, i + 1) / pow(10, i);
	}
	return g;
}

void nojam2231::solution()
{
	int input;
	int flag = 0;
	scanf("%d", &input);
	for (int i = 0; i < input; i++) {
		if (generate_number(i) == input) {
			printf("%d", i);
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("0");
	}
}
