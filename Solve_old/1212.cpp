#include "1212.h"

void nojam1212::solution()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int dec;
	std::string input;
	std::getline(std::cin, input);
	for (int i = 0; i < input.size(); i++) {
		dec = input[i] - '0';
		std::bitset<3> bin(dec);
		std::string tmp = bin.to_string();
		if (i == 0) {
			if (bin.any())
				tmp = tmp.substr(tmp.find('1'));
			else
				tmp = "0";
		}
		std::cout << tmp;
	}

}
