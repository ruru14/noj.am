// noj.am.12849.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define MOD 1'000'000'007

using namespace std;

vector<vector<int>> graph({
    {1,2},
    {0,2,3},
    {0,1,3,5},
    {1,2,4,5},
    {3,5,6},
    {2,3,4,7},
    {4,7},
    {5,6}
    });


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(100'001, vector<int>(8, 0));
    dp[0][0] = 1;

    for (int t = 1; t <= n; t++) {
        for (int i = 0; i < 8; i++) {
            for (auto& adj : graph[i]) {
                dp[t][i] = (dp[t][i] + dp[t - 1][adj]) % MOD;
            }
        }
    }

    cout << dp[n][0];
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
