#include "10989.h"

void nojam10989::solution()
{
	int n, max = -1;
	int dict[10001] = { 0, };
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		dict[tmp]++;
		if (tmp > max)
			max = tmp;
	}

	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < dict[i]; j++) {
			printf("%d\n", i);
		}
	}
}
