// noj.am.17070.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Pos { int x; int y; };

int ans = 0;
vector<vector<int>> map;
vector<vector<bool>> visit;
int dx[] = { 1, 0, 1 };
int dy[] = { 0, 1, 1 };

bool isValid(int x, int y) {
	if (x < 0 || x >= map.size()) return false;
	if (y < 0 || y >= map[0].size()) return false;
	return true;
}

void dfs(int n, Pos pos, int dir) {
	if (pos.x == n && pos.y == n) {
		ans++;
		return;
	}

	visit[pos.x][pos.y] = true;

	for (int i = 0; i < 3; i++) {
		Pos nxtPos;
		nxtPos.x = pos.x + dx[i];
		nxtPos.y = pos.y + dy[i];
		if ((dir == 0 && i == 1) ||
			(dir == 1 && i == 0) ||
			!isValid(nxtPos.x, nxtPos.y)) continue;

		if (i < 2) {
			if (map[nxtPos.x][nxtPos.y] == 0 && !visit[nxtPos.x][nxtPos.y]) {
				dfs(n, nxtPos, i);
				visit[nxtPos.x][nxtPos.y] = false;
			}
		} else {
			if ((map[nxtPos.x][nxtPos.y] == 0 &&
				map[nxtPos.x - 1][nxtPos.y] == 0 &&
				map[nxtPos.x][nxtPos.y - 1] == 0) && !visit[nxtPos.x][nxtPos.y]) {
				dfs(n, nxtPos, i);
				visit[nxtPos.x][nxtPos.y] = false;
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	map.assign(n, vector<int>(n, 0));
	visit.assign(n, vector<bool>(n, false)); 

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) cin >> map[x][y];

	dfs(n - 1, Pos({ 1,0 }), 0);
	cout << ans;
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
