#include "2667.h"

bool visit[626];
int n, num = 0;
std::vector<int> count;
std::vector<int> map;

void numbering(int index) {
	visit[index] = !visit[index];
	count[num]++;
	//UP (index > n)
	if (index >= n) {
		if (!visit[index - n] && map[index - n] == 1) {
			numbering(index - n);
		}
	}
	//Left (index % n != 0)
	if (index % n != 0) {
		if (!visit[index - 1] && map[index - 1] == 1) {
			numbering(index - 1);
		}
	}
	//Down (index < n * n - n)
	if (index < n * n - n) {
		if (!visit[index + n] && map[index + n] == 1) {
			numbering(index + n);
		}
	}
	//Right (index % n != n-1)
	if (index % n != n - 1) {
		if (!visit[index + 1] && map[index + 1] == 1) {
			numbering(index + 1);
		}
	}
}

void nojam2667::solution()
{
	scanf("%d", &n);
	getchar();

	// Input
	std::vector<std::vector<int>> adjList(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			char temp = getchar();
			if (temp == '\n') {
				continue;
			}
			else {
				map.push_back(temp - 48);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i * n + j] && map[i*n+j] != 0) {
				count.push_back(0);
				numbering(i * n + j);
				num++;
			}
		}
		//printf("\n");
	}

	printf("%d\n", num);
	std::sort(count.begin(), count.end());
	for (int i = 0; i < num; i++) {
		printf("%d\n", count[i]);
	}

	// Make Adjacency List
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		if (map[i * n + j] == 1) {
	//			if (i != 0) { // Up
	//				if (map[(i - 1) * n + j] == 1) {
	//					adjList.at(i * n + j).push_back((i - 1) * n + j);
	//				}
	//			}
	//			if (i != n - 1) { // Down
	//				if (map[(i + 1) * n + j] == 1) {
	//					adjList.at(i * n + j).push_back((i + 1) * n + j);
	//				}
	//			}
	//			if (j != 0) { // Left
	//				if (map[i * n + j - 1]) {
	//					adjList.at(i * n + j).push_back(i * n + j - 1);
	//				}
	//			}
	//			if (j != n - 1) { // Right
	//				if (map[i * n + j + 1]) {
	//					adjList.at(i * n + j).push_back(i * n + j + 1);
	//				}
	//			}
	//		}
	//	}
	//}

	
}
