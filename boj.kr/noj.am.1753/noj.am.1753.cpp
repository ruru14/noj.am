// noj.am.1753.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e, start;
    cin >> v >> e >> start;
    vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());
    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({ to, cost });
    }

    vector<int> dist(v + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (cur.first != dist[cur.second]) continue;
        for (auto& i : graph[cur.second]) {
            if (dist[i.first] > dist[cur.second] + i.second) {
                dist[i.first] = dist[cur.second] + i.second;
                pq.push({ dist[i.first], i.first });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
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
