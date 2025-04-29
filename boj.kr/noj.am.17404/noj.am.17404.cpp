// noj.am.17404.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 1'000'000

using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = INF;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3, 0));
    vector<vector<int>> dp(n, vector<int>(3, INF));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) cin >> cost[i][j];

    for (int color = 0; color < 3; color++) {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) dp[i][j] = INF;

        dp[0][color] = cost[0][color];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }

        for (int last_color = 0; last_color < 3; last_color++) {
            if (last_color != color) {
                ans = min(ans, dp[n - 1][last_color]);
            }
        }
    }

    cout << ans;
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
