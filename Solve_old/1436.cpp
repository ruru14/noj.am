#include "1436.h"

void nojam1436::solution()
{
	int n, ans = 0;;
	scanf("%d", &n);

	for (int i = 665; true; i++) {
		if (std::to_string(i).find("666") != std::string::npos) {
			ans++;
			if (ans == n) {
				printf("%d", i);
				break;
			}
		}
	}
}
