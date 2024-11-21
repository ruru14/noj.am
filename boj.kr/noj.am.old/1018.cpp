#include "1018.h"

int n, m;
std::vector<std::string> board;

int start_black(int x, int y) {
	bool flag = true;
	int swap = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			switch (flag)
			{
			case true:
				if (board.at(i)[j] == 'W') {
					swap++;
				}
				flag = !flag;
				continue;
			case false:
				if (board.at(i)[j] == 'B') {
					swap++;
				}
				flag = !flag;
				continue;
			}
		}
		flag = !flag;
	}
	return swap;
}

int start_white(int x, int y) {
	bool flag = false;
	int swap = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			switch (flag)
			{
			case true:
				if (board.at(i)[j] == 'W') {
					swap++;
				}
				flag = !flag;
				continue;
			case false:
				if (board.at(i)[j] == 'B') {
					swap++;
				}
				flag = !flag;
				continue;
			}
		}
		flag = !flag;
	}
	return swap;
}

void nojam1018::solution()
{
	std::vector<int> chess;
	scanf("%d %d", &n, &m);
	scanf("%d");

	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::getline(std::cin, tmp);
		board.push_back(tmp);
	}
	
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			chess.push_back(start_black(i, j));
			chess.push_back(start_white(i, j));
		}
	}

	std::sort(chess.begin(), chess.end());
	printf("%d", chess[0]);

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", board.at(i)[j]);
		}
		printf("\n");
	}*/
}
