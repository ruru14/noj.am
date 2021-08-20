#include "2749.h"

int mem[1000000000000000001] = { 0, };

int fibo(int n) {
	if (n < 2)
		return n;
	if (mem[n] == 0)
		mem[n] = fibo(n - 1) + fibo(n - 2);
	return mem[n];
}

void nojam2749::solution()
{
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
}
