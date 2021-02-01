#include "../AlgorithmStudy.h"

namespace nojam9663 {
	static std::vector<int> board;
	static int count = 0;
	static int n;

	static bool isValid(int index) {
		for (int i = 0; i < index; i++) {
			if (board[index] == board[i] || index - i == abs(board[index] - board[i])) {
				return false;
			}
		}
		return true;
	}

	static void queen(int index) {
		if (index == n) {
			count++;
			return;
		}
		for (int i = 0; i < n; i++) {
			board[index] = i;
			if (isValid(index)) {
				queen(index + 1);
			}
		}
	}

	static void solution() {
		scanf_s("%d", &n);
		board.assign(n, 0);

		queen(0);
		printf("%d", count);

	}
}