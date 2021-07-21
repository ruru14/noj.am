#include "1753.h"

void nojam1753::dijkstra(int start, std::vector<std::vector<std::pair<int, int>>> map){
	std::vector<int> distance(map.size(), 30000000);
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

	for (int i = 0; i < distance.size(); i++) {
		if (distance[i] >= 30000000) {
			printf("INF");
		}
		else {
			printf("%d", distance[i]);
		}
		if (i != distance.size() - 1) {
			printf("\n");
		}
	}
}

//int nojam1753::get_next(int current, int vertex, std::vector<std::vector<std::pair<int, int>>> map, std::vector<bool> visit) {
//	int next = -1;
//	int min = 30000000;
//	for (int i = 0; i < map[current].size(); i++) {
//		if (!visit[map[current][i].first] && map[current][i].second < min) {
//			min = map[current][i].second;
//			next = map[current][i].first;
//		}
//	}
//
//	return next;
//}

void nojam1753::solution()
{
	int INF = 30000000;
	int vertex;
	int edge;
	int start;
	int from;
	int to;
	int weight;
	scanf_s("%d %d", &vertex, &edge);
	scanf_s("%d", &start);

	start--;
	std::vector<std::vector<std::pair<int, int>>> temp(vertex);
	std::vector<int> distance(vertex, INF);
	std::vector<bool> visit(vertex);

	for (int i = 0; i < edge; i++) {
		scanf_s("%d %d %d", &from, &to, &weight);
		temp[from - 1].push_back(std::make_pair(to - 1, weight));
	}

	nojam1753::dijkstra(start, temp);

	/*int current = start;

	for (int i = 0; i < temp[start].size(); i++) {
		distance[temp[start][i].first] = temp[start][i].second;
	}

	while (true) {
		visit[current] = true;
		current = nojam1753::get_next(current, vertex, temp, visit);
		if (current == -1)
			break;
		for (int i = 0; i < temp[current].size(); i++) {
			distance[temp[current][i].first] 
				= std::min(distance[temp[current][i].first], distance[current] + temp[current][i].second);
		}
	}

	for (int i = 0; i < vertex; i++) {
		if (distance[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", distance[i]);
		}
	}*/

}
