// noj.am.1967.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int n;

pair<int, int> dfs(vector<vector<pair<int, int>>> graph, int start) {
	vector<bool> visit(n + 1, false);
	stack<pair<int, int>> st;
	st.push(make_pair(start, 0));
	visit[start] = true;
	pair<int, int> max = make_pair(start, 0);

	while (!st.empty()) {
		auto cur = st.top();
		if (max.second < cur.second) max = cur;
		st.pop();

		for (auto& i : graph[cur.first]) {
			if (!visit[i.first]) {
				visit[i.first] = true;
				st.push(make_pair(i.first, cur.second + i.second));
			}
		}
	}

	return max;
}

int main()
{
	int a, b, c;
	cin >> n;
	vector<vector<pair<int, int>>> tree(n + 1);

	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	auto st = dfs(tree, 1);
	auto answer = dfs(tree, st.first);

	cout << answer.second;
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
