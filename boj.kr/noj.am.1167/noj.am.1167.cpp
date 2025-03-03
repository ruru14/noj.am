// noj.am.1167.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 1'000'000'000

using namespace std;

int v;
vector<vector<pair<int, int>>> tree;

pair<int, int> bfs(int start) {
    vector<int> dist(v + 1, INF);
    vector<bool> visit(v + 1, false);
    pair<int, int> ans(0, 0);
    dist[start] = 0;
    visit[start] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto& nxt : tree[cur.first]) {
            if (visit[nxt.first]) continue;
            if (dist[nxt.first] > cur.second + nxt.second) {
                visit[nxt.first] = true;
                dist[nxt.first] = cur.second + nxt.second;
                q.push(make_pair(nxt.first, dist[nxt.first]));
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (ans.second < dist[i]) {
            ans.first = i;
            ans.second = dist[i];
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v;
    tree.assign(v + 1, vector<pair<int, int>>());

    for (int i = 0; i < v; i++) {
        int start;
        int end, dist;
        cin >> start;
        cin >> end;
        while (end != -1) {
            cin >> dist;
            tree[start].push_back(make_pair(end, dist));
            tree[end].push_back(make_pair(start, dist));
            cin >> end;
        }
    }

    auto foo = bfs(1);
    auto bar = bfs(foo.first);

    cout << bar.second;
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
