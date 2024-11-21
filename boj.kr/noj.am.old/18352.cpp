#include "18352.h"

int n, m, k, x;
int length[300001];
std::vector<std::vector<int>> adjList(300001);

void adjacencyBFS(int start, int dest) {
	std::queue<int> queue;
	length[start] = 0;
	int ans = 0;

	queue.push(start);
	while (!queue.empty()) {
		int current = queue.front();
		queue.pop();
		for (int i = 0; i < adjList.at(current).size(); i++) {
			if (length[adjList.at(current)[i]] == -1) {
				length[adjList.at(current)[i]] = length[current] + 1;
				queue.push(adjList.at(current)[i]);
			}
		}

	}

	for (int i = 1; i <= n; i++) {
		if (length[i] == dest) {
			printf("%d\n", i);
			ans++;
		}
	}
	if (ans == 0) {
		printf("-1");
	}
}

void nojam18352::solution()
{
	scanf("%d %d %d %d", &n, &m, &k, &x);
	std::fill_n(length, 300000, -1);

	while (m--) {
		int from, to;
		scanf("%d %d", &from, &to);
		adjList[from].push_back(to);
	}

	adjacencyBFS(x, k);
}
