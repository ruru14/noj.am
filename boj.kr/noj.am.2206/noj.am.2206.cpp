// noj.am.2206.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF 1'000'000
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int n, m;
vector<vector<int>> map;

bool isValidIndex(int y, int x) {
	if (y <= 0 || y > n) return false;
	if (x <= 0 || x > m) return false;
	return true;
}

int bfs(int startY, int startX, int destY, int destX) {
	vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
	dist[startY][startX] = 1;
	queue<pair<pair<int, int>, pair<int, int>>> q; // <CoordY, CoordX>, <break, distance>
	q.push(make_pair(make_pair(startY, startX), make_pair(0, 1)));

	while (!q.empty()) {
		auto cur = q.front();
		int curY = cur.first.first;
		int curX = cur.first.second;
		int curBreak = cur.second.first;
		int curDist = cur.second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtY = curY + dy[i];
			int nxtX = curX + dx[i];
			if (isValidIndex(nxtY, nxtX)) {
				if (curBreak + map[nxtY][nxtX] > 1) continue;
				if (dist[nxtY][nxtX] > curDist + 1) {
					dist[nxtY][nxtX] = curDist + 1;
					q.push(make_pair(make_pair(nxtY, nxtX), make_pair(curBreak + map[nxtY][nxtX], curDist + 1)));
				}
			}
		}
	}

	return dist[destY][destX];
}

int main()
{
	cin >> n >> m;
	map.assign(n + 1, vector<int>(m + 1));

	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp = getchar();
			map[i][j] = tmp - '0';
		}
		getchar();
	}

	int ansA = bfs(1, 1, n, m);
	int ansB = bfs(n, m, 1, 1);

	if (ansA == INF) {
		if (ansB == INF) cout << -1;
		else cout << ansB;
	} else {
		if (ansB == INF) cout << ansA;
		else cout << ((ansA > ansB) ? ansB : ansA);
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
