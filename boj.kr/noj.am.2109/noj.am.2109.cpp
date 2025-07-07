// noj.am.2109.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> arr;

	while (n--) {
		pair<int, int> foo;
		cin >> foo.second >> foo.first;
		arr.push_back(foo);
	}

	sort(arr.begin(), arr.end());

	for (auto& i : arr) {
		if (pq.size() < i.first) pq.push(i.second);
		else if (!pq.empty() && pq.top() < i.second) {
			pq.pop();
			pq.push(i.second);
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
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
