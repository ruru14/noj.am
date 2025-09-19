// noj.am.1005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int n, k, w;
vector<int> delay, dp;
vector<vector<int>> graph;

int func(int target) {
    if (dp[target] != -1) return dp[target];

    dp[target] = 0;
    for (auto& nxt : graph[target]) {
        dp[target] = max(dp[target], func(nxt));
    }

    return dp[target] = dp[target] + delay[target];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        delay.assign(n + 1, 0);
        dp.assign(n + 1, -1);
        graph.assign(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) cin >> delay[i];
        for (int i = 0; i < k; i++) {
            int from, to;
            cin >> from >> to;
            graph[to].push_back(from);
        }

        cin >> w;
        cout << func(w) << "\n";
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
