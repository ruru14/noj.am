// noj.am.21940.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>

#define INF 111'111'111

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> city(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i <= n; i++) city[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        city[from][to] = min(city[from][to], cost);
    }
    cin >> k;
    vector<int> start;
    start.reserve(k);
    for (int i = 0; i < k; i++) {
        int foo;
        cin >> foo;
        start.push_back(foo);
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (city[from][to] > city[from][mid] + city[mid][to]) {
                    city[from][to] = city[from][mid] + city[mid][to];
                }
            }
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (auto& j : start) {
            mx = max(mx, city[j][i] + city[i][j]);
        }
        ans.push_back({ mx, i });
    }

    sort(ans.begin(), ans.end());
    int min = ans[0].first;
    for (auto& i : ans) {
        if (i.first > min) break;
        cout << i.second << " ";
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
