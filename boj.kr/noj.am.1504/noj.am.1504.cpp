// noj.am.1504.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define INF 8'000'001

using namespace std;

int n, e;
vector<vector<int>> map;

int dijkstra(int start, int end) {
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> q;
	dist[start] = 0;
	q.push(make_pair(0, start));

	while (!q.empty()) {
		auto cur = q.top();
		int curDist = -cur.first;
		int curNode = cur.second;
		q.pop();

		for (int nxtNode = 1; nxtNode <= n; nxtNode++) {
			int nxtDist = map[curNode][nxtNode];
			if (nxtDist == INF) continue;
			if (dist[nxtNode] > curDist + nxtDist) {
				dist[nxtNode] = curDist + nxtDist;
				q.push(make_pair(-dist[nxtNode], nxtNode));
			}
		}
	}

	return dist[end];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, ans = 0;
	cin >> n >> e;
	map.assign(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	cin >> a >> b;

	int tmpA, tmpB;
	tmpA = dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, n);
	tmpB = dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, n);
	ans += (tmpA > tmpB) ? tmpB : tmpA;

	if (ans >= INF) cout << -1;
	else cout << ans;
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
