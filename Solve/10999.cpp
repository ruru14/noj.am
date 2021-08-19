#include "10999.h"

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

void nojam10999::solution() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	std::vector<long long> buffer(n + 1);
	std::vector<long long> arr(n + 1);
	std::vector<long long> tree(n + 1);
	std::vector<long long> sub_tree(n + 1);

	for (int i = 1; i < n + 1; i++) {
		scanf("%lld", &arr[i]);
		update(tree, i, arr[i]);
		update(tree, i + 1, -arr[i]);
		update(sub_tree, i, (-i + 1) * arr[i]);
		update(sub_tree, i + 1, i * arr[i]);
	}

	m += k;
	while (m--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int from, to;
			long long value;
			scanf("%d %d %lld", &from, &to, &value);
			update(tree, from, value);
			update(tree, to + 1, -value);
			update(sub_tree, from, (-from + 1) * value);
			update(sub_tree, to + 1, to * value);
		}
		else if (a == 2) {
			int start, end;
			long long ans = 0;
			scanf("%d %d", &start, &end);
			ans += sum(tree, end) * end + sum(sub_tree, end);
			ans -= sum(tree, start - 1) * (start - 1) + sum(sub_tree, start - 1);
			printf("%lld\n", ans);
		}
	}
}