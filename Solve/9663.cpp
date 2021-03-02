#include "9663.h"

// 체스판
//board[0] 의 원소의 값은 0번째 열에서 퀸이 놓인 행 번호
//board[0] = 1 일때
/*
* board[1] 은 1이면 안되잖아?
* 근데 대각선도 안되니까
* 2도 안돼
*/

bool nojam9663::isValid(int index) {
	for (int i = 0; i < index; i++) {
		if (board[index] == board[i] || index - i == abs(board[index] - board[i])) {
			return false;
		}
	}
	return true;
}

void nojam9663::queen(int index) {
	if (index == n) {
		count++;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[index] = i;
		if (nojam9663::isValid(index)) {
			nojam9663::queen(index + 1);
		}
	}
}

void nojam9663::solution() {
	scanf_s("%d", &n);
	board.assign(n, 0);

	nojam9663::queen(0);
	printf("%d", count);
}
