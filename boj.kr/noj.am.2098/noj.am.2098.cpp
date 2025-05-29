// noj.am.2098.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 100'000'000

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cities(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cities[i][j];
        }
    }

    int bitSize = 1 << n;
    vector<vector<int>> dp(bitSize, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < bitSize; mask++) {
        for (int cur = 0; cur < n; cur++) {
            for (int nxt = 0; nxt < n; nxt++) {
                if (cities[nxt][cur] == 0) continue;
                if (!(mask & (1 << nxt))) continue;
                if ((mask & (1 << cur))) continue;
                if (dp[mask][nxt] == INF) continue;
                int nxtMask = (mask | (1 << cur));
                dp[nxtMask][cur] = min(dp[nxtMask][cur], dp[mask][nxt] + cities[nxt][cur]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        if (cities[i][0] != 0) {
            ans = min(ans, dp[(1 << n) - 1][i] + cities[i][0]);
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
