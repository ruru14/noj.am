// noj.am.7569.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = { 1, -1, 0, 0, 0, 0 };
int dx[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
int x, y, z, answer = 0;
vector<vector<vector<int>>> tomato;
vector<vector<vector<bool>>> visit;
bool flag = true;

struct Coord {
	int x, y, z;
};

bool checkTomato(vector<vector<vector<int>>> tomato) {
	for (auto& i : tomato) {
		for (auto& j : i) {
			for (auto& k : j) {
				if (k == 0) return false;
			}
		}
	}

	return true;
}

queue<Coord> bfs(queue<Coord> box) {
	queue<Coord> nxtBox;
	while (!box.empty()) {
		auto cur = box.front();
		box.pop();

		for (int i = 0; i < 6; i++) {
			auto nxt = cur;
			nxt.x += dx[i];
			nxt.y += dy[i];
			nxt.z += dz[i];
			if (tomato[nxt.x][nxt.y][nxt.z] == 0) {
				tomato[nxt.x][nxt.y][nxt.z] = 1;
				nxtBox.push(nxt);
			}
		}
	}
	return nxtBox;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> y >> z;
	tomato.assign(x + 2, vector<vector<int>>(y + 2, vector<int>(z + 2, -1)));
	visit.assign(x + 2, vector<vector<bool>>(y + 2, vector<bool>(z + 2, false)));

	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				cin >> tomato[k][j][i];
			}
		}
	}

	Coord c;
	queue<Coord> box;
	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				if (!visit[k][j][i] && tomato[k][j][i] == 1) {
					visit[k][j][i] = true;
					c.x = k;
					c.y = j;
					c.z = i;
					box.push(c);
				}
			}
		}
	}
	
	while (!box.empty()) {
		box = bfs(box);
		answer++;
	}

	if (checkTomato(tomato)) cout << answer - 1;
	else cout << -1;
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
