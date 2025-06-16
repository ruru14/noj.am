// noj.am.1509.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

#define INF 2501

using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
    vector<vector<bool>> palindrome(n + 1, vector<bool>(n + 1, false));
    vector<int> dp(n + 1, INF);

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len == 1) palindrome[i][j] = true;
            else if (len == 2) palindrome[i][j] = (str[i] == str[j]);
            else palindrome[i][j] = (str[i] == str[j]) && palindrome[i + 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (palindrome[j][i]) {
                if (j == 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }

    cout << dp[n - 1];
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
