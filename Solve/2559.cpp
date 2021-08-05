#include "2559.h"

void nojam2559::solution()
{
	int n, k;
	int max = INT_MIN;
	int ptr1, ptr2;
	int sum = 0;
	scanf("%d %d", &n, &k);
	std::vector<int> arr;
	ptr1 = 0;
	ptr2 = k - 1;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	for (int i = ptr1; i < k; i++) {
		sum += arr[i];
	}

	if (max < sum) {
		max = sum;
	}

	for (int i = 0; i < n - k; i++) {
		ptr2++;
		sum += arr[ptr2];
		sum -= arr[ptr1];
		ptr1++;
		if (max < sum) {
			max = sum;
		}
	}

	printf("%d", max);
}
