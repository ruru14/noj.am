#include "../AlgorithmStudy.h"

namespace nojam2178 {
	static void solution() {
		int width;
		int height;
		scanf_s("%d %d", &height, &width);
		getchar();

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

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				for (int k = 0; k < adjList.at(i * width + j).size(); k++) {
					printf("%d %d\n", i * width + j, adjList.at(i * width + j)[k]);
				}
			}
		}
	}
}