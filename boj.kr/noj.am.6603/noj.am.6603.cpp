// noj.am6603.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> lotto;
	vector<int> comb;
	vector<vector<int>> dict;
	int flag = -1, tmp;
	while (true) {
		dict.clear();
		lotto.clear();
		comb.clear();
		comb.assign(6, 1);
		cin >> flag;
		if (flag == 0) return 0;

		for (int i = 0; i < flag - 6; i++) {
			comb.push_back(0);
		}

		for (int i = 0; i < flag; i++) {
			cin >> tmp;
			lotto.push_back(tmp);
		}
		sort(comb.begin(), comb.end());
		do {
			vector<int> tmp;
			for (int i = 0; i < comb.size(); i++) {
				if (comb[i] == 1) tmp.push_back(lotto[i]);
			}
			dict.push_back(tmp);
		} while (next_permutation(comb.begin(), comb.end()));
		sort(dict.begin(), dict.end());

		for (int i = 0; i < dict.size(); i++) {
			for (int j = 0; j < dict[i].size(); j++) {
				cout << dict[i][j];
				if (j != dict[i].size() - 1) cout << " ";
			}
			cout << "\n";
		}
		cout << "\n";
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
