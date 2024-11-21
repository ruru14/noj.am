#include "4949.h"

void nojam4949::solution()
{
	std::string input;
	std::stack<char> st;
	bool flag = true;
	std::getline(std::cin, input);

	while (input.size() != 1 & input[0] != '.') {
		while (!st.empty()) st.pop();
		flag = true;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(' | input[i] == '[') {
				st.push(input[i]);
				continue;
			}
			if (input[i] == ')') {
				if (st.empty()) {
					printf("no\n");
					flag = false;
					break;
				}
				if (st.top() == '[') {
					printf("no\n");
					flag = false;
					break;
				}
				if (st.top() == '(') {
					st.pop();
					continue;
				}
			}
			if (input[i] == ']') {
				if (st.empty()) {
					printf("no\n");
					flag = false;
					break;
				}
				if (st.top() == '(') {
					printf("no\n");
					flag = false;
					break;
				}
				if (st.top() == '[') {
					st.pop();
					continue;
				}
			}
		}
		if (st.empty() & flag) {
			printf("yes\n");
		}
		else if (!st.empty() & flag) {
			printf("no\n");
		}
		std::getline(std::cin, input);
	}
}
