// noj.am.1766.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> ans;
	vector<int> cnt(n + 1, 0);
	vector<vector<int>> graph(n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cnt[b]++;
		graph[a].push_back(b);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		ans.push_back(cur);

		for (auto& nxt : graph[cur]) {
			cnt[nxt]--;
			if (cnt[nxt] == 0) pq.push(nxt);
		}
	}

	for (auto& i : ans) cout << i << " ";
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
