// noj.am.1238.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define NIL 10000001

int n, m, x;
vector<vector<int>> graph;
vector<int> answer;

void dijkstra(int start, int end) {
	if (start == end) return;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	vector<int> dist(n + 1, NIL);
	dist[start] = 0;

	while (!pq.empty()) {
		auto cur = pq.top();
		int curDist = -cur.first;
		int curPos = cur.second;
		pq.pop();

		for (int nxtPos = 1; nxtPos <= n; nxtPos++) {
			int nxtDist = curDist + graph[curPos][nxtPos];

			if (dist[nxtPos] > nxtDist) {
				dist[nxtPos] = nxtDist;
				pq.push(make_pair(-nxtDist, nxtPos));
			}
		}
	}

	if (end != -1) {
		answer[start] += dist[end];
	} else {
		for (int i = 1; i <= n; i++) answer[i] += dist[i];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int output = 0;
	cin >> n >> m >> x;
	graph.assign(n + 1, vector<int>(n + 1, NIL));
	answer.assign(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	
	for (int i = 1; i <= n; i++) dijkstra(i, x);
	dijkstra(x, -1);

	for (int i = 1; i <= n; i++) {
		if (answer[i] > output) output = answer[i];
	}

	cout << output;

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
