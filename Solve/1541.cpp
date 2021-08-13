#include "1541.h"

void nojam1541::solution()
{
	std::stack<int> st;
	std::vector<std::string> arr;
	std::string str = "";
	char input;
	int sum = 0;

	do {
		input = getchar();
		if (input == '-') {
			arr.push_back(str);
			arr.push_back("-");
			str.clear();
		}
		else if (input == '+') {
			arr.push_back(str);
			arr.push_back("+");
			str.clear();
		}
		else {
			str.push_back(input);
		}
	} while (input != '\n');

	str.pop_back();
	arr.push_back(str);
	
	std::vector<std::string>::iterator iter = arr.begin();

	while (iter != arr.end()) {
		if (*iter == "+") {
			int tmp1 = std::stoi(*(iter - 1));
			int tmp2 = std::stoi(*(iter + 1));
			std::string tmp3 = std::to_string(tmp1 + tmp2);
			iter->swap(tmp3);
			iter = arr.erase(iter - 1);
			iter = arr.erase(iter + 1);
		}
		else {
			iter++;
		}
	}

	iter = arr.begin();
	sum = std::stoi(*iter);
	iter++;

	while (iter != arr.end()) {
		if (*iter != "-") {
			sum -= std::stoi(*iter);
		}
		iter++;
	}
	printf("%d", sum);
}
