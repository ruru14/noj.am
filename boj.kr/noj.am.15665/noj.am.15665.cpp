// noj.am.15665.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<int> arr;
vector<int> ans;

void track(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	for (auto& i : arr) {
		ans[cnt] = i;
		track(cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	ans.assign(n, 0);
	for (int i = 0; i < n; i++) {
		int foo;
		cin >> foo;
		arr.insert(foo);
	}
	track(0);
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
