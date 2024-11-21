#include "9095.h"

void nojam9095::solution()
{
	int t;
	scanf("%d", &t);
	int* arr = new int[12];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	while (t--) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", arr[tmp]);
	}
	
}
