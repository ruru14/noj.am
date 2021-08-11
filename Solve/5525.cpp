#include "5525.h"

int n, m;
char s[1000001];

void nojam5525::solution()
{
	int ans = 0, index = 0;
	bool flag = true;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%s", s);
	std::vector<int> arr;

	n = n * 2 + 1;

	for (int i = 0; i < m; i++) {
		if (flag && s[i] == 'I') {
			flag = !flag;
			index++;
		}
		else if (!flag && s[i] == 'O') {
			flag = !flag;
			index++;
		}
		else {
			if (index != 0) {
				if (index % 2 == 0)
					index--;
				arr.push_back(index);
				i--;
			}
			flag = true;
			index = 0;
		}
	}

	if (index > 2) {
		if (index % 2 == 0)
			index--;
		arr.push_back(index);
	}

	for (int i = 0; i < arr.size(); i++) {
		int tmp = arr[i];
		while (arr[i] >= n & tmp >= n) {
			tmp -= 2;
			ans++;
		}
	}
	printf("%d", ans);
}
