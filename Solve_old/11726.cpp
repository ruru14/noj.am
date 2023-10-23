#include "11726.h"

void nojam11726::solution()
{
	int n;
	scanf("%d", &n);
	int* tile = new int[n + 1];
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 2;
	tile[3] = 3;
	tile[4] = 5;

	for (int i = 5; i < n + 1; i++) {
		tile[i] = (tile[i - 1] % 10007 + tile[i - 2] % 10007) % 10007;
	}

	printf("%d", tile[n]);

}
