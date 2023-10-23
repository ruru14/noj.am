#include "4153.h"

bool is_right_angle(int a, int b, int c) {
	std::vector<int> tmp;
	tmp.push_back(a);
	tmp.push_back(b);
	tmp.push_back(c);
	std::sort(tmp.begin(), tmp.end());
	if ((int)pow(tmp[0], 2) + (int)pow(tmp[1], 2) == (int)pow(tmp[2], 2)) {
		return true;
	}
	return false;
}

void nojam4153::solution()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != 0 && b != 0 && c != 0) {
		if (is_right_angle(a, b, c)) {
			printf("right\n");
		}
		else {
			printf("wrong");
		}
		scanf("%d %d %d", &a, &b, &c);
	}
}
