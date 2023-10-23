#include "17390.h"

int mem[300001] = { 0, };

void nojam17390::solution()
{
	int n, m, sum = 0;;
	scanf("%d %d", &n, &m);
	std::vector<int> arr;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		mem[i + 1] = sum;
	}

	for (int i = 0; i < m; i++) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		printf("%d\n", mem[end] - mem[begin - 1]);
	}
}
