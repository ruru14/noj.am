#include "1764.h"

void nojam1764::solution()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::unordered_map<std::string, int> map;
	std::vector<std::string> dup;
	
	for (int i = 0; i < n; i++) {
		char input[21];
		scanf("%s", input);
		std::string tmp(input);
		map.insert(std::make_pair(tmp, i));
	}

	for (int i = 0; i < m; i++) {
		char input[21];
		scanf("%s", input);
		std::string tmp(input);
		auto a = map.find(tmp);
		if (a != map.end()) {
			dup.push_back(tmp);
		}
	}
	
	std::sort(dup.begin(), dup.end());

	printf("%d\n", dup.size());
	for (int i = 0; i < dup.size(); i++) {
		printf("%s\n", dup[i].c_str());
	}
}
