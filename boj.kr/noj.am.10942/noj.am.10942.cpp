// noj.am.10942.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n;
    vector<int> arr(n);
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            int j = i + len - 1;

            if (i == j) dp[i][j] = true;
            else if (j - i == 1) dp[i][j] = arr[i] == arr[j];
            else {
                dp[i][j] = arr[i] == arr[j] && dp[i + 1][j - 1];
            }
        }
    }

    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        cout << (dp[a - 1][b - 1] ? 1 : 0) << "\n";
    }
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
