#include "9012.h"

void nojam9012::solution()
{
	std::string input;
	std::stack<char> st;
	bool flag = true;
	int n;
	scanf("%d", &n);
	scanf("%d");

	for (int i = 0; i < n; i++) {
		std::getline(std::cin, input);
		while (!st.empty()) st.pop();
		flag = true;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				st.push(input[i]);
				continue;
			}
			if (input[i] == ')') {
				if (st.empty()) {
					printf("NO\n");
					flag = false;
					break;
				}
				if (st.top() == '(') {
					st.pop();
					continue;
				}
			}
		}
		if (st.empty() & flag) {
			printf("YES\n");
		}
		else if (!st.empty() & flag) {
			printf("NO\n");
		}
	}
}
