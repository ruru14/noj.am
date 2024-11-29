// noj.am.5052.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Trie {
public:
	Trie() : finish(false) { memset(next, 0, sizeof(next)); }
	~Trie() { for (auto& i : next) delete i; }

	bool finish;
	Trie* next[10];
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		Trie* trie = new Trie();
		vector<string> list;
		int n;
		bool flag = true;
		cin >> n;

		while (n--) {
			string num;
			cin >> num;
			list.push_back(num);

			Trie* curNode = trie;

			string::iterator foo = num.end() - 1;

			for (auto i = num.begin(); i != num.end(); i++) {
				int curChar = *i - '0';
				if (curNode->next[curChar] == nullptr) {
					curNode->next[curChar] = new Trie();
				}
				curNode = curNode->next[curChar];

				if (i == foo) {
					curNode->finish = true;
				}
			}
		}

		for (auto& i : list) {
			Trie* curNode = trie;
			while (!i.empty() && flag) {
				int curChar = *i.begin() - '0';
				i.erase(i.begin());
				if (curNode->finish) {
					cout << "NO\n";
					flag = !flag;
					break;
				}
				curNode = curNode->next[curChar];
			}
		}

		if (flag) cout << "YES\n";

		delete trie;
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
