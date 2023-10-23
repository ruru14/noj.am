#include "10828.h"

void nojam10828::solution()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, num;
	std::string func;
	std::stack<int> st;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> func;
		if (func == "push") {
			std::cin >> num;
			st.push(num);
		}
		else if (func == "pop") {
			if (st.empty())
				std::cout << "-1\n";
			else {
				std::cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (func == "size") {
			std::cout << st.size() << "\n";
		}
		else if (func == "empty") {
			std::cout << st.empty() << "\n";
		}
		else if (func == "top") {
			if (st.empty())
				std::cout << "-1\n";
			else {
				std::cout << st.top() << "\n";
			}
		}
	}
}
