// noj.am.2623.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> cnt(n + 1, 0), ans;

    for (int i = 0; i < m; i++) {
        int foo;
        cin >> foo;
        vector<int> seq;
        for (int j = 0; j < foo; j++) {
            int bar;
            cin >> bar;
            seq.push_back(bar);
        }

        for (int i = 0; i < seq.size()-1; i++) {
            graph[seq[i]].push_back(seq[i + 1]);
            cnt[seq[i + 1]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for (auto& i : graph[cur]) {
            cnt[i]--;
            if (cnt[i] == 0) q.push(i);
        }
    }

    if (ans.size() < n) cout << "0";
    else {
        for (auto& i : ans) cout << i << "\n";
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
