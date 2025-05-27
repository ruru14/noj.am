// noj.am.10844.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define MOD 1'000'000'000

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> dp(101, vector<long long>(10, 0));
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] % MOD;
        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
        dp[i][9] = dp[i - 1][8] % MOD;
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum = (sum + dp[n][i]) % MOD;
    }

    cout << sum;
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
