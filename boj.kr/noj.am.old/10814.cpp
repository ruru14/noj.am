#include "10814.h"

void nojam10814::solution()
{
	int n;
	std::vector<std::pair<int, std::pair<int, std::string>>> dict;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp_age;
		std::string tmp_name;
		std::cin >> tmp_age >> tmp_name;
		dict.push_back(std::make_pair(tmp_age, std::make_pair(i, tmp_name)));
	}
	std::sort(dict.begin(), dict.end());

	for (int i = 0; i < dict.size(); i++) {
		std::cout << dict[i].first << " " << dict[i].second.second << "\n";
	}

}
