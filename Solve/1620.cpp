#include "1620.h"

void nojam1620::solution()
{
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%d");

	//std::map<std::string, std::string> dict;
	//std::map<std::string, std::string> dict_rev;
	//std::unordered_map<std::string, int> dict;

	std::vector<std::pair<std::string, int>> dict;

	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::getline(std::cin, tmp);
		dict.push_back(std::make_pair(tmp, i + 1));
		//dict.insert(std::make_pair(tmp, i + 1));
	}

	/*for (auto i : dict) {
		printf("%s %s\n", i.first.c_str(), i.second.c_str());
	}*/

	for (int i = 0; i < m; i++) {
		std::string tmp;
		std::getline(std::cin, tmp);
		if (tmp[0] >= 'A') { // Name
			for (auto i : dict) {
				if (i.first == tmp) {
					printf("%d\n", i.second);
				}
			}
		}
		else {
			int index = std::stoi(tmp);
			for (auto i : dict) {
				if (i.second == index) {
					printf("%s\n", i.first.c_str());
				}
			}
		}
	}
}
