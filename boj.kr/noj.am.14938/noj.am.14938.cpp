// noj.am.14938.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define INF 222'222

int main()
{
	int n, m, r;
	int a, b, l;
	int ans = 0;
	cin >> n >> m >> r;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));
	vector<int> item(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
		map[i][i] = 0;
	}

	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		map[a][b] = l;
		map[b][a] = l;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (map[start][end] > map[start][mid] + map[mid][end])
					map[start][end] = map[start][mid] + map[mid][end];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] <= m) sum += item[j];
		}
		if (sum > ans) ans = sum;
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
