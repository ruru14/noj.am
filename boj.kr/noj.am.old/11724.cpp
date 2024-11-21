#include "11724.h"

int cc = 0;
bool visit[1001];
std::vector<std::vector<int>> adjList(1001);

void bfs(int start) {
	std::queue<int> queue;
	cc++;
	
	queue.push(start);
	while (!queue.empty()) {
		int current = queue.front();
		queue.pop();

		if (!visit[current]) {
			visit[current] = !visit[current];
			for (int i = 0; i < adjList[current].size(); i++) {
				if (!visit[adjList[current].at(i)])
					queue.push(adjList[current].at(i));
			}
		}
	}

}

void nojam11724::solution()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	for (int i = 1; i < n + 1; i++) {
		if (!visit[i])
			bfs(i);
	}
	printf("%d", cc);
}
