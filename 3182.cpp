#include "AlgorithmStudy.h"

namespace nojam3182 {
	static bool findItem(std::vector<int> list, int item) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i] == item)
				return true;
		}
		return false;
	}

	static void solution() {
		int member;
		int max = -1;
		int answer = -1;
		scanf_s("%d", &member);

		std::vector<int> senior;
		std::vector<int> question;
		for (int i = 0; i < member; i++) {
			int temp;
			scanf_s("%d", &temp);
			senior.push_back(temp);
		}

		for (int i = 0; i < senior.size(); i++) {
			std::vector<int> temp;
			int index = i;
			temp.push_back(i + 1);
			while (!findItem(temp, senior[index])) {
				temp.push_back(senior[index]);
				index = senior[index]-1;
			}
			question.push_back(temp.size());
		}

		for (int i = 0; i < question.size(); i++) {
			if (max < question[i]) {
				max = question[i];
				answer = i;
			}
		}

		printf("%d", answer + 1);
	}
}