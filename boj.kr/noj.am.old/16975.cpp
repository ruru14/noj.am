#include "16975.h"

long long sum(std::vector<long long>& tree, int index) {
	long long ans = 0;
	while (index > 0) {
		ans += tree[index];
		index -= (index & -index);
	}
	return ans;
}

void update(std::vector<long long>& tree, int index, long long value) {
	while (index < tree.size()) {
		tree[index] += value;
		index += (index & -index);
	}
}

void nojam16975::solution() {
	int n, m;
	scanf("%d", &n);
	std::vector<long long> arr(n + 1);
	std::vector<long long> tree(n + 1);


	for (int i = 1; i < n + 1; i++) {
		scanf("%lld", &arr[i]);
		update(tree, i, arr[i]);
		update(tree, i + 1, -arr[i]);
	}

	scanf("%d", &m);

	while (m--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int from, to;
			long long value;
			scanf("%d %d %lld", &from, &to, &value);
			update(tree, from, value);
			update(tree, to + 1, -value);
		}
		else if (a == 2) {
			int point;
			long long ans = 0;
			scanf("%d", &point);
			ans = sum(tree, point);
			printf("%lld\n", ans);
		}
	}
}