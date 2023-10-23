#include "11286.h"

void nojam11286::solution()
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
				while ((((int)abs(heap[tmp]) > (int)abs(heap[tmp * 2])) | ((int)abs(heap[tmp]) > (int)abs(heap[tmp * 2 + 1]))) & (tmp < size)) {
					int flag;
					if ((int)abs(heap[tmp * 2]) == (int)abs(heap[tmp * 2 + 1])) {
						flag = heap[tmp * 2] < heap[tmp * 2 + 1] ? 1 : 2;
					}
					else {
						flag = (int)abs(heap[tmp * 2]) < (int)abs(heap[tmp * 2 + 1]) ? 1 : 2;
					}
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
			while (((int)abs(heap[tmp]) <= (int)abs(heap[tmp / 2])) & (tmp != 1)) {
				if (((int)abs(heap[tmp]) == (int)abs(heap[tmp / 2])) &
					heap[tmp] < heap[tmp / 2]) {
					break;
				}
				int tmp2 = heap[tmp];
				heap[tmp] = heap[tmp / 2];
				heap[tmp / 2] = tmp2;
				tmp = tmp / 2;
			}
		}
	}
}
