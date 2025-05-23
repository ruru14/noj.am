// noj.am.4195.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Friend {
private:
	unordered_map<string, int> book;
public:
	const int operator[](const string& name) {
		if (book.find(name) == book.end()) {
			book[name] = (int)book.size();
		}
		return book[name];
	}
};

class DisjointSet {
private:
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
public:
	int Find(int n) {
		if (parent.find(n) == parent.end()) {
			parent[n] = n;
			rank[n] = 1;
		}

		if (parent[n] != n) parent[n] = Find(parent[n]);
		return parent[n];
	}

	int Union(int a, int b) {
		int rootA = Find(a);
		int rootB = Find(b);

		if (rootA == rootB) return rank[rootA];

		parent[rootA] = rootB;
		int sum = rank[rootA] + rank[rootB];
		rank[rootA] = sum;
		rank[rootB] = sum;

		return sum;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;

	while (tc--) {
		int f;
		cin >> f;
		Friend list;
		DisjointSet s;
		for (int i = 0; i < f; i++) {
			string foo, bar;
			cin >> foo >> bar;
			cout << s.Union(list[foo], list[bar]) << "\n";
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
