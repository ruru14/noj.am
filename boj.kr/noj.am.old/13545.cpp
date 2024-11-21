#include "13545.h"

int mem[100001] = { 0, };
bool calc[100001];

int sum(std::vector<int>& tree, int index) {
	int ans = 0;
	if (!calc[index]) {
		int tmp = index;
		while (index > 0) {
			ans += tree[index];
			index -= (index & -index);
		}
		calc[tmp] = !calc[tmp];
		mem[tmp] = ans;
	}
	else {
		return mem[index];
	}
	return ans;
}

void update(std::vector<int>& tree, int index, int value) {
	while (index < tree.size()) {
		tree[index] += value;
		index += (index & -index);
	}
}

void nojam13545::solution()
{
	int n, m;
	scanf("%d", &n);
	std::vector<int> tree(n + 1);
	std::vector<int> arr(n + 1);

	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &arr[i]);
		update(tree, i, arr[i]);
	}

	scanf("%d", &m);

	while (m--) {
		int a, b, max = 0;
		scanf("%d %d", &a, &b);
		for (int i = a; i < b + 1; i++) {
			for (int j = i + 1; j < b + 1; j++) {
				if (sum(tree, j) - sum(tree, i - 1) == 0 & j - i > max)
					max = j - i + 1;
			}
		}
		printf("%d\n", max);
	}

}
