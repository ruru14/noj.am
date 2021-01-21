#include "AlgorithmStudy.h"

namespace nojam14698 {
	static void solution() {
		std::vector<int> answer;
		int testCase;
		std::cin >> testCase;
		for (int i = 0; i < testCase; i++) {
			int slimes;
			std::cin >> slimes;
			std::vector<uint64_t> energies;
			std::vector<uint64_t> cost;
			uint64_t temp;
			for (int j = 0; j < slimes; j++) {
				std::cin >> temp;
				energies.push_back(temp);
			}
			// 여기까지 입력
			temp = 1;

			while (energies.size() != 1) {
				uint64_t min1 = energies.at(0);
				int minIndex1 = 0;
				for (int k = 0; k < energies.size(); k++) {
					if (min1 > energies.at(k)) {
						min1 = energies.at(k);
						minIndex1 = k;
					}
				}
				std::vector<uint64_t>::iterator iter = energies.begin();
				iter += minIndex1;
				energies.erase(iter);

				uint64_t min2 = energies.at(0);
				int minIndex2 = 0;
				for (int k = 0; k < energies.size(); k++) {
					if (min2 > energies.at(k)) {
						min2 = energies.at(k);
						minIndex2 = k;
					}
				}
				iter = energies.begin();
				iter += minIndex2;
				energies.erase(iter);

				energies.push_back(min1 * min2);
				temp = (temp * (min1 * min2 % 1000000007)) % 1000000007;
			}
			answer.push_back(temp);
		}

		for (int i = 0; i < answer.size(); i++) {
			std::cout << answer[i] << "\n";
		}


	}
}