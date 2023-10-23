#include "11399.h"

void nojam11399::solution()
{
	int n, sum = 0, time = 0;
	scanf("%d", &n);
	std::vector<int> atm;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		atm.push_back(tmp);
	}

	std::sort(atm.begin(), atm.end());

	for (int i = 0; i < n; i++) {
		sum += atm[i];
		time += sum;
	}

	printf("%d", time);
}
