#include "10866.h"

void nojam10866::solution()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n, num;
	std::string func;
	std::deque<int> deque;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> func;
		if (func == "push_front") {
			std::cin >> num;
			deque.push_front(num);
		}
		else if (func == "push_back") {
			std::cin >> num;
			deque.push_back(num);
		}
		else if (func == "pop_front") {
			if (deque.empty())
				std::cout << "-1\n";
			else {
				std::cout << deque.front() << "\n";
				deque.pop_front();
			}
		}
		else if (func == "pop_back") {
			if (deque.empty())
				std::cout << "-1\n";
			else {
				std::cout << deque.back() << "\n";
				deque.pop_back();
			}
		}
		else if (func == "size") {
			std::cout << deque.size() << "\n";
		}
		else if (func == "empty") {
			std::cout << deque.empty() << "\n";
		}
		else if (func == "front") {
			if (deque.empty())
				std::cout << "-1\n";
			else {
				std::cout << deque.front() << "\n";
			}
		}
		else if (func == "back") {
			if (deque.empty())
				std::cout << "-1\n";
			else {
				std::cout << deque.back() << "\n";
			}
		}
	}
}
