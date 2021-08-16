#include "2579.h"

void nojam2579::solution()
{
	int n;
	scanf("%d", &n);
	int* stair = new int[n + 2];
	int* score = new int[n + 2];
	stair[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &stair[i]);
	}
	score[0] = 0;
	score[1] = stair[1];
	score[2] = stair[2] + stair[1];

	for (int i = 3; i < n + 1; i++) {
		score[i] = std::max(stair[i] + stair[i - 1] + score[i - 3], stair[i] + score[i - 2]);
	}

	printf("\n%d", score[n]);

	/*
	* score[n] = stair[n] + stair[n-1] + score[n-3]
	* score[n] = stair[n] + score[n-2]
	*/
}
