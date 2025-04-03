// noj.am.30805.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, tmp, idx = -1;
	vector<int> a, b;
	vector<pair<int, int>> ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool flag = false, flag2 = false;
			if (b[j] == a[i]) {
				auto tmp = ans.begin();
				for (int k = 0; k < ans.size(); k++) {
					if ((*(tmp + k)).second == j) {
						flag = true;
						break;
					} 
					if ((*(tmp + k)).first < a[i]) {
						if (k == 0 || (*(tmp + k - 1)).second < j) {
							ans.erase(tmp + k, ans.end());
							ans.push_back(make_pair(a[i], j));
							idx = j;
							flag2 = true;
							break;
						}
					}
					idx = (*(tmp + k)).second;
				}
				if (!flag && idx < j) {
					ans.push_back(make_pair(a[i], j));
					break;
				}
				if (flag2) break;
			}
		}
	}

	if (ans.size() == 0) cout << 0;
	else {
		cout << ans.size() << "\n";
		for (auto& i : ans) cout << i.first << " ";
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
