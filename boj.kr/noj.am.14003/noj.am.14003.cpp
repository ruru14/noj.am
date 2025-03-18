// noj.am.14003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> arr, dp, bs_arr, bs_dp;

#define INF 1'111'111'111

int bSearch(int val) {
    int low = 0, high = bs_arr.size() - 1, mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (bs_arr[mid] >= val) high = mid;
        else low = mid + 1;
    }

    return high;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, answer = 0;
    cin >> n;
    arr.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    bs_arr.assign(1, -INF);
    bs_dp.assign(1, 0);
    stack<int> ans;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] > bs_arr.back()) {
            bs_arr.push_back(arr[i]);
            dp[i] = bs_dp.back() + 1;
            bs_dp.push_back(bs_dp.back() + 1);
        } else {
            int idx = bSearch(arr[i]);
            bs_arr[idx] = arr[i];
            dp[i] = bs_dp[idx];
        }
        if (answer < dp[i]) answer = dp[i];
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
