// noj.am.1043.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, ans = 0;
vector<vector<int>> party;

void func(int dec, int cnt, set<int> truth, set<int> lie) {
	if (m - cnt + dec < ans) return;
	for (auto& i : truth) if (lie.find(i) != lie.end()) return;
	if (cnt >= m) {
		ans = ans > dec ? ans : dec;
		return;
	}

	set<int> truth_alt(truth);
	set<int> lie_alt(lie);
	for (auto& i : party[cnt]) truth_alt.insert(i);
	for (auto& i : party[cnt]) lie_alt.insert(i);
	func(dec, cnt + 1, truth_alt, lie);
	func(dec + 1, cnt + 1, truth, lie_alt);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> n >> m;
	cin >> t;
	set<int> truth, lie;
	party.assign(m, vector<int>());
	for (int i = 0; i < t; i++) {
		int tmp;
		cin >> tmp;
		truth.insert(tmp);
	}

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		party[i].assign(tmp, 0);
		for (int j = 0; j < tmp; j++) cin >> party[i][j];
	}

	func(0, 0, truth, lie);
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
