// noj.am.14725.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
#include <set>

using namespace std;

class Trie {
public:
	Trie(string name, int layer) : name(name), layer(layer) {}
	struct compare {
		bool operator()(const Trie* a, const Trie* b) const {
			return a->name > b->name;
		}
	};
	string name;
	int layer;
	set<Trie*, compare> next;
};

int main()
{
	int n;
	cin >> n;
	Trie* cave = new Trie("", 0);

	while (n--) {
		int foo;
		Trie* cur = cave;
		cin >> foo;
		while (foo--) {
			string bar;
			bool flag = false;
			cin >> bar;
			for (auto& i : cur->next) {
				if (i->name == bar) {
					flag = true;
					cur = i;
					break;
				}
			}
			if (!flag) {
				cur = *cur->next.insert(new Trie(bar, cur->layer + 1)).first;
			}
		}
	}

	stack<Trie*> st;
	st.push(cave);

	while (!st.empty()) {
		Trie* cur = st.top();
		st.pop();
		if (cur->layer > 0) {
			for (int i = 1; i < cur->layer; i++) cout << "--";
			cout << cur->name << "\n";
		}

		for (auto& i : cur->next) {
			st.push(i);
		}
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
