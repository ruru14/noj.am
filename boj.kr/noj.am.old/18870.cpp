#include "18870.h"

int compare(const void* a, const void* b)
{
	const long long* x = (long long*)a;
	const long long* y = (long long*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

void nojam18870::solution()
{
	int n;
	scanf("%d", &n);
	std::vector<long long> arr1, arr2;
	std::unordered_map<long long, long long> map;
	long long adr = 0, pre;

	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		arr1.push_back(tmp);
		arr2.push_back(tmp);
	}

	std::sort(arr1.begin(), arr1.end());

	pre = arr1[0];
	for (int i = 0; i < n; i++) {
		if (arr1[i] == pre) {
			map[arr1[i]] = adr;
		}
		else {
			map[arr1[i]] = ++adr;
		}
		pre = arr1[i];
	}

	for (int i = 0; i < n; i++) {
		printf("%lld ", map[arr2[i]]);
	}
}
