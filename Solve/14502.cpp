#include "../AlgorithmStudy.h"

namespace nojam14502 {
	static int wtfCorona(std::vector<int> lab, int width, int height) {
		int count = 0;
		int safe = 0;
		do {
			count = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (lab[i * width + j] == 2) {
						if (i != 0) {
							if (lab[(i - 1) * width + j] == 0) {
								lab[(i - 1) * width + j] = 2;
								count++;
							}
						}
						if (i != height - 1) {
							if (lab[(i + 1) * width + j] == 0) {
								lab[(i + 1) * width + j] = 2;
								count++;
							}
						}
						if (j != 0) {
							if (lab[i * width + j - 1] == 0) {
								lab[i * width + j - 1] = 2;
								count++;
							}
						}
						if (j != width - 1) {
							if (lab[i * width + j + 1] == 0) {
								lab[i * width + j + 1] = 2;
								count++;
							}
						}
					}
				}
			}
		} while (count != 0);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (lab[i * width + j] == 0)
					safe++;
			}
		}
		return safe;
	}

	static void solution() {
		int height;
		int width;
		scanf_s("%d %d", &height, &width);
		
		std::vector<int> map; // Original map
		std::vector<int> emptySpace; // Space at 0's index
		std::vector<int> wallComb;
		std::vector<int> safeZone;
		int maxSafe = 0;
		wallComb.push_back(1);
		wallComb.push_back(1);
		wallComb.push_back(1);
		for (int i = 0; i < height * width; i++) {
			int temp;
			scanf_s("%d", &temp);
			map.push_back(temp);
		}
		
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[(i * width) + j] == 0) {
					emptySpace.push_back((i * width) + j);
				}
			}
		}

		for (int i = 0; i < emptySpace.size()-3; i++) {
			wallComb.push_back(0);
		}
		std::sort(wallComb.begin(), wallComb.end());


		do {
			std::vector<int> copyMap(map);
			for (int i = 0; i < wallComb.size(); i++) {
				if (wallComb[i] == 1) {
					copyMap[emptySpace[i]] = 1;
				}
			}
			safeZone.push_back(wtfCorona(copyMap, width, height));
		} while (std::next_permutation(wallComb.begin(), wallComb.end()));

		for (int i = 0; i < safeZone.size(); i++) {
			if (maxSafe < safeZone[i]) {
				maxSafe = safeZone[i];
			}
		}

		printf("%d", maxSafe);
	}
}