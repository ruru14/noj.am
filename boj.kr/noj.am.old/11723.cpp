#include "11723.h"

void nojam11723::solution()
{
	int m;
	scanf("%d", &m);
	std::bitset<21> set;
	
	for (int i = 0; i < m; i++) {
		char tmp_order[30];
		int tmp_elm;
		scanf("%s", tmp_order);
		if (strcmp(tmp_order, "all") == 0) {
			set.set();
		}
		else if (strcmp(tmp_order, "empty") == 0) {
			set.reset();
		}
		else {
			scanf("%d", &tmp_elm);
			if (strcmp(tmp_order, "add") == 0) {
				set.set(tmp_elm);
			}
			else if (strcmp(tmp_order, "remove") == 0) {
				set.reset(tmp_elm);
			}
			else if (strcmp(tmp_order, "check") == 0) {
				if (set.test(tmp_elm)) {
					printf("1\n");
				}
				else {
					printf("0\n");
				}
			}
			else if (strcmp(tmp_order, "toggle") == 0) {
				set.flip(tmp_elm);
			}
		}
	}
}
