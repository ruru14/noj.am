#include "1107.h"

int trouble[11] = { 0, };

bool button(std::string num) {

	for (int i = 0; i < 11; i++) {
		if (trouble[i] == 1) {
			if (num.find(std::to_string(i).c_str()) != std::string::npos) {
				return false;
			}
		}
	}
	return true;
}

void nojam1107::solution()
{
	int n, m;
	int plus = 0, minus = 0, h = 0;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		trouble[tmp] = 1;
	}

	h = (int)abs(100 - n);

	int tmp_plus = n;
	while (!button(std::to_string(tmp_plus)) | tmp_plus > 500000) {
		tmp_plus++;
		minus++;
	}

	int tmp_minus = n;
	while (!button(std::to_string(tmp_minus)) | tmp_minus < 0) {
		tmp_minus--;
		plus++;
	}


	if (h < minus && h < plus) {
		printf("%d", h);
	}
	else {
		printf("%d", (plus>minus? minus : plus) + std::to_string(n).size());
	}
}
