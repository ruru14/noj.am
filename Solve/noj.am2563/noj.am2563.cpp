// noj.am2563.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector<int>> paper(100, std::vector<int>(100));
	int cnt, answer = 0;
	std::cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int tmpX, tmpY;
		std::cin >> tmpX >> tmpY;
		for (int j = tmpX; j < tmpX + 10; j++) {
			for (int k = tmpY; k < tmpY + 10; k++) {
				paper[j][k] = 1;
			}
		}
	}

	for (auto& i : paper) {
		for (auto& j : i) {
			if (j == 1)answer++;
		}
	}
	std::cout << answer;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
