#include "2805.h"

void nojam2805::solution()
{
	long long n, m, left, right, mid, sum, ans = 0;
	std::vector<long long> tree;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		tree.push_back(tmp);
	}

	std::sort(tree.begin(), tree.end());
	left = 0;
	right = tree[tree.size() - 1];

	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
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
