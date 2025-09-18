// noj.am.1497.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;

int bitcnt(long long val) {
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans += (val >> i) & 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int maxsong = 0, ans = n + 1;
	vector<long long> playable;
	for (int i = 0; i < n; i++) {
		string guitar, songs;
		cin >> guitar >> songs;
		long long foo = 0;
		for (int j = 0; j < m; j++) {
			if (songs[j] == 'Y') foo |= (1LL << j);
		}
		playable.push_back(foo);
	}

	for (int i = 0; i < (1 << (n)); i++) {
		long long foo = 0;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				foo |= playable[j];
				cnt++;
			}
		}
		int songs = bitcnt(foo);
		if (songs > maxsong) {
			maxsong = songs;
			ans = cnt;
		} else if (songs == maxsong && ans > cnt) {
			ans = cnt;
		}
	}

	if (maxsong == 0) cout << -1;
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
