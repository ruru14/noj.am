// noj.am.1106.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1'111'111

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c, n;
	cin >> c >> n;
	vector<int> cost(n), cust(n);
	vector<int> dp(c + 101, INF); // dp[i] : 고객 i명을 늘리는 최소 금액
	dp[0] = 0;

	for (int i = 0; i < n; i++) cin >> cost[i] >> cust[i];

	for (int i = 0; i < n; i++) {
		for (int j = cust[i]; j < dp.size(); j++) {
			dp[j] = min(dp[j], dp[j - cust[i]] + cost[i]);
		}
	}

	int minCost = INF;
	for (int i = c; i < dp.size(); i++) {
		minCost = min(minCost, dp[i]);
	}
	cout << minCost;
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
