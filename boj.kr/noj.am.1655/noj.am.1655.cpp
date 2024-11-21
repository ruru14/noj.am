// noj.am1655.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, less<int>> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int n, v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v;
		if (maxheap.size() == minheap.size()) {
			maxheap.push(v);
		} else {
			minheap.push(v);
		}

		if (!maxheap.empty() && !minheap.empty()) {
			if (maxheap.top() > minheap.top()) {
				int foo = maxheap.top();
				maxheap.pop();
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(foo);
			}
		}
		cout << maxheap.top() << "\n";
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
