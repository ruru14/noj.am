// noj.am.1987.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int r, c, ans = 1;
int map[21][21] = { {0,}, };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isValid(int x, int y) {
	if (x <= 0 || x > c) return false;
	if (y <= 0 || y > r) return false;
	return true;
}

void track(bool* visit, int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nxtX = x + dx[i];
		int nxtY = y + dy[i];
		if (!isValid(nxtX, nxtY)) continue;
		if (visit[map[nxtX][nxtY]]) {
			if (ans < cnt) ans = cnt;
			continue;
		}

		bool nxtVisit[26];
		for (int i = 0; i < 26; i++) nxtVisit[i] = visit[i];
		nxtVisit[map[nxtX][nxtY]] = true;
		int nxtCnt = cnt + 1;

		track(nxtVisit, nxtX, nxtY, nxtCnt);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string tmp;
	cin >> r >> c;

	for (int i = 1; i <= r; i++) {
		cin >> tmp;
		for (int j = 0; j < c; j++) {
			map[j + 1][i] = tmp[j] - 65;
		}
	}
	
	bool visit[26] = { false, };
	visit[map[1][1]] = true;

	track(visit, 1, 1, 1);

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
