#include "20925.h"

std::vector<std::pair<int, int>> hunt;
std::vector<int> stamp;

int hunting(int start) {

	return *stamp.end();
}

void nojam20925::solution()
{
	int n, t;
	scanf("%d %d", &n, & t);
	std::vector<std::vector<int>> len(n * n);
	std::pair<int, int> start(0, 0);
	stamp.reserve(t);

	for (int i = 0; i < n; i++) {
		int c, e;
		scanf("%d %d", &c, &e);
		if (c == 0) {
			if (e > start.second) {
				start.first = c;
				start.second = e;
			}
		}
		hunt.push_back(std::make_pair(c, e));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			len.at(i).push_back(tmp);
		}
	}

	for (int i = 0; i < t; i++) {

	}
	// ù ����ʹ� ����ġ�� ���� ���������� (�ð��Ҹ� X)
	// ���� ����� �̵� ���� ?
	// �ð��� �Ҹ��ߴµ� ��ս��� ����? 
	// �ð� �������� ����
	// ���� �ð��� ���� �������ִ� ����ġ�� �ִ�
	//
	// ��� �迭�� 0���� �ʱ�ȭ
	// �� �ð��� ����, ���� ������� ����ġ�� ȹ�� (�迭����)
	// �� ������ �̵� ���� ����Ϳ� ���� �̵� / ���̵��� ���� ����ġ ȹ�� (�迭����)
	// 

}
