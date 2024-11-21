#include "1916.h"

void dijkstra(int start, int destination, std::vector<std::vector<std::pair<int, int>>> map) {
	std::vector<int> distance(map.size(), INT_MAX);
	distance[start] = 0;

	std::priority_queue<std::pair<int, int>> queue;

	queue.push(std::make_pair(0, start));

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

	printf("%d", distance[destination]);

}

void nojam1916::solution()
{
	int INF = INT_MAX;
	int vertex;
	int edge;
	int start, dest;
	int from;
	int to;
	int weight;
	scanf("%d", &vertex);
	scanf("%d", &edge);

	std::vector<std::vector<std::pair<int, int>>> temp(vertex);
	std::vector<int> distance(vertex, INF);
	std::vector<bool> visit(vertex);

	for (int i = 0; i < edge; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		temp[from - 1].push_back(std::make_pair(to - 1, weight));
	}

	scanf("%d %d", &start, &dest);
	start--;
	dest--;

	dijkstra(start, dest, temp);

}
