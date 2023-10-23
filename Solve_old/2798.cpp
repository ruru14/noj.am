#include "2798.h"

void nojam2798::solution()
{
	int n, m, flag = -1;
	std::vector<int> cards;
	std::vector<int> comb;
	std::vector<int> sum;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < 3; i++) {
		comb.push_back(1);
	}

	for (int i = 0; i < n - 3; i++) {
		comb.push_back(0);
	}

	std::sort(comb.begin(), comb.end());

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		cards.push_back(tmp);
	}

	do {
		int tmp = 0;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 1) {
				tmp += cards[i];
			}
		}
		sum.push_back(tmp);
	} while (std::next_permutation(comb.begin(), comb.end()));

	std::sort(sum.begin(), sum.end());

	for (int i = 0; i < sum.size(); i++) {
		if (sum[i] > m) {
			printf("%d", sum[i - 1]);
			flag = 0;
			break;
		}
	}
	if (flag == -1) {
		printf("%d", sum[sum.size() - 1]);
	}

}
