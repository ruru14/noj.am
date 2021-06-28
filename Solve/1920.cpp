#include "1920.h"

void nojam1920::solution()
{
	int size;
	int test_case;
	int right;
	int left;
	int mid;
	std::vector<int> arr;
	scanf("%d", &size);
	mid = size / 2;

	for (int i = 0; i < size; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end());

	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		left = 0;
		right = size - 1;
		int tmp;
		scanf("%d", &tmp);
		if (tmp >= arr[mid]) { // Start right
			for (int i = right; i >= mid; i--) {
				if (arr[i] == tmp) {
					printf("1 1\n");
					break;
				}
				if (arr[i] < tmp) {
					printf("0 2\n");
					break;
				}
			}
		}
		else { // Start left
			for (int i = 0; i <= mid; i++) {
				if (arr[i] == tmp) {
					printf("1 3\n");
					break;
				}
				if (arr[i] > tmp) {
					printf("0 4\n");
					break;
				}
			}
		}
	}
}
