// noj.am.2568.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());

	vector<int> tails;
	vector<int> arrIdx;
	vector<int> parent(arr.size(), -1);

	for (int i = 0; i < arr.size(); i++) {
		auto it = lower_bound(tails.begin(), tails.end(), arr[i].second);
		int pos = it - tails.begin();

		if (it == tails.end()) {
			tails.push_back(arr[i].second);
			arrIdx.push_back(i);
		} else {
			*it = arr[i].second;
			arrIdx[pos] = i;
		}

		if (pos > 0) {
			parent[i] = arrIdx[pos - 1];
		}
	}

	set<int> lis;
	int curr = arrIdx.back();

	while (curr != -1) {
		lis.insert(arr[curr].second);
		curr = parent[curr];
	}

	vector<int> ans;
	for (auto& i : arr) {
		if (lis.find(i.second) == lis.end()) {
			ans.push_back(i.first);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto& i : ans) cout << i << "\n";
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
