// noj.am.7453.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	long long ans = 0;
	cin >> n;
	vector<long long> a(n), b(n), c(n), d(n);
	
	unordered_map<long long, long long> m;
	m.reserve(n * n);

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (auto& i : a) {
		for (auto& j : b) {
			m[i + j]++;
		}
	}

	for (auto& i : c) {
		for (auto& j : d) {
			auto cur = m.find(-(i + j));
			if (cur != m.end())
				ans += cur->second;
		}
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
