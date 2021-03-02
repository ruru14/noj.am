#include "2776.h"

void nojam2776::solution() {
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int noteNum;
		int note;
		std::vector<int> mem;
		scanf("%d", &noteNum);
		for (int j = 0; j < noteNum; j++) {
			scanf("%d", &note);
			mem.push_back(note);
		}

		std::sort(mem.begin(), mem.end());

		int testNum;
		int test;
		scanf("%d", &testNum);
		for (int j = 0; j < testNum; j++) {
			scanf("%d", &test);
			if (std::binary_search(mem.begin(), mem.end(), test)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}
}
