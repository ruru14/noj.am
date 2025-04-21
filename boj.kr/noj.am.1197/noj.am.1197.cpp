// noj.am.1197.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 9'999'999

using namespace std;

int v, e;

void prim(vector<vector<pair<int, int>>> graph) {
    vector<bool> visit(v + 1, false);
    vector<int> edge;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visit[1] = true;

    for (auto& i : graph[1]) {
        pq.push({ i.second, i.first });
    }

    while (!pq.empty()) {
        pair<int, int> nxtNode = pq.top();
        pq.pop();

        if (visit[nxtNode.second]) continue;

        visit[nxtNode.second] = true;
        edge.push_back(nxtNode.first);

        for (auto& i : graph[nxtNode.second]) {
            if (!visit[i.first]) pq.push({ i.second, i.first });
        }

    }

    int sum = 0;
    for (auto& i : edge) {
        sum += i;
    }

    if (sum == INF) cout << 0;
    else cout << sum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());


    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    prim(graph);
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
