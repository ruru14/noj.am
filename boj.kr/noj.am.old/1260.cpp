#include "1260.h"

void nojam1260::adjacencyBFS(int start) {
	std::queue<int> queue;

	queue.push(start);
	while (!queue.empty()) {
		int current = queue.front();
		queue.pop();
		if (!bfsVisit[current]) {
			bfsVisit[current] = true;
			printf("%d ", current + 1);

			for (int i = 0; i < adjList.at(current).size(); i++) {
				if (!bfsVisit[adjList.at(current)[i]]) {
					queue.push(adjList.at(current)[i]);
				}
			}
		}

	}
}

void nojam1260::adjacencyDFS(int index) {
	dfsVisit[index] = true;
	printf("%d ", index + 1);

	for (int i = 0; i < adjList.at(index).size(); i++) {
		int next = adjList.at(index)[i];
		if (!dfsVisit[adjList.at(index)[i]]) {
			nojam1260::adjacencyDFS(next);
		}
	}
}

void nojam1260::adjacencyDFSStack(int index) {
	std::stack<int> stack;
	int current = index;
	dfsVisitStack[current] = true;
	printf("%d ", index + 1);

	do {
		for (int i = 0; i < adjList.at(current).size(); i++) {
			if (!dfsVisitStack[adjList.at(current)[i]]) {
				stack.push(current);
				dfsVisitStack[adjList.at(current)[i]] = true;
				printf("%d ", adjList.at(current)[i] + 1);
				current = adjList.at(current)[i];
				break;
			}
			else {
				stack.pop();
			}
		}
	} while (!stack.empty());
}

void nojam1260::solution() {
	int node;
	int vertex;
	int start;
	scanf_s("%d %d %d", &node, &vertex, &start);

	for (int i = 0; i < vertex; i++) {
		int node1;
		int node2;
		scanf_s("%d %d", &node1, &node2);
		adjList[node1 - 1].push_back(node2 - 1);
		adjList[node2 - 1].push_back(node1 - 1);
	}

	for (int i = 0; i < node; i++) {
		std::sort(adjList.at(i).begin(), adjList.at(i).end());
	}

	nojam1260::adjacencyDFS(start - 1);
	printf("\n");
	nojam1260::adjacencyDFSStack(start - 1);
	printf("\n");
	nojam1260::adjacencyBFS(start - 1);
}
