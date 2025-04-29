// noj.am.9252.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int answer = 0;
	string a, b, lcs = "";
	cin >> a >> b;
	vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int idxA = a.size(), idxB = b.size();
	cout << dp[idxA][idxB] << "\n";

	while (idxA > 0 && idxB > 0) {
		if (a[idxA - 1] == b[idxB - 1]) {
			lcs = a[idxA - 1] + lcs;
			idxA--;
			idxB--;
		} else if (dp[idxA - 1][idxB] > dp[idxA][idxB - 1]) {
			idxA--;
		} else {
			idxB--;
		}
	}

	cout << lcs;
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
