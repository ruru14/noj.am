#include "18111.h"

void nojam18111::solution()
{
	int n, m, b;
	int sum = 0;
	scanf("%d %d %d", &n, &m, &b);
	std::vector<std::vector<int>> field(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
			field[i].push_back(tmp);
		}
	}

	printf("%d", (int)round((double)sum / (double)(n * m)));


	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", field[i][j]);
		}
		printf("\n");
	}*/

}
