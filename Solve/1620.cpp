#include "1620.h"

std::unordered_map<std::string, int> dict;
std::string dict_rev[100001];

void nojam1620::solution()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::cin >> tmp;
		dict.insert(std::make_pair(tmp, i + 1));
		dict_rev[i] = tmp;
	}

	for (int i = 0; i < m; i++) {
		std::string tmp;
		std::cin >> tmp;
		if (tmp[0] >= 'A') { // Name
			auto val = dict.find(tmp);
			std::cout << val->second << "\n";
		}
		else {
			int index = std::stoi(tmp);
			index--;
			std::cout << dict_rev[index] << "\n";
		}
	}
}
