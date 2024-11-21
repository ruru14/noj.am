// noj.am3197.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char field[1501][1501];
bool waterVisit[1501][1501];
bool swanVisit[1501][1501];
queue<pair<int, int>> waterCoord;
queue<pair<int, int>> waterNextCoord;
queue<pair<int, int>> swanCoord;
queue<pair<int, int>> swanNextCoord;
pair<int, int> swanPos;
// Right, Down, Left, Up
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool meetSwan = false;

void bfs(int r, int c) {
	int curR, curC;
	waterCoord.push(make_pair(r, c));
	waterVisit[r][c] = true;

	while (!waterCoord.empty()) {
		curR = waterCoord.front().first;
		curC = waterCoord.front().second;
		waterCoord.pop();

		for (int i = 0; i < 4; i++) {
			if (!waterVisit[curR + dy[i]][curC + dx[i]]) {
				waterVisit[curR + dy[i]][curC + dx[i]] = true;
				if (field[curR + dy[i]][curC + dx[i]] == '.' || field[curR + dy[i]][curC + dx[i]] == 'L') {
					waterCoord.push(make_pair(curR + dy[i], curC + dx[i]));
				} else if (field[curR + dy[i]][curC + dx[i]] == 'X') {
					waterNextCoord.push(make_pair(curR + dy[i], curC + dx[i]));
				}
			}
		}
	}
}

void swanBfs() {
	int curR, curC;

	while (!swanCoord.empty()) {
		curR = swanCoord.front().first;
		curC = swanCoord.front().second;
		swanCoord.pop();

		for (int i = 0; i < 4; i++) {
			if (!swanVisit[curR + dy[i]][curC + dx[i]]) {
				swanVisit[curR + dy[i]][curC + dx[i]] = true;
				if (field[curR + dy[i]][curC + dx[i]] == '.') {
					swanCoord.push(make_pair(curR + dy[i], curC + dx[i]));
				} else if (field[curR + dy[i]][curC + dx[i]] == 'X') {
					swanNextCoord.push(make_pair(curR + dy[i], curC + dx[i]));
				} else if (field[curR + dy[i]][curC + dx[i]] == 'L') {
					meetSwan = true;
				}
			}
		}
	}

	while (!swanNextCoord.empty()) {
		swanCoord.push(swanNextCoord.front());
		swanNextCoord.pop();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int r, c, day = 0;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'L') {
				swanPos.first = i;
				swanPos.second = j;
			}
			field[i][j] = field[i][j];
		}
	}
	swanCoord.push(make_pair(swanPos.first, swanPos.second));
	swanVisit[swanPos.first][swanPos.second] = true;

	while (!meetSwan) {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (!waterVisit[i][j]) {
					if (field[i][j] == '.' || field[i][j] == 'L') bfs(i, j);
				}
			}
		}

		while (!waterNextCoord.empty()) {
			auto tmp = waterNextCoord.front();
			waterNextCoord.pop();
			field[tmp.first][tmp.second] = '.';
			waterVisit[tmp.first][tmp.second] = false;
		}

		/*
		while (!swanNextCoord.empty()) {
			auto tmp = swanNextCoord.front();
			swanNextCoord.pop();
			waterField[tmp.first][tmp.second] = '.';
			waterVisit[tmp.first][tmp.second] = false;
		}*/

		/*cout << "--------\n";
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << field[i][j];
			}
			cout << "\n";
		}
		cout << "--------\n";*/

		day++;

		swanBfs();
	}

	/*cout << "\n";

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << waterField[i][j];
		}
		cout << "\n";
	}*/

	cout << day;

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
