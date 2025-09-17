// noj.am.11780.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> nxt(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (dist[from][to] > cost) dist[from][to] = cost;
        nxt[from][to] = to;
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int st = 1; st <= n; st++) {
            for (int ed = 1; ed <= n; ed++) {
                if (dist[st][ed] > dist[st][mid] + dist[mid][ed]) {
                    dist[st][ed] = dist[st][mid] + dist[mid][ed];
                    nxt[st][ed] = nxt[st][mid];
                }
            }
        }
    }

    for (int st = 1; st <= n; st++) {
        for (int ed = 1; ed <= n; ed++) {
            if (dist[st][ed] == INF) cout << 0 << " ";
            else cout << dist[st][ed] << " ";
        }
        cout << "\n";
    }

    for (int st = 1; st <= n; st++) {
        for (int ed = 1; ed <= n; ed++) {
            if (dist[st][ed] == 0 || dist[st][ed] == INF) {
                cout << 0;
            } else {
                vector<int> path;
                int cur = st;
                while (cur != ed) {
                    path.push_back(cur);
                    cur = nxt[cur][ed];
                }
                path.push_back(ed);
                cout << path.size() << " ";
                for (auto& i : path) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
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
