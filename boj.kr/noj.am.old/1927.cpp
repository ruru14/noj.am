#include "1927.h"

void nojam1927::solution()
{
	int n, order, size = 0;
	scanf("%d", &n);
	std::vector<int> heap(300001, INT_MAX);

	while (n--) {
		scanf("%d", &order);
		if (order == 0) {
			if (size == 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", heap[1]);
				heap[1] = heap[size];
				heap[size--] = INT_MAX;
				int tmp = 1;
				while (heap[tmp] > heap[tmp * 2] | heap[tmp] > heap[tmp * 2 + 1]) {
					int flag = heap[tmp * 2] < heap[tmp * 2 + 1] ? 1 : 2;
					if (flag == 1) {
						int tmp2 = heap[tmp * 2];
						heap[tmp * 2] = heap[tmp];
						heap[tmp] = tmp2;
						tmp = tmp * 2;
					}
					else if (flag == 2) {
						int tmp2 = heap[tmp * 2 + 1];
						heap[tmp * 2 + 1] = heap[tmp];
						heap[tmp] = tmp2;
						tmp = tmp * 2 + 1;
					}
				}
			}
		}
		else {
			heap[++size] = order;
			int tmp = size;
			while (heap[tmp] < heap[tmp / 2] & tmp != 1) {
				int tmp2 = heap[tmp];
				heap[tmp] = heap[tmp / 2];
				heap[tmp / 2] = tmp2;
				tmp = tmp / 2;
			}
		}
	}
}
