// noj.am.16934.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Trie {
public:
	Trie(int layer) : finish(0), layer(layer) { memset(next, 0, sizeof(next)); }
	~Trie() { for (auto& i : next) delete i; }

	int finish;
	int layer;
	Trie* next[27];
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	Trie* t = new Trie(0);

	while (n--) {
		string foo;
		cin >> foo;
		Trie* cur = t;
		bool flag = true;

		string::iterator bar = foo.end() - 1;

		for (auto i = foo.begin(); i != foo.end(); i++) {
			char curChar = *i;
			int curIdx = curChar - 'a';

			if (!cur->next[curIdx]) {
				cur->next[curIdx] = new Trie(cur->layer + 1);
				if (flag) {
					cout << curChar;
					flag = false;
				}
			} else {
				cout << curChar;
				flag = true;
			}
			cur = cur->next[curIdx];

			if (i == bar) {
				cur->finish++;
				if (cur->finish > 1) cout << cur->finish;
			}
		}

		cout << "\n";
	}

	delete t;
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
