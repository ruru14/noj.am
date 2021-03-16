#include "2847.h"

void nojam2847::solution() {

	/*
	* IDEA
	* 1. ���� ���ϱ� (Top-Down)
	* 2. �Ʒ� ���̵� ������ �� �������
	* 3. �Ʒ� ���̵� ������ ���� (�����̵� - 1�� ������)
	* 4. �׻� ���� �����ϴ� ��츸 �־����Ƿ� ����ó�� X
	* 4.1. ����1 : Top-Down ���� ���� ������ ������ �� ���
	*/
	int levels;
	int answer = 0;
	std::cin >> levels; // ������ ��
	std::vector<int> scores;

	//������ ���� �Է�
	for (int i = 0; i < levels; i++) {
		int temp;
		std::cin >> temp;
		scores.push_back(temp);
	}

	//��� : �ֻ�ܺ��� �������鼭 �� �� �� ����
	for (int i = scores.size() - 2; i >= 0; --i) {
		if (scores[i] >= scores[i + 1]) {
			answer += scores[i] - scores[i + 1] + 1;
			scores[i] = scores[i + 1] - 1;
		}
	}

	/*  4 // Level
		5 -> 3-1 (2)
		3 -> pass
		7 -> 5-1 (4)
		5
	*/
	printf("%d", answer);
}
