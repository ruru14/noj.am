#include "7576.h"

int n, m;
int day = 0;
std::queue<int> queue;
bool* visit;
int* map;

void nojam7576::solution() {
	scanf("%d %d", &n, &m);
	map = new int[n * m];
	visit = new bool[n * m];

	for (int i = 0; i < m * n; i++) {
		visit[i] = false;
	}

	for (int i = 0; i < n * m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 1) {
			queue.push(i);
		}
		map[i] = tmp;
	}

	while (!queue.empty()) {
		int current = queue.front();
		int age = INT_MAX;
		queue.pop();
		if (!visit[current]) {
			visit[current] = !visit[current];
			//UP (index > n)
			if (current >= n) {
				if (map[current - n] > 0 && map[current - n] < age) {
					age = map[current - n];
				}
				if (!visit[current - n] && map[current - n] != -1) {
					queue.push(current - n);
				}
			}
			//Left (index % n != 0)
			if (current % n != 0) {
				if (map[current - 1] > 0 && map[current - 1] < age) {
					age = map[current - 1];
				}
				if (!visit[current - 1] && map[current - 1] != -1) {
					queue.push(current - 1);
				}
			}
			//Down (index < n * m - n)
			if (current < n * m - n) {
				if (map[current + n] > 0 && map[current + n] < age) {
					age = map[current + n];
				}
				if (!visit[current + n] && map[current + n] != -1) {
					queue.push(current + n);
				}
			}
			//Right (index % n != n-1)
			if (current % n != n - 1) {
				if (map[current + 1] > 0 && map[current + 1] < age) {
					age = map[current + 1];
				}
				if (!visit[current + 1] && map[current + 1] != -1) {
					queue.push(current + 1);
				}
			}
			if (map[current] == 0 | map[current] > age) {
				map[current] = age + 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i * n + j] == 0) {
				printf("-1");
				return;
			}
			if (day < map[i * n + j]) {
				day = map[i * n + j];
			}
		}
	}

	printf("%d", day - 1);

}