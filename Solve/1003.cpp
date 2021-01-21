#include "../AlgorithmStudy.h"

namespace nojam1003 {
	static void solution() {
		int testCase;
		scanf_s("%d", &testCase);
		int counter[2][41] = { 0, };
		counter[0][0] = 1;
		counter[1][0] = 0;
		counter[0][1] = 0;
		counter[1][1] = 1;
		int memo = 2;
		for (int i = 0; i < testCase; i++) {
			int fibo;
			scanf_s("%d", &fibo);

			for (int i = memo; i <= fibo; i++) {
				counter[0][i] = counter[0][i - 1] + counter[0][i - 2];
				counter[1][i] = counter[1][i - 1] + counter[1][i - 2];
			}
			if (memo < fibo) {
				memo = fibo;
			}

			printf("%d %d\n", counter[0][fibo], counter[1][fibo]);
		}
	}
}