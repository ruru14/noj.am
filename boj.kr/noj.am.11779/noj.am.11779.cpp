// noj.am.11779.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 1'000'000'000

using namespace std;

int n, m;

void dijkstra(int from, int to, vector<vector<int>> route) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, INF);
	vector<int> parent(n + 1, -1);
	dist[from] = 0;
	pq.push(make_pair(0, from));

	while (!pq.empty()) {
		auto cur = pq.top();
		int curCost = cur.first;
		int curNode = cur.second;
		pq.pop();

		if (dist[curNode] < curCost) continue;

		for (int i = 1; i < n + 1; i++) {
			// i = Next node
			int nxtDist = route[curNode][i];
			if (nxtDist == INF) continue;
			if (dist[i] > curCost + nxtDist) {
				dist[i] = curCost + nxtDist;
				parent[i] = curNode;
				pq.push(make_pair(dist[i], i));
			}
		}
	}

	cout << dist[to] << "\n";

	vector<int> path;
	for (int at = to; at != -1; at = parent[at]) {
		path.push_back(at);
	}
	cout << path.size() << "\n";
	for (auto i = path.rbegin(); i != path.rend(); i++) {
		cout << *i << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int from, to;
	cin >> n >> m;
	vector<vector<int>> route(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		if(route[s][e] > c) route[s][e] = c;
	}
	cin >> from >> to;

	dijkstra(from, to, route);
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
