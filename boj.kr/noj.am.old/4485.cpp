#include "4485.h"

int nojam4485::dijkstra(std::vector<std::vector<std::pair<int, int>>> map)
{
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

	return distance[distance.size() - 1];
}

void nojam4485::solution() {
	std::vector<int> answer;
	int n = -1;
	int tc = 1;
	int cost = 0;
	scanf_s("%d", &n);

	while (n != 0) {
		std::vector<std::vector<std::pair<int, int>>> map(n * n);
		std::vector<int> node(n * n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf_s("%d", &cost);
				node[n * i + j] = cost;
				if (j != 0) {
					map[n * i + j].push_back(std::make_pair(n * i + j - 1, node[n * i + j - 1]));
					map[n * i + j - 1].push_back(std::make_pair(n * i + j, node[n * i + j]));
				}
				if (i != 0) {
					map[n * i + j].push_back(std::make_pair(n * (i - 1) + j, node[n * (i - 1) + j]));
					map[n * (i - 1) + j].push_back(std::make_pair(n * i + j, node[n * i + j]));
				}
			}
		}
		printf("Problem %d: %d\n", tc++, nojam4485::dijkstra(map) + node[0]);
		scanf_s("%d", &n);
	}
}