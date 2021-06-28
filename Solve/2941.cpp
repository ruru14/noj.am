#include "2941.h"

void nojam2941::solution()
{
	int len = 0;
	std::string str;
	std::cin >> str;
	for (int i = 0; i < str.size(); i++) {
		len++;
		if (i != str.size() - 1) {
			if (str[i] == 'c') {
				if (str[i + 1] == '=' || str[i + 1] == '-') {
					i++;
					continue;
				}
			}
			if (str[i] == 'd') {
				if (str[i + 1] == '-') {
					i++;
					continue;
				}
			}
			if (str[i] == 'l' || str[i] == 'n') {
				if (str[i + 1] == 'j') {
					i++;
					continue;
				}
			}
			if (str[i] == 's' || str[i] == 'z') {
				if (str[i + 1] == '=') {
					i++;
					continue;
				}
			}
		}
		if (i != str.size() - 2) {
			if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
				i += 2;
				continue;
			}
		}
	}

	std::cout << len;
}
