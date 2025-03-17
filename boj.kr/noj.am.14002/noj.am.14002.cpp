// noj.am.14002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, answer = 0;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> dp(n + 1);
    stack<int> ans;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(dp[i], answer);
    }

    cout << answer << "\n";
    for (int i = n; i >= 1; i--) {
        if (dp[i] == answer) {
            ans.push(arr[i]);
            answer--;
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
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
