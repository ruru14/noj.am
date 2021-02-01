#include "../AlgorithmStudy.h"

namespace nojam2606 {
	static void solution() {
		int nodes;
		int edges;
		int infection = 0;
		scanf_s("%d", &nodes);
		scanf_s("%d", &edges);

		std::vector<bool> visit(nodes);
		std::vector<std::vector<int>> adjList(nodes);

		for (int i = 0; i < edges; i++) {
			int from;
			int to;
			scanf_s("%d %d", &from, &to);
			adjList[from - 1].push_back(to - 1);
			adjList[to - 1].push_back(from - 1);
		}

		std::queue<int> queue;
		queue.push(0);

		while (!queue.empty()) {
			int current = queue.front();
			queue.pop();

			if (!visit[current]) {
				infection++;
				visit[current] = true;
			}

			for (int i = 0; i < adjList[current].size(); i++) {
				if (!visit[adjList[current][i]]) {
					queue.push(adjList[current][i]);
				}
			}

		}

		printf("%d", infection-1);
	}
}