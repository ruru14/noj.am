#include "9663.h"

// ü����
//board[0] �� ������ ���� 0��° ������ ���� ���� �� ��ȣ
//board[0] = 1 �϶�
/*
* board[1] �� 1�̸� �ȵ��ݾ�?
* �ٵ� �밢���� �ȵǴϱ�
* 2�� �ȵ�
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
