// noj.am.1932.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> triangle(n + 1, vector<int>(n + 2, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    vector<int> answer(n + 1);

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }
    dp[1][1] = triangle[1][1];

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            dp[i][j] = max(dp[i - 1][j-1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
            answer[i] = dp[i][j] > answer[i] ? dp[i][j] : answer[i];
        }
    }

    cout << answer[n];
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
