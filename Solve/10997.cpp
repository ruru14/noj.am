#include "10997.h"

void nojam10997::solution()
{
	int n;
	scanf("%d", &n);
	int arr[500][500] = { {0,}, };
	int start_y = 0;
	int start_x = 4 * n - 2;
	int turn = 4 * n - 2;
	int dx = -1;
	int dy = 0;
	int left = 4 * n - 2, right = 4 * n - 2, down = 4 * n, up = 4 * n;

	if (n == 1) {
		printf("*");
		return;
	}

	//left 13 11 7 3
	//left : 
	//right : down = -2, up = -2
	//down : left = -2, right = -2;
	//up : left = -2, right = -2;

	while (turn--) {
		if (dx == -1) {
			for (int i = 0; i < left; i++) {
				arr[start_y][start_x] = 1;
				if (i - 1 != left) {
					start_y += dy;
					start_x += dx;
				}
			}
			dx = 0;
			dy = 1;
			up -= 2;
			down -= 2;
			//left -= 3;
		}
		else if (dy == 1) {
			for (int i = 0; i < down; i++) {
				arr[start_y][start_x] = 1;
				if (i - 1 != down) {
					start_y += dy;
					start_x += dx;
				}
			}
			dx = 1;
			dy = 0;
			right -= 2;
			left -= 2;
			//down -= 4;
		}
		else if (dx == 1) {
			for (int i = 0; i < right; i++) {
				arr[start_y][start_x] = 1;
				if (i - 1 != right) {
					start_y += dy;
					start_x += dx;
				}
			}
			dx = 0;
			dy = -1;
			down -= 2;
			up -= 2;
			//right -= 4;
		}
		else if (dy == -1) {
			for (int i = 0; i < up; i++) {
				arr[start_y][start_x] = 1;
				if (i - 1 != up) {
					start_y += dy;
					start_x += dx;
				}
			}
			dx = -1;
			dy = 0;
			left -= 2;
			right -= 2;
			//up -= 4;
		}
	}

	arr[start_y][start_x] = 1;

	for (int i = 0; i < 4 * n - 1; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			if (arr[i][j] == 0) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}

	//1 : 1 * 1 / 1
	//2 : 5 * 7 / 2, 4 / 5
	//3 : 9 * 11 / 4, 6 / 9
	//4 : 13 * 15 / 6, 8 / 13
	//3 3 5 5 7 7 9 9 11 9
}
