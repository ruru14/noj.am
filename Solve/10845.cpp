#include "10845.h"

void nojam10845::solution()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, num;
	std::string func;
	std::queue<int> queue;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> func;
		if (func == "push") {
			std::cin >> num;
			queue.push(num);
		}
		else if (func == "pop") {
			if (queue.empty())
				std::cout << "-1\n";
			else {
				std::cout << queue.front() << "\n";
				queue.pop();
			}
		}
		else if (func == "size") {
			std::cout << queue.size() << "\n";
		}
		else if (func == "empty") {
			std::cout << queue.empty() << "\n";
		}
		else if (func == "front") {
			if (queue.empty())
				std::cout << "-1\n";
			else {
				std::cout << queue.front() << "\n";
			}
		}
		else if (func == "back") {
			if (queue.empty())
				std::cout << "-1\n";
			else {
				std::cout << queue.back() << "\n";
			}
		}
	}
}
