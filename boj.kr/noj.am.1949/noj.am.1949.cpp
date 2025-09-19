// noj.am.1949.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> popu, dp1, dp2;
vector<vector<int>> graph;

void dfs(int cur, int parent) {
    dp1[cur] = popu[cur];
    dp2[cur] = 0;
    for (auto& nxt : graph[cur]) {
        if (parent == nxt) continue;
        dfs(nxt, cur);
        dp1[cur] += dp2[nxt];
        dp2[cur] += max(dp1[nxt], dp2[nxt]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    popu.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>());
    dp1.assign(n + 1, 0);
    dp2.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> popu[i];
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(1, 0);

    cout << max(dp1[1], dp2[1]);
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
