#include "17219.h"

void nojam17219::solution()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::unordered_map<std::string, std::string> dict;

	for (int i = 0; i < n; i++) {
		char site[21];
		char pwd[21];
		scanf("%s %s", site, pwd);
		std::string tmp_site(site);
		std::string tmp_pwd(pwd);
		dict.insert(std::make_pair(tmp_site, tmp_pwd));
	}

	for (int i = 0; i < m; i++) {
		char site[21];
		scanf("%s", site);
		std::string tmp_site(site);
		printf("%s\n", dict.find(tmp_site)->second.c_str());
	}
}
