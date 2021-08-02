#include "11659.h"

int mem[100001];

void nojam11659::solution()
{
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		
		sum += tmp;
		mem[i + 1] = sum;
	}

	for (int i = 0; i < m; i++) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		printf("%d\n", mem[end] - mem[begin - 1]);
	}
}
