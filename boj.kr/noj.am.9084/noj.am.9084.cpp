// noj.am.9084.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, target;
		cin >> n;
		vector<int> coin(n);
		for (int i = 0; i < n; i++) cin >> coin[i];
		cin >> target;
		vector<vector<int>> dp(n, vector<int>(target + 1, 0));
		for (int i = 0; i < n; i++) dp[i][0] = 1;

		/*
		* dp[i][j] = dp[i-1][j]
		* dp[i][j] = dp[i][j-coin[i]]
		*/
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= target; j++) {
				if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
				if (j - coin[i] >= 0) dp[i][j] += dp[i][j - coin[i]];
			}
		}

		cout << dp[n - 1][target] << "\n";
	}
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
