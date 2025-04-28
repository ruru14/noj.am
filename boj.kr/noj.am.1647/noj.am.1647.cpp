// noj.am.1647.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX 1'000'000

using namespace std;

int n, m;
vector<vector<pair<int, int>>> map;

// Kruskal
struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }
};

void kruskal(const vector<Edge>& edge) {
    DisjointSet ds(n + 1);
    priority_queue<Edge> mst;

    for (auto& i : edge) {
        if (!ds.isSameSet(i.from, i.to)) {
            mst.push(i);
            ds.unionSets(i.from, i.to);
        }
    }

    int ans = 0;
    mst.pop();
    while (!mst.empty()) {
        ans += mst.top().weight;
        mst.pop();
    }

    cout << ans;
}

void kruskal_input() {
    cin >> n >> m;
    vector<Edge> edge;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({ a,b,c });
    }

    sort(edge.begin(), edge.end());

    kruskal(edge);
}


// Prim
void prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<pair<int, int>> edge;
    vector<bool> visit(n + 1, false);
    visit[1] = true;

    for (auto& i : map[1]) {
        pq.push({ i.second, i.first });
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (visit[cur.second]) continue;

        visit[cur.second] = true;
        edge.push(cur);

        for (auto& i : map[cur.second]) {
            if (!visit[i.first]) pq.push({ i.second,i.first });
        }
    }

    int ans = 0;
    edge.pop();
    while (!edge.empty()) {
        ans += edge.top().first;
        edge.pop();
    }

    cout << ans;

}

void prim_input() {
    cin >> n >> m;
    map.assign(n + 1, vector<pair<int, int>>());

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
        map[b].push_back({ a,c });
    }

    prim();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //prim_input();
    kruskal_input();
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
