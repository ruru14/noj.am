#include "11727.h"

void nojam11727::solution()
{
	int n;
	scanf("%d", &n);
	int* tile = new int[n + 1];
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 3;

	for (int i = 3; i < n + 1; i++) {
		tile[i] = (tile[i - 1] + 2 * tile[i - 2]) % 10007;
	}

	printf("%d", tile[n]);
}
