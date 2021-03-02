#include "20046.h"

int nojam20046::dijkstra(std::vector<std::vector<std::pair<int, int>>> map)
{
	printf("\n");
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			printf("%d %d %d\n", i, map[i][j].first, map[i][j].second);
		}
	}
	printf("\n");

	std::vector<int> distance(map.size(), 30000000);
	distance[0] = 0;

	std::priority_queue<std::pair<int, int>> queue;

	queue.push(std::make_pair(0, 0));

	while (!queue.empty()) {
		int cost = -queue.top().first;
		int current = queue.top().second;

		queue.pop();

		if (distance[current] < cost) {
			continue;
		}

		for (int i = 0; i < map[current].size(); i++) {
			int dest = map[current][i].first;
			int next_cost = cost + map[current][i].second;

			if (distance[dest] > next_cost) {
				distance[dest] = next_cost;
				queue.push(std::make_pair(-next_cost, dest));
			}
		}
	}
	return distance[distance.size()-1];
}

void nojam20046::solution() {
	int width;
	int height;
	int cost;
	scanf_s("%d %d", &height, &width);

	std::vector<std::vector<std::pair<int, int>>> map(width * height);
	std::vector<int> node(width * height);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf_s("%d", &cost);
			node[width * i + j] = cost;
			if (j != 0) {
				if (node[width * i + j - 1] != -1)
					map[width * i + j].push_back(std::make_pair(width * i + j - 1, node[width * i + j - 1]));
				if (node[width * i + j] != -1)
					map[width * i + j - 1].push_back(std::make_pair(width * i + j, node[width * i + j]));
			}
			if (i != 0) {
				if (node[width * (i - 1) + j] != -1)
					map[width * i + j].push_back(std::make_pair(width * (i - 1) + j, node[width * (i - 1) + j]));
				if (node[width * i + j] != -1)
					map[width * (i - 1) + j].push_back(std::make_pair(width * i + j, node[width * i + j]));
			}
		}
	}
	if (node[0] == -1 || node[node.size() - 1] == -1 || nojam20046::dijkstra(map) > 10000000) {
		printf("-1");
	}
	else {
		printf("%d", nojam20046::dijkstra(map) + node[0]);
	}
}