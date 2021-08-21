#include "2749.h"

int mem[1500001] = { 0, };

int fibo(unsigned long long n) {
	if (n < 2)
		return n;
	if (mem[n] == 0)
		mem[n] = (fibo(n - 1) % 1000000 + fibo(n - 2) % 1000000) % 1000000;
	return mem[n];
}

void nojam2749::solution()
{
	unsigned long long n;
	scanf("%lld", &n);
	n = n % 1500000;
	printf("%d", fibo(n));
}
