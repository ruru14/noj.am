// noj.am.1339.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	map<char, int> m;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		string foo;
		cin >> foo;
		int s = foo.size();
		for (int j = 0; j < foo.size(); j++) {
			m[foo[j]] += pow(10, s - j - 1);
		}
	}

	for (auto& i : m) {
		pq.push(i.second);
	}

	int foo = 9;
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		ans += cur * foo--;
	}
	
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
