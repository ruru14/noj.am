// noj.am.1865.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define INF 1'000'000'000

struct Edge {
    int start;
    int end;
    int dist;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    int n, m, w;
    int s, e, t;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        vector<Edge> graph;
        vector<int> dist(n + 1, INF);
        bool flag = true;
        dist[1] = 0;
        // graph[start][idx].first = start - end
        // graph[start][idx].second = dist (start - end)


        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            graph.push_back({ s,e,t });
            graph.push_back({ e,s,t });
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            graph.push_back({ s,e,-t });
        }

        for (int i = 1; i < n; i++) {
            for (auto& j : graph) {
                if (dist[j.end] > dist[j.start] + j.dist) dist[j.end] = dist[j.start] + j.dist;
            }
        }

        for (auto& i : graph) {
            if (dist[i.end] > dist[i.start] + i.dist) {
                cout << "YES\n";
                flag = false;
                break;
            }
        }

        if (flag) cout << "NO\n";

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
