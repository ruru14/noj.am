#include "1259.h"

void nojam1259::solution()
{
	std::string input;
	std::string comp;
	std::getline(std::cin, input);
	while (input != "0") {
		comp.clear();
		for (int i = input.size()-1; i >= 0; i--) {
			if (i == input.size() - 1 && input[i] == '0') {
				continue;
			}
			comp += input[i];
		}
		if (comp.compare(input) == 0) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
		std::getline(std::cin, input);
	}
}
