#include "1874.h"

void nojam1874::solution()
{
	int n, cur = 1;
	std::stack<int> stack;
	std::vector<char> log;
	scanf("%d", &n);
	

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (stack.empty()) {
			stack.push(cur++);
			log.push_back('+');
		}
		if (stack.top() > tmp) {
			printf("NO\n");
			return;
		}
		while (stack.top() != tmp | tmp > cur) {
			stack.push(cur++);
			log.push_back('+');
		}
		if (stack.top() = tmp) {
			stack.pop();
			log.push_back('-');
		}
	}

	for (auto i : log) {
		printf("%c\n", i);
	}
}
