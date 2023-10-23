#include "2042.h"

long long sum(std::vector<long long> &tree, int index) {
	long long ans = 0;
	while (index > 0) {
		ans += tree[index];
		index -= (index & -index);
	}
	return ans;
}

void update(std::vector<long long> &tree, int index, long long value) {
	while (index < tree.size()) {
		tree[index] += value;
		index += (index & -index);
	}
}

void nojam2042::solution() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	std::vector<long long> arr(n + 1);
	std::vector<long long> tree(n + 1);

	for (int i = 1; i < n + 1; i++) {
		scanf("%lld", &arr[i]);
		update(tree, i, arr[i]);
	}
	
	m += k;
	while (m--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int index;
			long long value;
			scanf("%d %lld", &index, &value);
			update(tree, index, (long long)(value - arr[index]));
			arr[index] = value;
		}
		else if (a == 2) {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", sum(tree, end) - sum(tree, start - 1));
		}
	}
}