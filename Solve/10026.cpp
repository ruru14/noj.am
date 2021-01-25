#include "../AlgorithmStudy.h"

namespace nojam10026 {
	static void solution() {
		// Input
		int n;
		int max = -1;
		scanf_s("%d", &n);
		getchar();

		std::vector<int> image;
		std::vector<std::vector<int>> adjList(n * n);
		for (int i = 0; i < n * n + n; i++) {
			char temp = getchar();
			if (temp == '\n') {
				continue;
			}
			else {
				if (temp == 'R') {
					image.push_back(0);
				}
				else if (temp == 'G') {
					image.push_back(1);
				}
				else if (temp == 'B') {
					image.push_back(2);
				}
			}
		}

		// Make Adjacency List
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != 0) { // Up
					adjList.at(i * n + j).push_back((i - 1) * n + j);
				}
				if (i != n - 1) { // Down
					adjList.at(i * n + j).push_back((i + 1) * n + j);
				}
				if (j != 0) { // Left
					adjList.at(i * n + j).push_back(i * n + j - 1);
				}
				if (j != n - 1) { // Right
					adjList.at(i * n + j).push_back(i * n + j + 1);
				}
			}
		}

		std::queue<int> queue;
		std::vector<bool> bfsVisit(n * n);
		std::vector<int> area(n * n);
		queue.push(0);

		while (!queue.empty()) {
			int current = queue.front();
			queue.pop();

			if (!bfsVisit[current]) {
				bfsVisit[current] = true;

				for (int i = 0; i < adjList.at(current).size(); i++) {
					if (!bfsVisit[adjList.at(current)[i]]) {
						queue.push(adjList.at(current)[i]);
						int tempA = (current % n == n - 1 ? image[current - 1] : -1);
						//int tempA = (current % n == n - 1 ? 0 : image[current - 1]);
						int tempB = (current < n ? -1 : image[current - n]);
						if ((image[current] != (current % n == n - 1 ? image[current - 1] : -1))&
							(image[current] != (current < n ? -1 : image[current - n]))) {
							int areaLeft = (current % n == n - 1 ? area[current - 1] : 0);
							int areaUpper = (current < n ? 0 : area[current - n]);
							area[current] = (areaLeft > areaUpper ? areaLeft : areaUpper) + 1;
							if (area[current] > max) {
								max = area[current];
							}
						}
					}
				}
			}
		}

		printf("%d", max + 1);

		/*for (int i = 0; i < area.size(); i++) {
			printf("%d", area[i]);
			if (i % n == n - 1) {
				printf("\n");
			}
		}*/



		/*printf("\n");

		for (int i = 0; i < image.size(); i++) {
			printf("%d", image[i]);
			if (i % n == n-1) {
				printf("\n");
			}
		}*/
	}
}