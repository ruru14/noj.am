#include "18111.h"

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

void nojam18111::solution()
{
	int n, m, b, max;
	int sum = 0;
	scanf("%d %d %d", &n, &m, &b);
	std::vector<std::vector<int>> field(n);
	std::vector<std::pair<int, int>> cost;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
			field[i].push_back(tmp);
		}
	}

	max = (int)floor(((double)sum + b) / (double)(n * m));

	for (int i = 0; i <= (max > 256 ? 256 : max); i++) {
		int time = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				time += abs(field[j][k] - i) * (field[j][k] < i ? 1 : 2);
			}
		}
		cost.push_back(std::make_pair(time, i));
	}

	std::sort(cost.begin(), cost.end(), compare);

	printf("%d %d", cost[cost.size() - 1].first, cost[cost.size() - 1].second);
	/*for (int i = 0; i < cost.size(); i++) {
		printf("%d %d\n", cost[i].first, cost[i].second);
	}*/

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", field[i][j]);
		}
		printf("\n");
	}*/

}
