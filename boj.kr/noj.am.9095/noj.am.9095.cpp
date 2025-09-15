// noj.am.9095.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(11);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    // 1 : 1
    // 2 : 1+1, 2
    // 3 : 1+1+1, 1+2, 2+1, 3

    for (int i = 4; i < 11; i++) {
        for (int j = 1; j <= 3; j++) {
            dp[i] += dp[i - j];
        }
    }

    while (n--) {
        int foo;
        cin >> foo;
        cout << dp[foo] << "\n";
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
