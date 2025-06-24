// noj.am.28707.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

struct Control {
	int from;
	int to;
	int cost;
};

vector<int> target;
vector<Control> foo;

struct VectorHash {
	size_t operator()(const vector<int>& v) const {
		size_t hash = 0;
		for (int i : v) {
			hash ^= std::hash<int>{}(i)+0x9e3779b9 + (hash << 6) + (hash >> 2);
		}
		return hash;
	}
};

void dijkstra(vector<int> start) {
	unordered_map<vector<int>, int, VectorHash> dist;
	priority_queue<pair<int, vector<int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		int curCost = -(pq.top().first);
		vector<int> curArr = pq.top().second;
		pq.pop();

		if (curCost > dist[curArr]) continue;

		for (auto& i : foo) {
			swap(curArr[i.from], curArr[i.to]);
			if (dist.find(curArr) == dist.end() || curCost + i.cost < dist[curArr]) {
				dist[curArr] = curCost + i.cost;
				pq.push({ -(curCost + i.cost), curArr });
			}
			swap(curArr[i.from], curArr[i.to]);
		}
	}

	if (dist.find(target) == dist.end()) cout << -1;
	else cout << dist[target];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	target = arr;
	sort(target.begin(), target.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		foo.push_back({ a - 1, b - 1, cost });
	}

	dijkstra(arr);
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
