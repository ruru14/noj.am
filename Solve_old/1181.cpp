#include "1181.h"

void nojam1181::solution()
{
	int n;
	std::vector<std::pair<int, std::string>> dict;
	std::string flag;
	scanf("%d", &n);
	scanf("%d");

	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::getline(std::cin, tmp);
		dict.push_back(std::make_pair(tmp.size(), tmp));
	}

	printf("\n");
	std::sort(dict.begin(), dict.end());

	for (int i = 0; i < dict.size(); i++) {
		if (flag == dict[i].second) {
			continue;
		}
		printf("%s\n", dict[i].second.c_str());
		//std::cout << dict[i].second << "\n";
		flag = dict[i].second;
	}
}
