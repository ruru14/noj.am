#include "2775.h"

int combination(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}

void nojam2775::solution()
{
	int t, k, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int p = 1;
		scanf("%d", &k);
		k++;
		scanf("%d", &n);
		n--;
		printf("%d", combination(k + n, n));
	}

	//for (unsigned long long i = 1; i < 15; i++) { // floor
	//	for (unsigned long long j = 1; j < 15; j++) {
	//		unsigned long long tmp = 1;
	//		for (unsigned long long k = 0; k < i; k++) {
	//			tmp *= j + k;
	//		}
	//		tmp = tmp / factorial(i);
	//		printf("%.8llu ", tmp);
	//	}
	//	printf("\n");
	//}

	//01 05 15 35 70 126 : 1/24 * n * n+1 * n+2 * n+3 1*2*3*4 = 24
	//01 04 10 20 35 56 84 120 165 220 : 1/6 * n * (n+1) * (n+2) 1*2*3 = 6
	//01 03 06 10 15 21 28 36 45 55 : 1/2 * n * (n+1) : 1*2 = 2
	//01 02 03 04 05 06 07 08 09 10 : n : 1
}
