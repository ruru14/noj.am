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
	// 첫 사냥터는 경험치가 가장 높은곳으로 (시간소모 X)
	// 다음 사냥터 이동 조건 ?
	// 시간을 소모했는데 경손실이 나면? 
	// 시간 기준으로 정렬
	// 현재 시간에 내가 가지고있는 경험치의 최댓값
	//
	// 모든 배열을 0으로 초기화
	// 각 시간에 대해, 현재 사냥터의 경험치를 획득 (배열갱신)
	// 분 단위로 이동 가능 사냥터에 대해 이동 / 비이동에 대해 경험치 획득 (배열갱신)
	// 

}
