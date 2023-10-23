#include "9184.h"

int mem[101][101][101];

int recursion(int a, int b, int c) {
	if (a <= 50 | b <= 50 | c <= 50) {
		if (mem[a][b][c] == -1) {
			mem[a][b][c] = 1;
		}
		return mem[a][b][c];
	}
	if (a > 70 | b > 70 | c > 70) {
		if (mem[a][b][c] == -1) {
			mem[a][b][c] = recursion(70, 70, 70);
		}
		return mem[a][b][c];
	}
	if (a < b & b < c) {
		if (mem[a][b][c] == -1) {
			mem[a][b][c] = recursion(a, b, c - 1) + recursion(a, b - 1, c - 1) - recursion(a, b - 1, c);
		}
		return mem[a][b][c];
	}
	if (mem[a][b][c] == -1) {
		mem[a][b][c] = recursion(a - 1, b, c) + recursion(a - 1, b - 1, c) + recursion(a - 1, b, c - 1) - recursion(a - 1, b - 1, c - 1);
	}
	return mem[a][b][c];
}

void nojam9184::solution()
{
	memset(mem, -1, sizeof(mem));
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a += 50;
	b += 50;
	c += 50;

	do {
		printf("w(%d, %d, %d) = %d\n", a - 50, b - 50, c - 50, recursion(a, b, c));
		scanf("%d %d %d", &a, &b, &c);
		a += 50;
		b += 50;
		c += 50;
	} while (a - 50 != -1 | b - 50 != -1 | c - 50 != -1);
}
