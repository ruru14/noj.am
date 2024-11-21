#include "11003.h"

int arr[5000001];

struct pair {
	int val;
	int index;
};

struct compare {
	bool operator()(const pair& a, const pair& b) {
		return a.val > b.val;
	}
};

void nojam11003::solution()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, l;
	std::cin >> n >> l;
	std::priority_queue<pair, std::vector<pair>, compare> queue;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		queue.push({ arr[i], i });
		while (queue.top().index < i - l + 1) {
			queue.pop();
		}
		std::cout << queue.top().val << " ";
	}
}
