// noj.am12865.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int w[101];
int v[101];
int dp[101][100001];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n + 1; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < k + 1; j++) {
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][k];
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
