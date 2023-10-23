#include "1654.h"

void nojam1654::solution()
{
	long long n, m, left, right, mid, sum, ans = 0;
	std::vector<long long> cable;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		cable.push_back(tmp);
	}

	std::sort(cable.begin(), cable.end());
	left = 0;
	right = INT_MAX;

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += cable[i] / mid;
		}

		if (sum >= m) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;

	}
	printf("%lld", ans);
}
