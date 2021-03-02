#include "2847.h"

void nojam2847::solution() {

	/*
	* IDEA
	* 1. 점수 비교하기 (Top-Down)
	* 2. 아래 난이도 점수가 더 높을경우
	* 3. 아래 난이도 점수를 조정 (윗난이도 - 1의 값으로)
	* 4. 항상 답이 존재하는 경우만 주어지므로 예외처리 X
	* 4.1. 예외1 : Top-Down 진행 도중 점수가 음수가 될 경우
	*/
	int levels;
	int answer = 0;
	std::cin >> levels; // 레벨의 수
	std::vector<int> scores;

	//레벨별 점수 입력
	for (int i = 0; i < levels; i++) {
		int temp;
		std::cin >> temp;
		scores.push_back(temp);
	}

	//계산 : 최상단부터 내려오면서 비교 후 값 변경
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
