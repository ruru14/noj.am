// noj.am.2342.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 5'555'555

using namespace std;

int getCost(int from, int to) {
	if (from == 0) return 2;
	if (from == to) return 1;
	if ((from + to) % 2 == 1) return 3;
	return 4;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> input;
	int step = 2, pos;
	while (cin >> pos) {
		if (pos == 0) break;
		input.push_back(pos);
	}

	vector<vector<vector<int>>> dp(input.size() + 1, vector<vector<int>>(5, vector<int>(5, INF)));
	int n = input.size();
	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) {
		int next = input[i];

		for (int left = 0; left <= 4; left++) {
			for (int right = 0; right <= 4; right++) {
				if (dp[i][left][right] == INF) continue;

				if (next != right) {
					dp[i + 1][next][right] = min(
						dp[i + 1][next][right],
						dp[i][left][right] + getCost(left, next)
					);
				}

				if (next != left) {
					dp[i + 1][left][next] = min(
						dp[i + 1][left][next],
						dp[i][left][right] + getCost(right, next)
					);
				}
			}
		}
	}

	int result = INF;
	for (int left = 0; left <= 4; left++) {
		for (int right = 0; right <= 4; right++) {
			result = min(result, dp[n][left][right]);
		}
	}

	cout << result;
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
