#include "3053.h"

double pi = 3.141592653589793238;

void nojam3053::solution() {
	double n;
	scanf("%lf", &n);

	printf("%.6lf\n", round(pow(n, 2) * pi * 1000000) / 1000000);
	printf("%.6lf", round(pow(n, 2) * 2 * 1000000) / 1000000);
}