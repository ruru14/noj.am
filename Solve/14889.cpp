#include "../AlgorithmStudy.h"

namespace nojam14889 {
	static int solution() {
        int lines;
        std::cin >> lines;
        int** stats = new int* [lines];
        for (int i = 0; i < lines; i++) {
            stats[i] = new int[lines];
        }
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < lines; j++) {
                std::cin >> stats[i][j];
            }
        }

        std::vector<int> index(lines);
        std::vector<int> memPair;
        std::vector<int> memComb;
        std::vector<int> redTeam;
        std::vector<int> redPair;
        std::vector<int> blueTeam;
        std::vector<int> bluePair;
        int redSum;
        int blueSum;
        int minValue = -1;

        for (int i = 0; i < lines / 2; i++) {
            memComb.push_back(0);
            memComb.push_back(1);
        }
        memPair.push_back(1);
        memPair.push_back(1);
        for (int i = 0; i < (lines / 2) - 2; i++) {
            memPair.push_back(0);
        }
        sort(memComb.begin(), memComb.end());
        for (int i = 0; i < lines; i++) {
            index[i] = i;
        }
        do {
            sort(memPair.begin(), memPair.end());
            redTeam.clear();
            redSum = 0;
            blueTeam.clear();
            blueSum = 0;
            for (int i = 0; i < lines; i++) {
                if (memComb[i] == 1) {
                    redTeam.push_back(index[i]);
                }
                else {
                    blueTeam.push_back(index[i]);
                }
            }
            do {
                redPair.clear();
                bluePair.clear();
                for (int i = 0; i < lines / 2; i++) {
                    if (memPair[i] == 1) {
                        redPair.push_back(redTeam[i]);
                        bluePair.push_back(blueTeam[i]);
                    }
                }
                redSum += stats[redPair[0]][redPair[1]] + stats[redPair[1]][redPair[0]];
                blueSum += stats[bluePair[0]][bluePair[1]] + stats[bluePair[1]][bluePair[0]];
            } while (std::next_permutation(memPair.begin(), memPair.end()));
            if (minValue == -1) {
                minValue = abs(redSum - blueSum);
            }
            if (minValue > abs(redSum - blueSum)) {
                minValue = abs(redSum - blueSum);
            }
        } while (std::next_permutation(memComb.begin(), memComb.end()));
		return minValue;
	}
}
