// noj.am.2887.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Pos {
    int x;
    int y;
    int z;
    int idx;
};

void prim(vector<vector<pair<int,int>>>& graph) {
    int ans = 0;
    int n = graph.size();
    vector<bool> visit(n, false);
    vector<int> edge;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visit[0] = true;
    for (auto& i : graph[0]) {
        pq.push({ i.second, i.first });
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        if (visit[cur.second]) continue;
        visit[cur.second] = true;
        ans += cur.first;

        for (auto& i : graph[cur.second]) {
            if (!visit[i.first]) pq.push({ i.second,i.first });
        }
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<Pos> planet(n);
    for (int i = 0; i < n; i++) {
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
        planet[i].idx = i;
    }

    vector<vector<pair<int, int>>> graph(n);
    sort(planet.begin(), planet.end(), [](const Pos& a, const Pos& b) { return a.x < b.x; });
    for (int i = 0; i < n - 1; i++) {
        int foo = min(abs(planet[i].x - planet[i + 1].x), abs(planet[i].y - planet[i + 1].y));
        foo = min(foo, abs(planet[i].z - planet[i + 1].z));
        graph[planet[i].idx].push_back({ planet[i + 1].idx,foo });
        graph[planet[i + 1].idx].push_back({ planet[i].idx,foo });
    }

    sort(planet.begin(), planet.end(), [](const Pos& a, const Pos& b) { return a.y < b.y; });
    for (int i = 0; i < n - 1; i++) {
        int foo = min(abs(planet[i].x - planet[i + 1].x), abs(planet[i].y - planet[i + 1].y));
        foo = min(foo, abs(planet[i].z - planet[i + 1].z));
        graph[planet[i].idx].push_back({ planet[i + 1].idx,foo });
        graph[planet[i + 1].idx].push_back({ planet[i].idx,foo });
    }

    sort(planet.begin(), planet.end(), [](const Pos& a, const Pos& b) { return a.z < b.z; });
    for (int i = 0; i < n - 1; i++) {
        int foo = min(abs(planet[i].x - planet[i + 1].x), abs(planet[i].y - planet[i + 1].y));
        foo = min(foo, abs(planet[i].z - planet[i + 1].z));
        graph[planet[i].idx].push_back({ planet[i + 1].idx,foo });
        graph[planet[i + 1].idx].push_back({ planet[i].idx,foo });
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
