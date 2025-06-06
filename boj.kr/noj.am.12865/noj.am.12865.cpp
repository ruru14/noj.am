// noj.am12865.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> weight(n), value(n);
    vector<long long> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int item = 0; item < n; item++) {
        for (int c = k; c >= weight[item]; c--) {
            dp[c] = max(dp[c], dp[c - weight[item]] + value[item]);
        }
    }

    cout << dp[k];
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
