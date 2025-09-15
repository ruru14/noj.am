// noj.am.12852.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(1'000'001, 1'000'001);
    vector<int> back(1'000'001, 1'000'001);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    back[1] = 0;
    back[2] = 1;
    back[3] = 1;

    for (int i = 4; i <= n; i++) {
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            back[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            back[i] = i / 3;
        }
        if (dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            back[i] = i - 1;
        }
    }

    cout << dp[n] << "\n";
    while (n > 1) {
        cout << n << " ";
        n = back[n];
    }
    cout << 1;
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
