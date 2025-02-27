// noj.am.11657.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define INF 1'000'000'000

struct Edge {
    int start;
    int end;
    int cost;
};

int main()
{
    int n, m;
    int a, b, c;
    bool flag = true;
    cin >> n >> m;
    vector<Edge> graph;
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph.push_back({ a, b, c });
    }

    for (int i = 1; i < n; i++) {
        for (auto& j : graph) {
            if (dist[j.start] == INF) continue;
            if (dist[j.end] > dist[j.start] + j.cost) dist[j.end] = dist[j.start] + j.cost;
        }
    }

    for (auto& i : graph) {
        if (dist[i.start] == INF) continue;
        if (dist[i.end] > dist[i.start] + i.cost) {
            cout << -1;
            flag = false;
            break;
        }
    }

    if (flag) for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << "\n";
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
