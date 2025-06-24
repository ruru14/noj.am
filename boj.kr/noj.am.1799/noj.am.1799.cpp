// noj.am.1799.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ansW, ansB;
bool pDiag[40], aDiag[40];
vector<pair<int, int>> white, black;

inline bool promise(int y, int x) {
	return !pDiag[y - x + (n - 1)] && !aDiag[y + x];
}

inline void place(int y, int x) {
	pDiag[y - x + (n - 1)] = aDiag[y + x] = true;
}

inline void remove(int y, int x) {
	pDiag[y - x + (n - 1)] = aDiag[y + x] = false;
}

void bishopW(int idx, int cnt) {
	ansW = max(ansW, cnt);

	for (int i = idx; i < white.size(); i++) {
		int y = white[i].first;
		int x = white[i].second;

		if (promise(y,x)) {
			place(y, x);
			bishopW(i + 1, cnt + 1);
			remove(y, x);
		}
	}
}

void bishopB(int idx, int cnt) {
	ansB = max(ansB, cnt);

	for (int i = idx; i < black.size(); i++) {
		int y = black[i].first;
		int x = black[i].second;

		if (promise(y, x)) {
			place(y, x);
			bishopB(i + 1, cnt + 1);
			remove(y, x);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int foo;
			cin >> foo;
			if (foo == 1) {
				if ((i + j) % 2 == 0) white.push_back({ i,j });
				else black.push_back({ i,j });
			}
		}
	}

	bishopW(0, 0);
	memset(pDiag, false, sizeof(pDiag));
	memset(aDiag, false, sizeof(aDiag));
	bishopB(0, 0);

	cout << ansW + ansB;
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
