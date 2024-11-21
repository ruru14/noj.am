#include "2475.h"

void nojam2475::solution()
{
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += pow(tmp, 2);
	}
	
	printf("%d", sum%10);
}
