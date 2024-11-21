#include "10815.h"

void nojam10815::solution()
{
	int size;
	int test_case;
	int right;
	int left;
	int mid;
	int index;
	std::vector<int> arr;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end());

	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		index = -1;
		left = 0;
		right = size - 1;
		int tmp;
		scanf("%d", &tmp);

		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] == tmp) {
				index = mid;
				break;
			}
			else if (arr[mid] < tmp) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		if (index == -1) {
			printf("0\n");
		}
		else {
			printf("1\n");
		}
	}
}
