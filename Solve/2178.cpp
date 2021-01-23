#include "../AlgorithmStudy.h"

namespace nojam2178 {
	static void solution() {
		int width;
		int height;
		scanf_s("%d %d", &height, &width);
		getchar();

		// Input
		std::vector<int> map;
		std::vector<std::vector<int>> adjList(height * width);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width + 1; j++) {
				char temp = getchar();
				if (temp == '\n') {
					continue;
				}
				else {
					map.push_back(temp - 48);
				}
			}
		}
		// Make Adjacency List
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i * width + j] == 1) {
					if (i != 0) { // Up
						if (map[(i - 1) * width + j] == 1) {
							adjList.at(i * width + j).push_back((i - 1) * width + j);
							//adjList.at((i - 1) * width + j).push_back(i * width + j);
						}
					}
					if (i != height - 1) { // Down
						if (map[(i + 1) * width + j] == 1) {
							adjList.at(i * width + j).push_back((i + 1) * width + j);
							//adjList.at((i + 1) * width + j).push_back(i * width + j);
						}
					}
					if (j != 0) { // Left
						if (map[i * width + j - 1]) {
							adjList.at(i * width + j).push_back(i * width + j - 1);
							//adjList.at(i * width + j - 1).push_back(i * width + j);
						}
					}
					if (j != width - 1) { // Right
						if (map[i * width + j + 1]) {
							adjList.at(i * width + j).push_back(i * width + j + 1);
							//adjList.at(i * width + j + 1).push_back(i * width + j);
						}
					}
				}
			}
		}

		// Length arr Init
		std::vector<int> length;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				length.push_back(-1);
			}
		}
		length[0] = 0;

		// BFS
		std::queue<int> queue;
		int way = 0;

		queue.push(0);
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

		printf("%d", length[length.size() - 1] + 1);
	}
}