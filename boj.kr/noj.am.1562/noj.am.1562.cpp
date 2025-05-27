// noj.am.1562.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define MOD 1'000'000'000

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(10, vector<long long>(1024, 0)));

	for (int i = 1; i <= 9; i++) dp[1][i][(1 << i)] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 1; k < 1024; k++) {
				int nxtBit;
				if (j > 0) {
					nxtBit = k | (1 << (j - 1));
					dp[i + 1][j - 1][nxtBit] = (dp[i + 1][j - 1][nxtBit] + dp[i][j][k]) % MOD;
				}
				if (j < 9) {
					nxtBit = k | (1 << (j + 1));
					dp[i + 1][j + 1][nxtBit] = (dp[i + 1][j + 1][nxtBit] + dp[i][j][k]) % MOD;
				}
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[n][i][1023]) % MOD;
	}
	cout << answer;
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
