#include "1966.h"

void nojam1966::solution()
{
	int tc;
	std::vector<std::pair<int, int>> queue;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		int n, m, tmp = 1;
		queue.clear();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int prior;
			scanf("%d", &prior);
			queue.push_back(std::make_pair(i, prior));
		}

		while (!queue.empty()) {
			bool flag = true;
			if (queue.size() == 1) {
				printf("%d", tmp);
				break;
			}
			while (flag) {
				for (int i = 1; i < queue.size(); i++) {
					if (queue.front().second < queue[i].second) {
						auto tmp = queue.front();
						std::pair<int, int> page = std::make_pair(tmp.first, tmp.second);
						queue.erase(queue.begin());
						queue.push_back(page);
						break;
					}
					if (i == queue.size() - 1) {
						flag = !flag;
					}
				}
			}
			/*for (int i = 0; i < queue.size(); i++) {
				printf("<%d %d>\n", queue[i].first, queue[i].second);
			}*/
			/*for (int i = 0; i < queue.size(); i++) {
				if (queue.front().second < queue[i].second) {
					auto tmp = queue.begin();
					std::pair<int, int> page = std::make_pair(tmp->first, tmp->second);
					queue.erase(tmp);
					queue.push_back(page);
					break;
				}
			}*/
			if (queue.front().first == m) {
				//printf("Elm : %d %d / ANS : %d\n", queue.front().first, queue.front().second, tmp);
				printf("ans:%d\n", tmp);
				break;
			}
			queue.erase(queue.begin());
			tmp++;
		}
	}
}
